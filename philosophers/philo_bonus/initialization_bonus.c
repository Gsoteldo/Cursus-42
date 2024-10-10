/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:54:14 by gabo              #+#    #+#             */
/*   Updated: 2024/10/04 00:57:18 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	init_values(t_data *data, char *argv[])
{
	data->philo->id = 0;
	data->start_time = get_current_time();
	data->last_meal = get_current_time();
	data->eat_flag = 0;
	data->philo->times_eaten = 0;
	data->num_of_philo = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		data->num_of_meals = ft_atol(argv[5]);
	else
		data->num_of_meals = -1;
	data->philo->dead_flag = &data->dead_flag;
}

static void	initialization_semaphores(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/print_sem");
	sem_unlink("/dead_sem");
	data->forks = sem_open("/forks", O_CREAT, 0644, data->num_of_philo);
	if (data->forks == SEM_FAILED)
	{
		write(2, "Semaphore error\n", 16);
		exit(1);
	}
	data->print_semaphore = sem_open("/print_sem", O_CREAT, 0644, 1);
	if (data->print_semaphore == SEM_FAILED)
	{
		write(2, "Semaphore error\n", 16);
		exit(1);
	}
	data->dead_semaphore = sem_open("/dead_sem", O_CREAT, 0644, 1);
	if (data->dead_semaphore == SEM_FAILED)
	{
		write(2, "Semaphore error\n", 16);
		exit(1);
	}
}

void	start_philo(t_data *data, char *argv[])
{
	data->dead_flag = 0;
	data->philo = (t_philo *)malloc(sizeof(t_philo) * ft_atol(argv[1]));
	if (!data->philo)
	{
		write(2, "Malloc error\n", 13);
		exit(1);
	}
	init_values(data, argv);
	initialization_semaphores(data);
}
