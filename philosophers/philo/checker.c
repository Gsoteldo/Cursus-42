/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:22:30 by gabo              #+#    #+#             */
/*   Updated: 2024/09/17 20:55:36 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Verifica si los argumentos de contenido son válidos.
 *
 * Esta función verifica si los caracteres en la cadena de caracteres `argv`
 * son dígitos numéricos.
 * Si encuentra un carácter que no es un dígito numérico, imprime un mensaje
 * de error y devuelve 0.
 * 
 * Si todos los caracteres son dígitos numéricos, devuelve 1.
 *
 * @param argv La cadena de caracteres que contiene los argumentos.
 * @return 1 si los argumentos son válidos, 0 si no lo son.
 */
static int	check_content_args(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] < '0' || argv[i] > '9')
		{
			printf("Error: Invalid argument\n");
			return (0);
		}
		i++;
	}
	return (1);
}

/**
 * @brief Verifica el número de argumentos.
 *
 * Esta función verifica si el número de argumentos proporcionados es válido.
 * Debe haber entre 5 y 6 argumentos para que sea considerado válido.
 *
 * @param argc El número de argumentos proporcionados al programa.
 * @return 0 si el número de argumentos es inválido, 1 si es válido.
 */
static int	check_num_args(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf(RED "Error: " NC "Invalid number of arguments\n\n");
		printf("\tUsage: ./philo [number_of_philosophers] [time_to_die]");
		printf(" [time_to_eat] [time_to_sleep] ");
		printf("[number_of_times_each_philosopher_must_eat]\n");
		return (0);
	}
	return (1);
}

/**
 * @brief Verifica si los argumentos proporcionados son válidos. 
 * En caso de que no lo sean, imprime un mensaje de error. Se
 * considera que los argumentos son válidos si el número de argumentos
 * es válido y si el contenido de los argumentos es válido.
 * 
 *
 * @param argc El número de argumentos proporcionados al programa.
 * @param argv Un arreglo de cadenas que contiene los argumentos proporcionados 
 * al programa.
 * @return 0 si los argumentos no son válidos, 1 si son válidos.
 */
int	check_valid_args(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (check_num_args(argc) == 0)
		return (0);
	while (i < argc)
	{
		if ((ft_atoi(argv[i]) <= 0) || (check_content_args(argv[i]) == 0))
		{
			printf(RED "Error: " NC "Argument %d is invalid\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_alive(size_t time, t_philo *philo, char *str)
{
	time_t	start;

	start = get_current_time();
	if (str)
		printf_with_id_and_time(philo, philo->id, str);
	while (1)
	{
		pthread_mutex_lock(philo->dead_mutex);
		if (*philo->dead_flag == 1)
		{
			pthread_mutex_unlock(philo->dead_mutex);
			return ;
		}
		pthread_mutex_unlock(philo->dead_mutex);
		if (get_current_time() - start >= time)
			break ;
		usleep(100);
	}
}
