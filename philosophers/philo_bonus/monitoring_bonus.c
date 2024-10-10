/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:21:49 by gabo              #+#    #+#             */
/*   Updated: 2024/10/07 18:59:19 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	is_dead(t_data *data)
{
	sem_wait(data->eat_semaphore);
	if (get_current_time() - data->last_meal >= data->time_to_die)
	{
		printf_with_id_and_time(data, data->philo->id, "died");
		sem_wait(data->print_semaphore);
		data->dead_flag = 1;
		exit(1);
	}
	sem_post(data->eat_semaphore);
}

void	*monitor(void *arg)
{
	t_data	*data;
	int		i;

	i = 0;
	data = (t_data *)arg;
	while (1)
	{
		is_dead(data);
		if (data->dead_flag == 1)
			exit(0);
		usleep(100);
		while (data->num_of_meals != -1 \
			&& data->philo[i].times_eaten >= data->num_of_meals \
			&& i < data->num_of_philo)
			i++;
		if (i == data->num_of_philo)
		{
			data->dead_flag = 1;
			exit(0);
		}
	}
	return (NULL);
}
