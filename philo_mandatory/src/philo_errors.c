/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:10:51 by tyuuki            #+#    #+#             */
/*   Updated: 2022/03/02 14:57:34 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_errors(int flag)
{
	if (flag == E_NOP)
	{
		printf("%s", YELLOW NOP WHITE);
		return (FALSE);
	}
	if (flag == E_NVS)
	{
		printf("%s", YELLOW NVS WHITE);
		return (FALSE);
	}
	return (TRUE);
}