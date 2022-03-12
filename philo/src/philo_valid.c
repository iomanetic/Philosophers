/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:10:38 by tyuuki            #+#    #+#             */
/*   Updated: 2022/03/02 14:57:20 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_validation(char **ag)
{
	int	i;

	i = 0;
	while (ag[i])
	{
		if (ft_atoi(ag[i]) < 0)
			return (philo_errors(E_NVS));
		i++;
	}
	if (i < 4 || i > 5)
		return (philo_errors(E_NOP));
	return (TRUE);
}