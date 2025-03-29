/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_expansion_pid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:18:44 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 18:33:25 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Obtiene el PID del proceso actual leyendo el archivo /proc/self/stat.
 *
 * Esta función abre el archivo /proc/self/stat para leer información sobre
 * el proceso actual. Extrae el PID del contenido del archivo y lo devuelve
 * como una cadena de caracteres. Si ocurre algún error durante la lectura
 * o el procesamiento, la función devuelve NULL.
 *
 * @return Un puntero a una cadena de caracteres que contiene el PID del
 * proceso actual, o NULL si ocurre un error.
 *
 * @note Es responsabilidad del llamador liberar la memoria asignada para
 * la cadena devuelta.
 *
 * @warning Esta función depende de la existencia del archivo /proc/self/stat,
 * por lo que no funcionará en sistemas que no soporten el sistema de archivos
 * proc.
 */
static char	*get_pid(void)
{
	int		fd;
	char	*buffer;
	char	*pid;

	pid = NULL;
	buffer = NULL;
	fd = open("/proc/self/stat", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (NULL);
	}
	buffer = get_next_line(fd);
	if (!buffer)
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	pid = ft_substr(buffer, 0, ft_strchr(buffer, ' ') - buffer);
	if (!pid)
		pid = NULL;
	free(buffer);
	return (pid);
}

/**
 * @brief Hace un join de la cadena line con el resto de la cadena str y libera
 * la cadena line original.
 * 
 * @param line La cadena a la que se le hará el join.
 * @param str La cadena con la que se hará el join.
 * 
 * @return Un puntero a la cadena resultante del join.
 * 
 * @note Es responsabilidad del llamador liberar la memoria asignada para
 * la cadena devuelta.
 */
static char	*join_and_free(char *line, char *str, int *j)
{
	char	*temp;

	temp = ft_strjoin(line, str + *j + 2);
	free(line);
	line = temp;
	return (line);
}

/**
 * @brief: Esta función maneja la expansión del PID (Process ID) en una
 * cadena de caracteres. 
 * Reemplaza la secuencia "$$" con el PID actual del proceso.
 * 
 * @note: La función 'get_pid()' obtiene el PID actual del proceso, llamando al
 * fichero /proc/self/stat, que contiene la información del proceso actual
 * 
 * @note: Si el carácter siguiente a "$$" es otro '$', se llama
 * a 'process_line_with_expansion' para manejar la expansión adicional.
 * En cualquier otro caso, se llama a 'join_and_free' para concatenar el PID
 * con el resto de la cadena.
 * 
 * @param shell: Puntero a la estructura t_minishell que contiene el
 * estado del minishell.
 * @param j: Puntero a un entero que indica la posición actual en la cadena 'str'
 * donde se encontró "$".
 * @param str: La cadena de caracteres que se está procesando.
 * 
 * @return: Retorna una nueva cadena de caracteres con la expansión del
 * PID realizada.
 */
char	*expansion_pid(t_minishell *shell, int *j, char *str)
{
	char	*line;
	char	*temp;
	char	*aux;

	line = get_pid();
	if (str[*j + 2] == '\0')
	{
		temp = ft_strjoin(line, str + *j + 2);
		free(line);
		line = temp;
	}
	else if (str[*j + 2] == '$')
	{
		aux = process_line_with_expansion(shell, str + *j + 2);
		if (aux != NULL)
		{
			temp = ft_strjoin(line, aux);
			free(line);
			line = temp;
			free(aux);
		}
	}
	else
		line = join_and_free(line, str, j);
	return (line);
}
