/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:44:27 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/21 14:01:12 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define ERROR_MESSAGE "Error\n"
# define SETTINGS_ERROR "nbr_philo, time : die, eat, sleep [philo_must_eat].\n"
# define ARGS_ERROR "Wrong arguments.\n"
# define NBR_OF_MEAL "Number of meal can_t be equal to 0.\n"

# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <limits.h> 

typedef struct s_data
{
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_meal;
}	t_data;

void	error_management(int signal);
int		parsing(t_data *data, char **av, int ac);
void	initialize_thread(t_data *data);

#endif
