/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymac <mymac@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:17:37 by mymac             #+#    #+#             */
/*   Updated: 2022/03/22 13:27:36 by mymac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

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
		if (output * 1 > INT_MAX)
			return (-1);
		if (output * -1 < INT_MIN)
			return (-2);
		output = (output * 10) + (*str - 48);
		++str;
	}
	return (output);
}

long	philo_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	philo_message(t_philo *philo, char *message)
{
	sem_wait(philo->data->sem_out);
	printf("%ld %zu %s", philo_time() - philo->start_time, \
		philo->id + 1, message);
	sem_post(philo->data->sem_out);
}

void	philo_clean(t_data *info)
{
	long	i;

	i = 0;
	sem_wait(info->sem_exit);
	while (i < info->numb_of_philo)
	{
		pthread_detach(info->thread[i]);
		kill(info->philo[i].pid, SIGTERM);
		i++;
	}
	sem_close(info->sem_exit);
	sem_close(info->sem_out);
	sem_close(info->sem_forks);
	sem_close(info->sem_inc);
	sem_unlink(EXIT);
	sem_unlink(OUT);
	sem_unlink(FORK);
	sem_unlink(INC);
	free(info->philo);
	free(info->thread);
}
