/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymac <mymac@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:18:05 by mymac             #+#    #+#             */
/*   Updated: 2022/03/22 13:18:06 by mymac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <signal.h>
# include "defines_bonus.h"
# include "structs_bonus.h"

# ifndef MAIN_FUNC
#  define MAIN_FUNC

int		philo_errors(int flag);
int		philo_validation(char **ag);
int		philo_init(t_data *info, char **ag);
int		philo_start(t_data *info);
# endif

# ifndef PHILO_ACTIONS
#  define PHILO_ACTIONS

void	philo_take_fork(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
# endif

# ifndef PHILO_UTILS
#  define PHILO_UTILS

int		ft_atoi(const char *str);
long	philo_time(void);
void	philo_message(t_philo *philo, char *message);
void	philo_clean(t_data *info);
# endif

#endif