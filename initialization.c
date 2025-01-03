/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:55:10 by mpendilh          #+#    #+#             */
/*   Updated: 2025/01/03 12:59:55 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	initialize_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			destroy_mutex(data, i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	initialize_struct(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->number_of_philo);
	if (!data->philo)
		return (0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philo);
	if (!data->forks)
		return (0);
	return (1);
}

int	initialize_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		data->philo[i].time_to_die = data->time_to_die;
		data->philo[i].time_to_eat = data->time_to_eat;
		data->philo[i].time_to_sleep = data->time_to_sleep;
		data->philo[i].number_of_meal = data->number_of_meal;
		data->philo[i].number_of_philo = data->number_of_philo;
		data->philo[i].id = i + 1;
		data->philo[i].dead = &data->dead;
		data->philo[i].print = &data->print;
		data->philo[i].is_dead = &data->is_dead;
		data->philo[i].right_fork = &data->forks[i];
		if (i + 1 == data->number_of_philo)
			data->philo[i].left_fork = &data->forks[0];
		else
			data->philo[i].left_fork = &data->forks[i + 1];
		i++;
	}
	return (1);
}
