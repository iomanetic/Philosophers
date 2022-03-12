/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:06:06 by tyuuki            #+#    #+#             */
/*   Updated: 2022/03/09 13:01:52 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	info;

	(void)argc;
	if (!philo_validation(&argv[1]))
		return (FALSE);
	if(!philo_init(&info, &argv[1]))
		return (FALSE);
	if(!philo_start(&info))
		return (FALSE);
	return (TRUE);
}
