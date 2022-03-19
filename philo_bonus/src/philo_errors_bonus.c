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
	else if (flag == E_ESI)
	{
		printf("%s", YELLOW ESI WHITE);
		return (FALSE);
	}
	else if (flag == E_EMA)
	{
		printf("%s", YELLOW EMA WHITE);
		return (FALSE);
	}
	else if (flag == E_ETC)
	{
		printf("%s", YELLOW ETC WHITE);
		return (FALSE);
	}
	return (TRUE);
}