#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <limits.h>
# include "defines_bonus.h"
# include "structs_bonus.h"

# ifndef MAIN_FUNC
#  define MAIN_FUNC

int		philo_errors(int flag);
int		philo_validation(char **ag);
int		philo_init(t_data *info, char **ag);
int		philo_start(t_data *info);
# endif

# ifndef PHILO_UTILS
#  define PHILO_UTILS

int		ft_atoi(const char *str);
long	philo_time(void);
# endif

#endif