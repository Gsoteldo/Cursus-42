/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:50:54 by gabo              #+#    #+#             */
/*   Updated: 2024/10/07 19:00:53 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_alive(size_t time, t_data *data, char *str)
{
	time_t	start;

	start = get_current_time();
	if (str)
		printf_with_id_and_time(data, data->philo->id, str);
	while (1)
	{
		if (get_current_time() - start >= time)
			break ;
		usleep(10);
		sem_wait(data->dead_semaphore);
		if (data->dead_flag == 1)
		{
			sem_post(data->dead_semaphore);
			break ;
		}
		sem_post(data->dead_semaphore);
	}
	return ;
}

int	dead_philo(t_data *data)
{
	sem_wait(data->dead_semaphore);
	if (data->dead_flag == 1)
	{
		sem_post(data->dead_semaphore);
		return (1);
	}
	sem_post(data->dead_semaphore);
	return (0);
}

void	eating(t_data *data)
{
	usleep(10);
	sem_wait(data->forks);
	printf_with_id_and_time(data, data->philo->id, "has taken a fork");
	sem_wait(data->forks);
	printf_with_id_and_time(data, data->philo->id, "has taken a fork");
	sem_wait(data->eat_semaphore);
	data->last_meal = get_current_time();
	sem_post(data->eat_semaphore);
	check_alive(data->time_to_eat, data, "is eating");
	data->philo->times_eaten++;
	sem_post(data->forks);
	sem_post(data->forks);
}

void	*routine(t_data *data)
{
	data->last_meal = get_current_time();
	if (pthread_create(&data->monitor_thread, NULL, monitor, (void *)data))
	{
		printf("Error creating monitor thread\n");
		return (NULL);
	}
	if (data->philo->id % 2 == 0)
		ft_usleep(5);
	sem_wait(data->dead_semaphore);
	while (1)
	{
		sem_post(data->dead_semaphore);
		eating(data);
		if (dead_philo(data))
			exit(0);
		if (data->num_of_meals != -1 \
			&& data->philo->times_eaten >= data->num_of_meals)
			exit(0);
		check_alive(data->time_to_sleep, data, "is sleeping");
		printf_with_id_and_time(data, data->philo->id, "is thinking");
		sem_wait(data->dead_semaphore);
	}
	pthread_join(data->monitor_thread, NULL);
	exit(1);
}
