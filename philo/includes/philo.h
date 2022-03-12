/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:07:03 by tyuuki            #+#    #+#             */
/*   Updated: 2022/03/10 18:27:22 by tyuuki           ###   ########.fr       */
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
int		philo_init(t_data *philo, char **ag);
int		philo_start(t_data *philo);
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
# endif

#endif