/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymac <mymac@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:10:36 by tyuuki            #+#    #+#             */
/*   Updated: 2022/03/22 13:25:01 by mymac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philos_live(t_data *info)
{
	long	i;
	long	time;

	while (info->eat_status)
	{
		i = 0;
		while (i < info->numb_of_philo \
			&& check_lives(info))
		{
			pthread_mutex_lock(&info->inc_mutex);
			time = philo_time() - info->philo[i].last_eat;
			if (time > info->time_to_die)
			{
				pthread_mutex_lock(&info->out_mutex);
				printf("%ld %zu %s", philo_time() - info->philo[i].start_time,
					info->philo[i].id + 1, DIE);
				info->philo[i].live = 0;
				philo_cleaner(info);
				return ;
			}
			i++;
			pthread_mutex_unlock(&info->inc_mutex);
		}
	}
	philo_cleaner(info);
}

void	*philo_action(void *philo_i)
{
	t_philo	*philo;

	philo = (t_philo *)philo_i;
	while (1)
	{
		philo_take_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (NULL);
}

int	philo_start(t_data *info)
{
	long	i;

	i = 0;
	while (i < info->numb_of_philo)
	{
		if (pthread_create(&info->thread[i], NULL,
				philo_action, &info->philo[i]) != 0)
			return (philo_errors(E_ETC));
		i++;
		usleep(500);
	}
	philos_live(info);
	return (TRUE);
}
