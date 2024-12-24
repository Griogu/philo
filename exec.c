/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:43:56 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/23 11:10:49 by griogu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;

	if (ac != 5 && ac != 6)
	{
		error_management(0);
		return (0);
	}
	memset(&data, 0, sizeof(t_data));
	if (!parsing(&data, av, ac))
		return (0);
	philo = initialize_thread(&data);
	if (!philo)
	{
		error_management(3);
		return (0);
	}
	destroy_thread(philo, &data);
	return (0);
}
