/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:10:36 by tyuuki            #+#    #+#             */
/*   Updated: 2022/03/10 18:53:48 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philos_live(t_data *info)
{
	size_t	i;
	long	time;

	while (info->eat_status)
	{
		i = 0;
		while ((long)i < info->numb_of_philo \
			&& check_lives(info))
		{
			pthread_mutex_lock(&info->inc_mutex);
			time = philo_time() - info->philo[i].last_eat;
			if (time > info->time_to_die)
			{
				philo_message(&info->philo[i], DIE);
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
	size_t	i;

	i = 0;
	while ((long)i < info->numb_of_philo)
	{
		if (pthread_create(&info->thread[i], NULL,
				philo_action, &info->philo[i]) != 0)
			return (FALSE);
		i++;
		usleep(1350);
	}
	philos_live(info);
	return (TRUE);
}
