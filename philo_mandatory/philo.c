/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:06:06 by tyuuki            #+#    #+#             */
/*   Updated: 2022/03/02 17:16:57 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int main(int argc, char **argv)
{
	t_philo			*philo;
	t_about_philo	*philos;
	
	(void)argc;
	philo = NULL;
	philos = NULL;
	if(!philo_validation(&argv[1]))
		return (FALSE);
	philo_init(&philo, &philos, &argv[1]);
	philo_start(philo, philos);
	return (TRUE);
}