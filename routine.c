/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: griogu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:45:20 by griogu            #+#    #+#             */
/*   Updated: 2025/01/03 13:36:23 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

static int	ft_sleep(t_philo *philo)
{
	int					i;

	i = 0;
	printf_message(philo, 2);
	while (timestamp() - philo->start
		< philo->time_to_sleep + philo->time_to_eat)
	{
		usleep(1000);
		if (is_dead(philo))
			return (1);
		i++;
	}
	printf_message(philo, 3);
	return (0);
}

static int	eat(t_philo *philo)
{
	int	i;

	i = 0;
	if (is_dead(philo))
		return (1);
	printf_message(philo, 1);
	philo->start = timestamp();
	while (timestamp() - philo->start < philo->time_to_eat)
	{
		usleep(1000);
		if (is_dead(philo))
		{
			unlock_forks(philo);
			return (1);
		}
		i++;
	}
	unlock_forks(philo);
	if (ft_sleep(philo))
		return (1);
	return (0);
}

static int	take_fork(t_philo *philo)
{
	pthread_mutex_t		*fork_a;
	pthread_mutex_t		*fork_b;

	fork_a = philo->left_fork;
	fork_b = philo->right_fork;
	if (philo->id % 2)
	{
		fork_a = philo->right_fork;
		fork_b = philo->left_fork;
	}
	if (is_dead(philo))
		return (1);
	if (get_fork(philo, fork_a))
		return (1);
	if (get_fork(philo, fork_b))
	{
		pthread_mutex_unlock(fork_a);
		return (1);
	}
	return (0);
}

static void	routine(t_philo *philo)
{
	smart_sleep(philo);
	if (philo->number_of_meal != -1)
	{
		while (philo->number_of_meal > 0 && !*philo->is_dead)
		{
			if (take_fork(philo))
				break ;
			if (eat(philo))
				break ;
			usleep(800);
			philo->number_of_meal--;
		}
	}
	else
	{
		while (!*philo->is_dead)
		{
			if (take_fork(philo))
				break ;
			if (eat(philo))
				break ;
			usleep(800);
		}
	}
}

int	start_routine(t_data *data)
{
	int	i;

	i = 0;
	if (data->number_of_philo == 1)
		return (start_routine2(data, 0));
	else
	{
		while (i < data->number_of_philo)
		{
			if (pthread_create(&data->philo[i].thread, NULL,
					(void *)routine, &data->philo[i]) != 0)
				return (0);
			i++;
		}
	}
	return (1);
}
