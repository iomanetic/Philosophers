/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:10:36 by tyuuki            #+#    #+#             */
/*   Updated: 2022/03/09 14:59:27 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_status(t_about_philo *philo)
{
	if (philo->live_status == -1)
		return (FALSE);
	return (TRUE);
}

void	check_die(t_about_philo *philo, t_philo *philo_data)
{
	int 				i;
	long				time;

	while (1)
	{
		i = 0;
		while (i < philo->data->numb_of_philo
			&& philo_status(&philo[i]))
		{
			time = philo_time() - philo[i].last_eat;
			if (time > philo->data->time_to_die)
			{
				philo_message(philo, DIE);
				philo[i].live_status = -1;
				philo_cleaner(philo_data, philo);
				return ;
			}
			i++;
		}
	}
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