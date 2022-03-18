#ifndef DEFINES_BONUS_H
# define DEFINES_BONUS_H

# ifndef PHILO_ERROS
#  define PHILO_ERROS

#  define NOP "numbers of params < 5 or > 6\n"
#  define NVS "params of programm should be only integer and > 1\n"
#  define EMI "error mutex init\n"
#  define EMA "error memory allocated\n"
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
# endif

#endif