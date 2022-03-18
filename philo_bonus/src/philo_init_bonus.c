#include "../includes/philo_bonus.h"

int	philo_init(t_data *info, char **ag)
{
	info->numb_of_philo = ft_atoi(ag[0]);
	info->time_to_die = ft_atoi(ag[1]);
	info->time_to_eat = ft_atoi(ag[2]);
	info->time_to_sleep = ft_atoi(ag[3]);
	if(ag[4])
		info->numb_of_eat = ft_atoi(ag[4]);
	return (TRUE);
}