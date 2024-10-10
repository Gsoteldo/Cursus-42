/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:21:39 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/09/17 20:56:08 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_arguments(t_philo *philo, char *argv[])
{
	philo->num_of_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->num_of_meals = ft_atoi(argv[5]);
	else
		philo->num_of_meals = -1;
}

static void	init_values(t_data *data, char *argv[], pthread_mutex_t **forks)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		data->philo[i].id = i + 1;
		data->philo[i].start_time = get_current_time();
		data->philo[i].last_meal = get_current_time();
		data->philo[i].eat_flag = 0;
		data->philo[i].times_eaten = 0;
		data->philo[i].print_mutex = &data->print_mutex;
		data->philo[i].eat_mutex = &data->eat_mutex;
		data->philo[i].dead_mutex = &data->dead_mutex;
		data->philo[i].init_philo = &data->init_philo;
		init_arguments(&data->philo[i], argv);
		data->philo[i].dead_flag = &data->dead_flag;
		data->philo[i].l_fork = *forks + i;
		data->philo[i].r_fork = *forks + (i + 1) % ft_atoi(argv[1]);
		i++;
	}
}

static void	initialization_forks(pthread_mutex_t **forks, int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		pthread_mutex_init((*forks + i), NULL);
		i++;
	}
}

void	start_philo(t_data *data, pthread_mutex_t **forks, char *argv[])
{
	data->dead_flag = 0;
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->eat_mutex, NULL);
	pthread_mutex_init(&data->dead_mutex, NULL);
	pthread_mutex_init(&data->init_philo, NULL);
	data->philo = malloc(sizeof(t_philo) * (ft_atoi(argv[1])));
	if (!data->philo)
	{
		printf(RED "Error: " NC "Fail creating philo\n");
		free_and_destroy(data, *forks, NULL);
	}
	*forks = malloc(sizeof(pthread_mutex_t) * (ft_atoi(argv[1])));
	if (!forks)
	{
		printf(RED "Error: " NC "Fail creating forks\n");
		free_and_destroy(data, *forks, NULL);
	}
	initialization_forks(forks, ft_atoi(argv[1]));
	init_values(data, argv, forks);
}
