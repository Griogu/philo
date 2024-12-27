/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: griogu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:45:20 by griogu            #+#    #+#             */
/*   Updated: 2024/12/26 17:44:32 by griogu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	routine(t_philo *philo)
{
	if (philo[philo->philo].number_of_meal > 0)
	{
		while (philo[philo->philo].number_of_meal > 0)
		{
			usleep(1);
			printf("index : %d\n", philo[philo->philo].philo);
			printf("meal : %d\n", philo[philo->philo].number_of_meal);
			philo[philo->philo].number_of_meal--;
		}
	}
	else
	{
		while (1)
			printf("%d\n", philo->time_to_die);
	}
}
