/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:53:16 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/03/31 18:09:11 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

#define RC "\x1b[0m"

/*Colores 
	RED: "\x1b[31m"
	BLUE "\x1b[34m"
*/

static int	checker(char **str)
{
	int	flag;
	int	i;

	i = 0;
	flag = 1;
	while (str[1][i])
		if (ft_isdigit(str[1][i++]) == 0)
			flag = 0;
	return (flag);
}

/**
 * @brief Función de controlador de señal.
 *
 * Esta función se encarga de manejar las señales recibidas por el programa
 * cliente.
 * 
 * Si la señal recibida es SIGUSR1, incrementa el contador interno.
 * Si la señal recibida es diferente a SIGUSR1, imprime el valor actual del
 * contador y finaliza el programa.
 *
 * @param sig La señal recibida.
 */
static void	handler(int sig)
{
	static int		count;

	if (sig == SIGUSR1)
		++count;
	else
	{
		if (count)
		{
			ft_printf("\x1b[34m" "\nMensaje recibido correctamente ");
			ft_printf("(%d bytes)\n" RC, count);
		}
		exit(0);
	}
}

/**
 * @brief Envía un mensaje utilizando señales.
 *
 * Esta función envía un mensaje utilizando señales. Toma como argumentos
 * el identificador de la señal y el puntero a la cadena de caracteres que
 * se desea enviar.
 *
 * @param signal El identificador de la señal.
 * @param str El puntero a la cadena de caracteres a enviar.
 */
static void	send_message(int signal, char *str)
{
	int		j;
	char	c;

	while (*str)
	{
		j = 8;
		c = *str++;
		while (j--)
		{
			if ((c >> j) & 1)
				kill(signal, SIGUSR2);
			else
				kill(signal, SIGUSR1);
			usleep(100);
		}
	}
	j = 8;
	while (j--)
	{
		kill(signal, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;
	int		i;

	i = 0;
	if (argc != 3 || !ft_strlen(argv[2]) || checker(argv) == 0)
	{
		ft_putstr_fd("\x1b[31m" "ERROR! " RC, 2);
		ft_putstr_fd("This format is needed: \n", 2);
		ft_putstr_fd("\n\t./client [server_pid] \"Message\"\n\n", 2);
		return (1);
	}
	pid = atoi(argv[1]);
	str = argv[2];
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	send_message(pid, str);
	while (1)
		pause();
	return (0);
}
