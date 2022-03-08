/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:43:16 by tyuuki            #+#    #+#             */
/*   Updated: 2022/03/02 19:29:44 by tyuuki           ###   ########.fr       */
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
			return (0);
		if (output * 1 > 2147483647)
			return (-1);
		if (output * -1 < -2147483648)
			return (0);
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

void	philo_message(t_about_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->data->output_protect);
	printf("%ld %d %s", philo_time() - philo->start_time, philo->philo_id, message);
	pthread_mutex_unlock(&philo->data->output_protect);
}