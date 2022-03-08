/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:10:27 by tyuuki            #+#    #+#             */
/*   Updated: 2022/03/02 20:10:09 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_philo
{
	int				numb_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				numb_of_eat;
	pthread_t		*thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	output_protect;
}					t_philo;

typedef struct s_about_philo
{
	long			last_eat;
	int				must_eat;
	int				live_status;
	int				philo_id;
	long			start_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_philo			*data;
}					t_about_philo;