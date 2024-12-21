/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:24:18 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/18 11:27:18 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	error_management(int signal)
{
	printf(ERROR_MESSAGE);
	if (!signal)
		printf(SETTINGS_ERROR);
	if (signal == 1)
		printf(ARGS_ERROR);
	if (signal == 2)
		printf(NBR_OF_MEAL);
}
