/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:43:31 by gabo              #+#    #+#             */
/*   Updated: 2024/09/17 20:55:20 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(9);
	return (0);
}

void	free_and_destroy(t_data *data, pthread_mutex_t *forks, char *str)
{
	int	i;
	int	num;

	i = 0;
	num = data->philo[0].num_of_philo;
	if (str)
		printf("%s\n", str);
	free(data->philo);
	while (i < num)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
	pthread_mutex_destroy(&data->eat_mutex);
	pthread_mutex_destroy(&data->print_mutex);
}

void	printf_with_id_and_time(t_philo *philo, int id, char *str)
{
	size_t	time;

	pthread_mutex_lock(philo->print_mutex);
	time = get_current_time() - philo->start_time;
	if (*philo->dead_flag == 1)
	{
		pthread_mutex_unlock(philo->print_mutex);
		return ;
	}
	printf("%ld %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->print_mutex);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	negativo;

	i = 0;
	num = 0;
	negativo = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			negativo++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i++] - '0');
	}
	if (negativo % 2 == 1)
		return (num * -1);
	return (num);
}
