/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymac <mymac@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:10:51 by tyuuki            #+#    #+#             */
/*   Updated: 2022/03/22 13:14:17 by mymac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
	return (TRUE);
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
	else if (flag == E_EMI)
	{
		printf("%s", YELLOW EMI WHITE);
		return (FALSE);
	}
	if (!help_errors(flag))
		return (FALSE);
	return (TRUE);
}
