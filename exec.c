/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:43:56 by mpendilh          #+#    #+#             */
/*   Updated: 2025/01/02 14:26:07 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
	{
		error_management(0);
		return (0);
	}
	memset(&data, 0, sizeof(t_data));
	if (!parsing(&data, av, ac))
		return (0);
	if (!initialize_struct(&data))
		return (free_error(&data, 3));
	if (!initialize_mutex(&data))
		return (free_error(&data, 4));
	initialize_philo(&data);
	if (!start_routine(&data))
		return (free_error(&data, 5));
	destroy_thread(&data, data.number_of_philo);
	destroy_mutex(&data, data.number_of_philo);
	free(data.philo);
	free(data.forks);
	return (0);
}
