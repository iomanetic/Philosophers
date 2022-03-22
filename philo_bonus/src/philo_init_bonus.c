/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymac <mymac@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:17:45 by mymac             #+#    #+#             */
/*   Updated: 2022/03/22 13:23:47 by mymac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	philo_sem(t_data *info)
{
	sem_unlink(FORK);
	sem_unlink(OUT);
	sem_unlink(EXIT);
	sem_unlink(INC);
	info->sem_forks = \
		sem_open(FORK, O_CREAT | O_EXCL, 777, info->numb_of_philo);
	if (info->sem_forks <= 0)
		return (FALSE);
	info->sem_out = \
		sem_open(OUT, O_CREAT | O_EXCL, 777, 1);
	if (info->sem_out <= 0)
		return (FALSE);
	info->sem_exit = \
		sem_open(EXIT, O_CREAT | O_EXCL, 777, 0);
	if (info->sem_exit <= 0)
		return (FALSE);
	info->sem_inc = \
		sem_open(INC, O_CREAT | O_EXCL, 777, 1);
	if (info->sem_inc <= 0)
		return (FALSE);
	return (TRUE);
}

int	philo_malloc(t_data *info)
{
	info->philo = \
		(t_philo *) malloc(sizeof(t_philo) * info->numb_of_philo);
	if (!info->philo)
		return (philo_errors(E_EMA));
	info->thread = \
		(pthread_t *) malloc(sizeof(pthread_t) * info->numb_of_philo);
	if (!info->thread)
		return (philo_errors(E_EMA));
	if (!philo_sem(info))
		return (philo_errors(E_ESI));
	return (TRUE);
}

void	philo_write_data(t_data *info)
{
	long	i;

	i = 0;
	while (i < info->numb_of_philo)
	{
		info->philo[i].id = i;
		info->philo[i].live = 1;
		info->philo[i].data = info;
		info->philo[i].start_time = philo_time();
		info->philo[i].last_eat = philo_time();
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
		info->must_eat = info->numb_of_eat;
		info->eat_status = 1;
	}
	else
	{
		info->numb_of_eat = -1;
		info->must_eat = -1;
		info->eat_status = 0;
	}
	if (!philo_malloc(info))
		return (FALSE);
	philo_write_data(info);
	return (TRUE);
}
