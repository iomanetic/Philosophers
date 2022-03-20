#include "includes/philo_bonus.h"

int main(int argc, char **argv)
{
	t_data	info;

	(void)argc;
	if(!philo_validation(&argv[1]))
		return (FALSE);
	if(!philo_init(&info, &argv[1]))
		return (FALSE);
	if(!philo_start(&info))
		return (FALSE);
	return (TRUE);
}