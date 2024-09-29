/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:54:30 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/21 16:41:55 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Verifica si el número representado por la cadena de caracteres es el valor
 * máximo de un entero. Si el número es mayor que 2147483647 o menor que
 * -2147483648, se liberan las estructuras de datos y se finaliza el programa.
 *
 * @param str La cadena de caracteres que representa el número a verificar.
 */
static void	is_max_int(char *str)
{
	if (ft_atol(str) > 2147483647 || ft_atol(str) < -2147483648)
		free_stacks(NULL, 0, 1, 1);
}

/**
 * Verifica si hay elementos repetidos en los argumentos de entrada.
 *
 * @param argc La cantidad de argumentos de entrada.
 * @param argv Los argumentos de entrada como un arreglo de cadenas
 * de caracteres.
 * @return 1 si hay elementos repetidos, 0 en caso contrario.
 */
int	is_repeated(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @brief Realiza la comprobación de los argumentos de entrada.
 *
 * Esta función verifica si los argumentos de entrada son válidos.
 * Comprueba que todos los caracteres sean dígitos y que no haya
 * caracteres no numéricos en posiciones incorrectas.
 *
 * @param argc El número de argumentos de línea de comandos.
 * @param argv Un array de cadenas que contiene los argumentos de
 * línea de comandos.
 * @param stacks Un puntero a la estructura de datos t_stack.
 */
void	comprobation(int argc, char **argv, t_stack *stacks)
{
	int		i;
	size_t	j;

	i = 1;
	if (argv[i][0] == '\0')
		free_stacks(stacks, 0, 1, 1);
	while (i < argc)
	{
		j = 0;
		while (j < ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]))
			{
				if (j == 0 && ft_strlen(argv[i]) != 1 && (argv[i][j] == '-'
					|| argv[i][j] == '+'))
				{
					j++;
					continue ;
				}
				free_stacks(stacks, 1, 1, 1);
			}
			j++;
		}
		i++;
	}
}

/**
 * Verifica los argumentos de entrada y realiza diversas comprobaciones.
 *
 * @param argc El número de argumentos de la línea de comandos.
 * @param argv Un array de cadenas que representan los argumentos de la
 * línea de comandos.
 * @param stacks Un puntero a la estructura t_stack que contiene las pilas.
 * @return 1 si los argumentos son válidos, 0 si no lo son.
 */
int	checker(int argc, char **argv, t_stack *stacks)
{
	int	i;
	int	num;

	i = 1;
	num = 1;
	if (argc < 2)
		free_stacks(stacks, 0, 0, 1);
	comprobation(argc, argv, stacks);
	while (i < argc)
	{
		is_max_int(argv[i]);
		if (is_repeated(argc, argv) == 1)
		{
			num = 0;
			free_stacks(stacks, 0, 1, 1);
			break ;
		}
		i++;
	}
	return (num);
}
