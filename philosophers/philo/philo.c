/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:07:16 by gabo              #+#    #+#             */
/*   Updated: 2024/09/16 22:38:16 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data			data;
	pthread_mutex_t	*forks;

	forks = NULL;
	if (check_valid_args(argc, argv) == 0)
		return (1);
	start_philo(&data, &forks, argv);
	create_threads(&data, forks);
	free_and_destroy(&data, forks, NULL);
	return (0);
}
