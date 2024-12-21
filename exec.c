/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:43:56 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/21 14:01:32 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data		data;

	if (ac != 5 && ac != 6)
	{
		error_management(0);
		return (0);
	}
	memset(&data, 0, sizeof(t_data));
	if (!parsing(&data, av, ac))
		return (0);
	initialize_thread(&data);
	return (0);
}
