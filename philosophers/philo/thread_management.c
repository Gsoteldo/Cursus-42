/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:10:07 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/09/19 19:43:08 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_data *data, pthread_mutex_t *forks)
{
	int			i;
	pthread_t	monitoring;

	i = 0;
	pthread_mutex_lock(&data->init_philo);
	while (i < data->philo[0].num_of_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &routine, \
			&data->philo[i]) != 0)
			free_and_destroy(data, forks, RED "Error:" NC "creating thread");
		i++;
	}
	i = 0;
	if (pthread_create(&monitoring, NULL, &monitor, data->philo) != 0)
		free_and_destroy(data, forks, RED "Error: " NC "creating thread");
	pthread_mutex_unlock(&data->init_philo);
	if (pthread_join(monitoring, NULL) != 0)
		free_and_destroy(data, forks, RED "Error:" NC "joining thread");
	while (i < data->philo[0].num_of_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			free_and_destroy(data, forks, RED "Error: " NC "joining thread");
		i++;
	}
}
