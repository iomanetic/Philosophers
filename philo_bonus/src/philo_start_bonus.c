/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymac <mymac@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:17:42 by mymac             #+#    #+#             */
/*   Updated: 2022/03/22 13:23:24 by mymac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	*philo_live(void *tmp)
{
	long	time;
	t_philo	*philo;

	philo = (t_philo *)tmp;
	while (philo->data->must_eat)
	{
		sem_wait(philo->data->sem_inc);
		time = philo_time() - philo->last_eat;
		if (time > philo->data->time_to_die)
		{
			sem_wait(philo->data->sem_out);
			printf("%ld %zu %s", philo_time() - philo->start_time, \
				philo->id + 1, DIE);
			sem_post(philo->data->sem_exit);
			philo->live = 0;
			return ((void *)0);
		}
		sem_post(philo->data->sem_inc);
	}
	if ((long)philo->id + 1 == philo->data->numb_of_philo)
		sem_post(philo->data->sem_exit);
	return ((void *)0);
}

void	philo_action(t_philo *philo)
{
	while (philo->live)
	{
		philo_take_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
	}
	exit(0);
}

int	philo_start(t_data *info)
{
	long	i;

	i = 0;
	while (i < info->numb_of_philo)
	{
		info->philo[i].pid = fork();
		if (info->philo[i].pid == 0)
		{
			if (pthread_create(&info->thread[i], NULL, \
				philo_live, &info->philo[i]) != 0)
				return (philo_errors(E_ETC));
			philo_action(&info->philo[i]);
		}
		i++;
		usleep(500);
	}
	philo_clean(info);
	return (TRUE);
}
