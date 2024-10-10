/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:43:45 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/10/04 00:55:36 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# define GREEN "\033[0;32m"
# define NC "\033[0m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				*dead_flag;
	int				times_eaten;
	pid_t			pid;
}	t_philo;

typedef struct s_data
{
	pthread_t		monitor_thread;
	int				dead_flag;
	int				eat_flag;
	int				num_of_meals;
	int				num_of_philo;
	sem_t			*dead_semaphore;
	sem_t			*eat_semaphore;
	sem_t			*forks;
	sem_t			*print_semaphore;
	size_t			last_meal;
	size_t			start_time;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	t_philo			*philo;
}	t_data;

int		check_valid_args(int argc, char *argv[]);

void	start_philo(t_data *data, char *argv[]);
void	create_processes(t_data *data);
void	*monitor(void *data);
void	*routine(t_data *data);

long	ft_atol(const char *str);
void	printf_with_id_and_time(t_data *data, int id, char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);

size_t	get_current_time(void);
int		ft_usleep(size_t milliseconds);
void	kill_them_all(t_data *data);

#endif