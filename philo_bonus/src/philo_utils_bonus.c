#include "../includes/philo_bonus.h"

int	ft_atoi(const char *str)
{
	long int	output;

	output = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-3);
		if (output * 1 > 2147483647)
			return (-1);
		if (output * -1 < -2147483648)
			return (-2);
		output = (output * 10) + (*str - 48);
		++str;
	}
	return (output);
}