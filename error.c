/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:24:18 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/31 12:51:27 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	error_management(int signal)
{
	printf(ERROR_MESSAGE);
	if (!signal)
		printf(SETTINGS_ERROR);
	else if (signal == 1)
		printf(ARGS_ERROR);
	else if (signal == 2)
		printf(NBR_OF_MEAL);
	else if (signal == 3)
		printf(MALLOC_ERROR);
	else if (signal == 4)
		printf(MUTEX_ERROR);
	else if (signal == 5)
		printf(THREAD_ERROR);
}

int	free_error(t_data *data, int signal)
{
	free(data->philo);
	free(data->forks);
	error_management(signal);
	return (0);
}
