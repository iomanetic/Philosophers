#include "../includes/philo_bonus.h"

int	philo_errors(int flag)
{
	if (flag == E_NOP)
	{
		printf("%s", YELLOW NOP WHITE);
		return (FALSE);
	}
	else if (flag == E_NVS)
	{
		printf("%s", YELLOW NVS WHITE);
		return (FALSE);
	}
	else if (flag == E_EMI)
	{
		printf("%s", YELLOW EMI WHITE);
		return (FALSE);
	}
	else if (flag == E_EMA)
	{
		printf("%s", YELLOW EMA WHITE);
		return (FALSE);
	}
	return (TRUE);
}