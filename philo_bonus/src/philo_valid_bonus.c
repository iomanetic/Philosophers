/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_valid_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymac <mymac@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:17:30 by mymac             #+#    #+#             */
/*   Updated: 2022/03/22 13:19:04 by mymac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	philo_validation(char **ag)
{
	int	i;

	i = 0;
	while (ag[i])
	{
		if (ft_atoi(ag[i]) <= 0)
			return (philo_errors(E_NVS));
		i++;
	}
	if (i < 4 || i > 5)
		return (philo_errors(E_NOP));
	return (TRUE);
}
