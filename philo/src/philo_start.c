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

int	philo_status(t_about_philo *philo)
{
	if (!philo->live_status)
		return (FALSE);
	return (TRUE);
}

void	check_die(t_about_philo *philo, t_philo *philo_data)
{
	int 	i;
	long	time;

	while (philo_data->must_eat_status)
	{
		i = 0;
		while (i < philo->data->numb_of_philo
			&& philo_data->must_eat_status)
		{
			time = philo_time() - philo[i].last_eat;
			if (time > philo->data->time_to_die)
			{
				printf("%ld %zu %s", philo_time() - philo->start_time, philo->philo_id, DIE);
				philo[i].live_status = 0;
				philo_cleaner(philo_data, philo);
				return ;
			}
			i++;
		}
	}
	philo_cleaner(philo_data, philo);
}

void	*philo_actions(void *philos)
{
	t_about_philo	*philo;
	
	philo = (t_about_philo *)philos;
	while (philo_status(philo))
	{
		philo_take_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (NULL);
}

void	philo_start(t_philo *philo, t_about_philo *philos)
{
	int	i;

	i = 0;
	while (i < philo->numb_of_philo)
	{
		pthread_create(&philo->thread[i], NULL, philo_actions, &philos[i]);
		i++;
		usleep(50);
	}
	check_die(philos, philo);
}