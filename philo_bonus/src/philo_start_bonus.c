#include "../includes/philo_bonus.h"

//in work
void	*philo_live(void *philo);

void	*philo_action(t_philo *philo);

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
}