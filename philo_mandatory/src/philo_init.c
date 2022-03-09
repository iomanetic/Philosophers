/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:10:33 by tyuuki            #+#    #+#             */
/*   Updated: 2022/03/09 12:59:58 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_malloc(t_philo **philo, t_about_philo **philos)
{
	(*philos) = (t_about_philo *) \
		malloc(sizeof(t_about_philo) * (*philo)->numb_of_philo);
	(*philo)->forks = (pthread_mutex_t *) \
		malloc(sizeof(pthread_mutex_t) * (*philo)->numb_of_philo);
	(*philo)->thread = (pthread_t *) \
		malloc(sizeof(pthread_t) * (*philo)->numb_of_philo);
}

void	philo_mutex_init(t_philo **philo)
{
	int	i;

	i = 0;
	while (i < (*philo)->numb_of_philo)
	{
		pthread_mutex_init(&(*philo)->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&(*philo)->output_protect, NULL);
}

void	philo_info_init(t_philo **philo, t_about_philo **philos)
{
	int	i;

	i = 0;
	while (i < (*philo)->numb_of_philo)
	{
		(*philos)[i].last_eat = philo_time();
		(*philos)[i].live_status = 1;
		(*philos)[i].philo_id = i;
		(*philos)[i].must_eat = (*philo)->numb_of_eat;
		(*philos)[i].left_fork = \
			&(*philo)->forks[(i + 1) % (*philo)->numb_of_philo];
		(*philos)[i].right_fork = &(*philo)->forks[i];
		(*philos)[i].data = *philo;
		(*philos)[i].start_time = philo_time();
		i++;
	}
}

void	philo_init(t_philo **philo, t_about_philo **philos, char **ag)
{
	*philo = (t_philo *) malloc(sizeof(t_philo));
	(*philo)->numb_of_philo = ft_atoi(ag[0]);
	(*philo)->time_to_die = ft_atoi(ag[1]);
	(*philo)->time_to_eat = ft_atoi(ag[2]);
	(*philo)->time_to_sleep = ft_atoi(ag[3]);
	if (ag[4])
	{
		(*philo)->numb_of_eat = ft_atoi(ag[4]);
		(*philo)->must_eat_status = (*philo)->numb_of_eat * (*philo)->numb_of_philo;
	}
	else
		(*philo)->numb_of_eat = -1;
	philo_malloc(philo, philos);
	philo_mutex_init(philo);
	philo_info_init(philo, philos);
}