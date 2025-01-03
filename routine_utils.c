/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:34:28 by mpendilh          #+#    #+#             */
/*   Updated: 2025/01/03 13:27:59 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

bool	is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead);
	if (timestamp() - philo->start >= philo->time_to_die)
	{
		printf_message(philo, 4);
		*philo->is_dead = philo->id;
		pthread_mutex_unlock(philo->dead);
		return (true);
	}
	pthread_mutex_unlock(philo->dead);
	return (false);
}

int	get_fork(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	printf_message(philo, 0);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(fork);
		return (1);
	}
	return (0);
}

void	printf_message(t_philo *philo, int signal)
{
	unsigned long long	time;

	if (signal != 4)
		pthread_mutex_lock(philo->dead);
	pthread_mutex_lock(philo->print);
	time = timestamp() - philo->first_start;
	if (!signal && !*philo->is_dead)
		printf(PHILO FORK, time, philo->id);
	else if (signal == 1 && !*philo->is_dead)
		printf(PHILO EAT, time, philo->id);
	else if (signal == 2 && !*philo->is_dead)
		printf(PHILO SLEEP, time, philo->id);
	else if (signal == 3 && !*philo->is_dead)
		printf(PHILO THINK, time, philo->id);
	else if (signal == 4 && !*philo->is_dead)
	{
		printf(DIE, time, philo->id);
		pthread_mutex_unlock(philo->print);
		return ;
	}
	pthread_mutex_unlock(philo->dead);
	pthread_mutex_unlock(philo->print);
}
