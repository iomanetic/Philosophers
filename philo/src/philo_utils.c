/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:43:16 by tyuuki            #+#    #+#             */
/*   Updated: 2022/03/10 19:02:51 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	long int	output;

	output = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-3);
		if (output * 1 > 2147483647)
			return (-1);
		if (output * -1 < -2147483648)
			return (-2);
		output = (output * 10) + (*str - 48);
		++str;
	}
	return (output);
}

long philo_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	philo_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->data->out_mutex);
	printf("%ld %zu %s", philo_time() - philo->start_time,
			philo->id, message);
	pthread_mutex_unlock(&philo->data->out_mutex);
}

int	check_lives(t_data *info)
{
	size_t	i;

	i = 0;
	while ((long)i < info->numb_of_philo)
	{
		pthread_mutex_lock(&info->inc_mutex);
		if (!info->philo[i].live)
			return (FALSE);
		else if (info->eat_status != -1 \
				&& !info->must_eat)
		{
			info->eat_status = 0;
			return (FALSE);
		}
		i++;
		pthread_mutex_unlock(&info->inc_mutex);
	}
	return (TRUE);
}

void	philo_cleaner(t_data *info)
{
	size_t	i;

	i = 0;
	while ((long)i < info->numb_of_philo)
	{
		pthread_detach(info->thread[i]);
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&info->inc_mutex);
	pthread_mutex_destroy(&info->out_mutex);
	free(info->philo);
	free(info->thread);
	free(info->forks);
}