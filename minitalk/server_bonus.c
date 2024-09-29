/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:53:26 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/03/26 17:15:57 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

#define RC "\x1b[0m"
#define BLUE "\x1b[34m"

/*Colores
	Blue: "\x1b[34m"
	ORANGE: "\x1b[33m"
*/

/**
 * @brief Manejador de señales para la recepción de datos.
 *
 * Esta función se encarga de manejar las señales recibidas para la
 * recepción de datos.
 * Al recibir una señal, se almacena el bit correspondiente en la variable 'c'
 * hasta que se hayan recibido los 8 bits necesarios para formar un carácter
 * completo. Una vez se hayan recibido los 8 bits, se imprime el carácter
 * correspondiente y se envía una señal al proceso cliente para indicar que
 * se ha recibido el carácter correctamente.
 *
 * @param sig El número de la señal recibida.
 * @param info Puntero a una estructura que contiene información adicional
 * sobre la señal.
 * @param ucontext Puntero al contexto de ejecución actual.
 */
static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static char		c;
	static int		count;
	static pid_t	pid;

	(void)ucontext;
	if (!pid)
		pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++count == 8)
	{
		count = 0;
		if (!c)
		{
			kill(pid, SIGUSR2);
			ft_printf("\x1b[33m" "\n\n\nWaiting for message... \n" RC);
			pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("\x1b[34m" "Server PID: " RC "%d\n\n", getpid());
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	ft_printf("\x1b[33m" "Waiting for message...\n" RC);
	while (1)
		pause();
	return (0);
}
