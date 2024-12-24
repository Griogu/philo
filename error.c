/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:24:18 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/23 10:41:39 by griogu           ###   ########.fr       */
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
		printf(THREAD_ERROR);
}
