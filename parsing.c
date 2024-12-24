/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:37:01 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/24 16:30:19 by griogu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

static int	ft_atoi(char *nptr)
{
	int	i;
	int	result;
	int	counter;

	i = 0;
	counter = 0;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			counter++;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	if (counter % 2 == 1)
		return (-result);
	return (result);
}

static int	ft_atol(char *tab)
{
	int			i;
	long int	result;
	int			counter;

	i = 0;
	result = 0;
	counter = 0;
	while (tab[i] == ' '
		|| (tab[i] >= 9 && tab[i] <= 13))
		i++;
	if (tab[i] == '-' || tab[i] == '+')
	{
		if (tab[i] == '-')
			counter = 1;
		i++;
	}
	while (tab[i] >= '0' && tab[i] <= '9')
	{
		result = result * 10 + (tab[i++] - 48);
		if (result > 2147483648 || (result > INT_MAX && !counter))
			return (1);
	}
	if (tab[i])
		return (1);
	return (0);
}

static void	initialize_data(t_data *data, char *tab, int i)
{
	if (i == 1)
		data->number_of_philo = ft_atoi(tab);
	if (i == 2)
		data->time_to_die = ft_atoi(tab);
	if (i == 3)
		data->time_to_eat = ft_atoi(tab);
	if (i == 4)
		data->time_to_sleep = ft_atoi(tab);
	if (i == 5)
		data->number_of_meal = ft_atoi(tab);
}

int	ft_is_digit(char *tab)
{
	int	i;

	i = 0;
	if (!tab[i])
		return (0);
	while (tab[i])
	{
		if (tab[i] > '9' || tab[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int	parsing(t_data *data, char **av, int ac)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atol(av[i]) || !ft_is_digit(av[i]))
		{
			error_management(1);
			return (0);
		}
		initialize_data(data, av[i], i);
		i++;
	}
	if (ac == 6 && !data->number_of_meal)
	{
		error_management(2);
		return (0);
	}
	if (ac == 5)
		data->number_of_meal = -1;
	return (1);
}
