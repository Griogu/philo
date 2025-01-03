/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:21:33 by mpendilh          #+#    #+#             */
/*   Updated: 2025/01/03 13:13:49 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	smart_sleep(t_philo *philo)
{
	if (!philo->number_of_philo % 2)
	{
		if (philo->id % 2)
			usleep(10);
	}
	else
	{
		if (!philo->id % 2)
			usleep(10);
	}
	philo->first_start = timestamp();
	philo->start = timestamp();
}

void	routine2(t_philo *philo)
{
	philo->first_start = timestamp();
	philo->start = timestamp();
	printf_message(philo, 0);
	usleep(philo->time_to_die * 1000);
	printf_message(philo, 4);
}

int	start_routine2(t_data *data, int i)
{
	if (pthread_create(&data->philo[i].thread, NULL,
			(void *)routine2, &data->philo[i]) != 0)
		return (0);
	return (1);
}
