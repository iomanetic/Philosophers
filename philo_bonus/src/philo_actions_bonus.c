#include "../includes/philo_bonus.h"

void	philo_take_fork(t_philo *philo)
{
	sem_wait(philo->data->sem_forks);
	philo_message(philo, TAKE_F);
	sem_wait(philo->data->sem_forks);
	philo_message(philo, TAKE_F);
}

void	philo_eat(t_philo *philo)
{
	long	time;

	philo_message(philo, EAT);
	time = philo_time();
	sem_wait(philo->data->sem_inc);
	philo->last_eat = philo_time();
	sem_post(philo->data->sem_inc);
	while (philo_time() - time < philo->data->time_to_eat)
		usleep(500);
	sem_post(philo->data->sem_forks);
	sem_post(philo->data->sem_forks);
}

void	philo_sleep(t_philo *philo)
{
	long	time;

	philo_message(philo, SLEEP);
	time = philo_time();
	while(philo_time() - time < philo->data->time_to_sleep)
		usleep(500);
	philo_message(philo, THINK);
}