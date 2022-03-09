/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:07:03 by tyuuki            #+#    #+#             */
/*   Updated: 2022/03/09 14:59:45 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include "defines.h"
# include "structs.h"

# ifndef MAIN_FUNC
#  define MAIN_FUNC

int		philo_errors(int flag);
int		philo_validation(char **ag);
void	philo_init(t_philo **philo, t_about_philo **philos, char **ag);
void	philo_start(t_philo *philo, t_about_philo *philos);
# endif

# ifndef PHILO_ACTIONS
#  define PHILO_ACTIONS

void	philo_take_fork(t_about_philo *philo);
void	philo_eat(t_about_philo *philo);
void	philo_sleep(t_about_philo *philo);
# endif

# ifndef PHILO_UTILS
#  define PHILO_UTILS

int		ft_atoi(const char *str);
long	philo_time(void);
void	philo_message(t_about_philo *philo, char *message);
void	philo_cleaner(t_philo *philo_d, t_about_philo *philos);
# endif

#endif