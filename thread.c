/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:55:10 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/24 16:47:57 by griogu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

t_philo	*destroy_thread(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_join(philo[i].thread, NULL);
		pthread_mutex_destroy(&philo[i].mutex);
		i++;
	}
	free(philo);
	return (NULL);
}

t_philo	*initialize_thread(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->number_of_philo);
	if (!philo)
		return (destroy_thread(philo, data));
	while (i < data->number_of_philo)
	{
		philo[i].time_to_sleep = data->time_to_sleep;
		philo[i].time_to_die = data->time_to_die;
		philo[i].time_to_eat = data->time_to_eat;
		philo[i].number_of_meal = data->number_of_meal;
		philo[i].philo = i;
		if (pthread_create(&philo[i].thread, NULL,
				(void *)routine, philo) != 0)
			return (destroy_thread(philo, data));
		if (pthread_mutex_init(&philo[i].mutex, NULL) != 0)
			return (destroy_thread(philo, data));
		i++;
	}
	return (philo);
}
