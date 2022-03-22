/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymac <mymac@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:17:54 by mymac             #+#    #+#             */
/*   Updated: 2022/03/22 13:22:13 by mymac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	philo_take_fork(t_philo *philo)
{
	sem_wait(philo->data->sem_forks);
	philo_message(philo, TAKE_F);
	sem_wait(philo->data->sem_forks);
	philo_message(philo, TAKE_F);
}

void	philo_eat(t_philo *philo)
{
	long	time;

	philo_message(philo, EAT);
	sem_wait(philo->data->sem_inc);
	if (philo->data->eat_status)
		philo->data->must_eat--;
	philo->last_eat = philo_time();
	sem_post(philo->data->sem_inc);
	time = philo_time();
	while (philo_time() - time < philo->data->time_to_eat)
		usleep(500);
	sem_post(philo->data->sem_forks);
	sem_post(philo->data->sem_forks);
}

void	philo_sleep(t_philo *philo)
{
	long	time;

	philo_message(philo, SLEEP);
	time = philo_time();
	while (philo_time() - time < philo->data->time_to_sleep)
		usleep(500);
	philo_message(philo, THINK);
}
