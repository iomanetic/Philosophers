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

int	philo_live(t_philo *philo)
{
	if(!philo->live)
		return (FALSE);
	return (TRUE);
}

void	philos_live(t_data *info)
{
	size_t	i;
	long	time;

	i = 0;
	while(1)
	{
		i = 0;
		while((long)i < info->numb_of_philo)
		{
			time = philo_time() - info->philo[i].last_eat;
			if(time > info->time_to_die)
			{
				pthread_mutex_lock(&info->out_mutex);
				printf("%ld %ld %s", philo_time() - info->philo[i].start_time, \
					info->philo[i].id, DIE);
				return ;
			}
			i++;
		}
	}
}

void	*philo_action(void *philo_i)
{
	t_philo	*philo;

	philo = (t_philo *)philo_i;
	while(philo_live(philo))
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
		if(pthread_create(&info->thread[i], NULL, 
			philo_action, &info->philo[i]) != 0)
			return (FALSE);
		i++;
		usleep(100);
	}
	philos_live(info);
	return (TRUE);
}