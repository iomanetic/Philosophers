/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:10:33 by tyuuki            #+#    #+#             */
/*   Updated: 2022/03/10 18:33:39 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_malloc(t_data *info)
{
	info->philo = (t_philo *) \
		malloc(sizeof(t_philo) * info->numb_of_philo);
	if (!info->philo)
		return (FALSE);
	info->forks = (pthread_mutex_t *) \
		malloc(sizeof(pthread_mutex_t) * info->numb_of_philo);
	if (!info->forks)
		return (FALSE);
	info->thread = (pthread_t *) \
		malloc(sizeof(pthread_t) * info->numb_of_philo);
	if (!info->thread)
		return (FALSE);
	return (TRUE);
}

int	philo_mutex_init(t_data *info)
{
	size_t	i;

	i = 0;
	while ((long)i < info->numb_of_philo)
	{
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
			return (FALSE);
		i++;
	}
	if (pthread_mutex_init(&info->out_mutex, NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&info->inc_mutex, NULL) != 0)
		return (FALSE);
	return (TRUE);
}

void	philo_write_data(t_data *info)
{
	size_t	i;

	i = 0;
	while ((long)i < info->numb_of_philo)
	{
		info->philo[i].id = i + 1;
		info->philo[i].live = 1;
		info->philo[i].data = info;
		info->philo[i].right_fork = &info->forks[i];
		info->philo[i].left_fork = \
			&info->forks[(i + 1) % info->numb_of_philo];
		info->philo[i].last_eat = philo_time();
		info->philo[i].start_time = philo_time();
		i++;
	}
}

int	philo_init(t_data *info, char **ag)
{
	info->numb_of_philo = ft_atoi(ag[0]);
	info->time_to_die = ft_atoi(ag[1]);
	info->time_to_eat = ft_atoi(ag[2]);
	info->time_to_sleep = ft_atoi(ag[3]);
	if (ag[4])
	{
		info->numb_of_eat = ft_atoi(ag[4]);
		info->must_eat = info->numb_of_eat * info->numb_of_philo;
		info->eat_status = 1;
	}
	else
	{
		info->numb_of_eat = -1;
		info->eat_status = -1;
		info->must_eat = -1;
	}
	if (!philo_malloc(info))
		return (philo_errors(E_EMA));
	if (!philo_mutex_init(info))
		return (philo_errors(E_EMI));
	philo_write_data(info);
	return (TRUE);
}
