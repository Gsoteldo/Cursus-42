/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:40:08 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/10/04 00:56:02 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (check_valid_args(argc, argv) == 0)
		return (1);
	start_philo(&data, argv);
	create_processes(&data);
	kill_them_all(&data);
	return (0);
}
