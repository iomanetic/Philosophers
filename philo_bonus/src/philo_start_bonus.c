#include "../includes/philo_bonus.h"

void	*philo_live(void *tmp)
{
	long	time;
	t_philo	*philo;

	philo = (t_philo *)tmp;
	while (1)
	{
		sem_wait(philo->data->sem_inc);
		time = philo_time() - philo->last_eat;
		if(time > philo->data->time_to_die)
		{
			sem_wait(philo->data->sem_out);
			printf("%ld %zu %s", philo_time() - philo->start_time, philo->id + 1, DIE);
			sem_post(philo->data->sem_exit);
			philo->live = 0;
			return ((void *)0);
		}
		sem_post(philo->data->sem_inc);
	}
	return ((void *)0);
}

void	philo_action(t_philo *philo)
{
	while(philo->live)
	{
		philo_take_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
	}
	exit(0);
}

int	philo_start(t_data *info)
{
	size_t	i;

	i = 0;

	while((long) i < info->numb_of_philo)
	{
		info->philo[i].pid = fork();
		if(info->philo[i].pid == 0)
		{
			if(pthread_create(&info->thread[i], NULL, \
				philo_live, &info->philo[i]) != 0)
				return (philo_errors(E_ETC));
			philo_action(&info->philo[i]);
		}
		i++;
	}
	philo_clean(info);
	return (TRUE);
}