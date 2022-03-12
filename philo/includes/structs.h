/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:10:27 by tyuuki            #+#    #+#             */
/*   Updated: 2022/03/10 18:33:31 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_data
{
	long			numb_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			numb_of_eat;
	long			must_eat;
	struct s_philo	*philo;
	pthread_t		*thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	out_mutex;
	pthread_mutex_t	inc_mutex;
}					t_data;

typedef struct s_philo
{
	size_t			last_eat;
	size_t			live;
	size_t			id;
	long			start_time;
	t_data			*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philo;

#endif