/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_errors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymac <mymac@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:17:50 by mymac             #+#    #+#             */
/*   Updated: 2022/03/22 13:21:02 by mymac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	help_errors(int flag)
{
	if (flag == E_EMA)
	{
		printf("%s", YELLOW EMA WHITE);
		return (FALSE);
	}
	else if (flag == E_ETC)
	{
		printf("%s", YELLOW ETC WHITE);
		return (FALSE);
	}
	return (FALSE);
}

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
	if (!help_errors(flag))
		return (FALSE);
	return (TRUE);
}
