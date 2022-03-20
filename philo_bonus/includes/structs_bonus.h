#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

typedef struct s_data
{
	long			numb_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			numb_of_eat;
	long			must_eat;
	pthread_t		*thread;
	size_t			eat_status;
	sem_t			*sem_forks;
	sem_t			*sem_exit;
	sem_t			*sem_out;
	sem_t			*sem_inc;
	struct s_philo	*philo;
}					t_data;

typedef struct s_philo
{
	size_t			live;
	size_t			id;
	long			start_time;
	long			last_eat;
	pid_t			pid;
	t_data			*data;
}					t_philo;

#endif