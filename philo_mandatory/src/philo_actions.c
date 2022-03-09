/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:10:31 by tyuuki            #+#    #+#             */
/*   Updated: 2022/03/09 14:59:37 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_take_fork(t_about_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		philo_message(philo, TOOK_LF);
		pthread_mutex_lock(philo->right_fork);
		philo_message(philo, TOOK_RF);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		philo_message(philo, TOOK_RF);
		pthread_mutex_lock(philo->left_fork);
		philo_message(philo, TOOK_LF);
	}
}

void	philo_putdown_fork(t_about_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		philo_message(philo, PUTD_RF);
		pthread_mutex_unlock(philo->left_fork);
		philo_message(philo, PUTD_LF);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		philo_message(philo, PUTD_LF);
		pthread_mutex_unlock(philo->right_fork);
		philo_message(philo, PUTD_RF);
	}
}

void	philo_eat(t_about_philo *philo)
{
	long time;

	time = philo_time();
	philo_message(philo, EAT);
	philo->last_eat = philo_time();
	while(philo_time() - time < philo->data->time_to_eat)
		usleep(50);
	philo_putdown_fork(philo);
}

void	philo_sleep(t_about_philo *philo)
{
	long	time;

	philo_message(philo, THINK);
	philo_message(philo, SLEEP);
	time = philo_time();
	while(philo_time() - time < philo->data->time_to_eat)
		usleep(50);
}