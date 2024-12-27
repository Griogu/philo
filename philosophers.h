/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:44:27 by mpendilh          #+#    #+#             */
/*   Updated: 2024/12/26 17:44:01 by griogu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define ERROR_MESSAGE "Error\n"
# define SETTINGS_ERROR "nbr_philo, time : die, eat, sleep [philo_must_eat].\n"
# define ARGS_ERROR "Wrong arguments.\n"
# define NBR_OF_MEAL "Number of meal can_t be equal to 0.\n"
# define THREAD_ERROR "Thread can't be created.\n"

# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <limits.h> 
# include <unistd.h>

typedef struct s_philo
{
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				number_of_meal;
	int				philo;

	bool			is_dead;

	pthread_mutex_t	mutex;
	pthread_t		thread;
}	t_philo;

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
t_philo	*initialize_thread(t_data *data);
t_philo	*destroy_thread(t_philo *philo, t_data *data);
void	routine(t_philo *philo);

#endif
