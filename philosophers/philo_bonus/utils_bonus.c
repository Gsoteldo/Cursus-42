/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:37:50 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/10/04 00:51:33 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(9);
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long	ft_atol(const char *str)
{
	int		i;
	long	num;
	int		negativo;

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

void	printf_with_id_and_time(t_data *data, int id, char *str)
{
	size_t	time;

	sem_wait(data->print_semaphore);
	time = get_current_time() - data->start_time;
	if (data->dead_flag == 1)
	{
		sem_post(data->print_semaphore);
		return ;
	}
	printf("%ld %d %s\n", time, id, str);
	sem_post(data->print_semaphore);
	return ;
}

void	kill_them_all(t_data *data)
{
	int	status;
	int	i;
	int	j;

	i = 0;
	j = 0;
	status = 0;
	while (i < data->num_of_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			while (j++ < data->num_of_philo)
				kill(data->philo[j].pid, SIGINT);
			break ;
		}
		i++;
	}
	sem_close(data->forks);
	sem_close(data->print_semaphore);
	sem_close(data->dead_semaphore);
	sem_close(data->eat_semaphore);
	(sem_unlink("/forks"), sem_unlink("/eat_sem"));
	(sem_unlink("/print_sem"), sem_unlink("/dead_sem"));
	free(data->philo);
}
