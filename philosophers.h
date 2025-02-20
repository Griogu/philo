/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:44:27 by mpendilh          #+#    #+#             */
/*   Updated: 2025/01/15 14:41:04 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define PHILO "\033[36;03m| %-10llums | 👴 philosopher %-5d"
# define FORK "| has taken a fork.🍴\033[00m\n"
# define EAT "| is eating.🍝\033[00m\n"
# define SLEEP "| is sleeping.🛏️\033[00m\n"
# define THINK "| is thinking.🤔\033[00m\n"
# define DIE "\033[31;03m| %-10llums | 💀 philosopher %-5d| died.⚰️\033[00m\n"
# define ERROR_MESSAGE "Error\n"
# define SETTINGS_ERROR "nbr_philo, time : die, eat, sleep [philo_must_eat].\n"
# define ARGS_ERROR "Wrong arguments.\n"
# define NBR_OF_MEAL "Number of meal can_t be equal to 0.\n"
# define MALLOC_ERROR "Malloc failed.\n"
# define MUTEX_ERROR "Mutex can't be created.\n"
# define THREAD_ERROR "Thread can't be created.\n"

# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <limits.h> 
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				number_of_meal;
	int				number_of_philo;
	int				id;

	int				*is_dead;

	pthread_t		thread;

	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*print;
	pthread_mutex_t	*dead;

	long long		time_to_sleep;
	long long		time_to_eat;
	long long		first_start;
	long long		start;
	long long		time_to_die;
}	t_philo;

typedef struct s_data
{
	int				number_of_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meal;

	int				is_dead;

	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;

	t_philo			*philo;

	long long		time_to_die;
}	t_data;

// parsing

int			parsing(t_data *data, char **av, int ac);

// initialization

int			initialize_philo(t_data *data);
int			initialize_struct(t_data *data);
int			initialize_mutex(t_data *data);

// exit

void		error_management(int signal);
int			free_error(t_data *data, int signal);
void		destroy_mutex(t_data *data, int index);
void		destroy_thread(t_data *data, int index);

// routine + utils

int			start_routine(t_data *data);
long long	timestamp(void);
bool		is_dead(t_philo *philo);
void		unlock_forks(t_philo *philo);
int			get_fork(t_philo *philo, pthread_mutex_t *fork);
void		printf_message(t_philo *philo, int signal);
void		dead(t_philo *philo);
void		smart_sleep(t_philo *philo);
int			start_routine2(t_data *data, int i);

#endif
