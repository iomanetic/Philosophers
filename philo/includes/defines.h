/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:10:23 by tyuuki            #+#    #+#             */
/*   Updated: 2022/03/02 18:20:00 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# ifndef PHILO_REPLICS
#  define PHILO_REPLICS

#  define TAKE_F "has taken a fork\n"
#  define EAT "is eating\n"
#  define SLEEP "is sleeping\n"
#  define THINK "is thinking\n"
#  define DIE "died\n"
# endif

# ifndef PHILO_ERROS
#  define PHILO_ERROS

#  define NOP "numbers of params < 5 or > 6\n"
#  define NVS "params of programm should be only integer and > 1\n"
#  define EMI "error mutex init\n"
#  define EMA "error memory allocated\n"
#  define ETC "error thread create"
# endif

# ifndef COLORS
#  define COLORS

#  define YELLOW "\033[0;33m"
#  define WHITE "\033[0;37m"
# endif

# ifndef VALUES
#  define VALUES

#  define TRUE 1
#  define FALSE 0
#  define E_NOP 2
#  define E_NVS 3
#  define E_EMI 4
#  define E_EMA 5
#  define E_ETC 6
# endif

#endif