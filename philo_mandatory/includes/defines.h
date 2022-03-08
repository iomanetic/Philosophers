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

#  define EAT "EATING\n"
#  define SLEEP "SLEEPING\n"
#  define THINK "THINKING\n"
#  define TOOK_RF "TOOK A RIGHT FORK\n"
#  define TOOK_LF "TOOK A LEFT FORK\n"
#  define PUTD_RF "PUT DOWN A RIGHT FORK\n"
#  define PUTD_LF "PUT DOWN A LEFT FORK\n"
#  define DIE "IS DIE\n"
# endif

# ifndef PHILO_ERROS
#  define PHILO_ERROS

#  define NOP "numbers of params < 5 or > 6\n"
#  define NVS "params of programm should be only integer and < 1\n"
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
# endif

#endif