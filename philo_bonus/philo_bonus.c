/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymac <mymac@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:17:26 by mymac             #+#    #+#             */
/*   Updated: 2022/03/22 13:18:48 by mymac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	info;

	(void)argc;
	if (!philo_validation(&argv[1]))
		return (FALSE);
	if (!philo_init(&info, &argv[1]))
		return (FALSE);
	if (!philo_start(&info))
		return (FALSE);
	return (TRUE);
}
