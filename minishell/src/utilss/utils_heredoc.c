/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:09:18 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 21:12:05 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Verifica si un carácter dado es un delimitador.
 *
 * Esta función determina si el carácter proporcionado es uno de los siguientes
 * delimitadores: espacio (' '), coma (','), punto ('.'), tabulación ('\t') o 
 * salto de línea ('\n').
 *
 * @param c El carácter a evaluar.
 * @return int Devuelve 1 si el carácter es un delimitador, de lo contrario 
 * devuelve 0.
 */
int	is_delimiter(char c)
{
	return (c == ' ' || c == ',' || c == '.' || c == '\t' || c == '\n');
}

/**
 * get_variable - Extrae el nombre de una variable de entorno de una cadena.
 *
 * @str: La cadena de entrada que puede contener una variable de entorno.
 *
 * Esta función busca el primer carácter '$' en la cadena de entrada y extrae
 * el nombre de la variable de entorno que le sigue. El nombre de la variable
 * puede contener caracteres alfanuméricos y guiones bajos ('_'). Si no se 
 * encuentra un carácter '$' o si la entrada es NULL, la función devuelve NULL.
 *
 * Retorna:
 * - Un puntero a una nueva cadena que contiene el nombre de la variable de 
 *   entorno extraída.
 * - NULL si no se encuentra una variable o si la entrada es NULL.
 */
char	*get_variable(char *str)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	aux = NULL;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '$')
		i++;
	j = i + 1;
	while (str[j] && (str[j] == '_' || ft_isalnum(str[j])))
		j++;
	aux = ft_substr(str, i + 1, j - i - 1);
	return (aux);
}

/**
 * @brief Verifica si una variable está presente en el entorno de shell.
 *
 * Esta función recorre el arreglo de variables de entorno `envp` del shell
 * y compara cada variable con el valor proporcionado en `temp`. Si encuentra
 * una coincidencia, devuelve 1, indicando que la variable está presente.
 * En caso contrario, devuelve 0.
 *
 * @param temp Cadena que representa el nombre de la variable a buscar.
 * @param shell Puntero a la estructura `t_minishell` que contiene el entorno
 *              del shell, incluyendo el arreglo `envp` con las variables de 
 * 				entorno.
 * @return int Devuelve 1 si la variable está presente en el entorno, 
 *             o 0 si no lo está.
 *
 * @note La función utiliza `ft_substr` para extraer el nombre de la variable
 *       de entorno antes del carácter '=' y `ft_strcmp` para comparar cadenas.
 *       Se asegura de liberar la memoria asignada dinámicamente para evitar
 *       fugas de memoria.
 */
int	is_in_env(char *temp, t_minishell *shell)
{
	char	*aux;
	size_t	difference;
	int		i;

	i = 0;
	aux = NULL;
	while (shell->envp[i] != NULL)
	{
		difference = ft_strchr(shell->envp[i], '=') - shell->envp[i];
		if (difference != ft_strlen(temp))
		{
			i++;
			continue ;
		}
		aux = ft_substr(shell->envp[i], 0, difference);
		if (ft_strcmp(aux, temp) == 0)
		{
			free(aux);
			return (1);
		}
		free(aux);
		i++;
	}
	return (0);
}

/**
 * @brief Obtiene el argumento en la posición especificada de la lista de 
 * argumentos.
 *
 * @param shell Puntero a la estructura t_minishell que contiene la lista
 * de argumentos.
 * @param n Índice del argumento que se desea obtener. Debe estar dentro
 * del rango válido.
 * @return Un puntero a una cadena duplicada que contiene el argumento en 
 * la posición n.
 * Si el índice n está fuera de rango, se devuelve una cadena vacía.
 */
char	*get_argument(t_minishell *shell, int n)
{
	char	*arg_value;

	if (n < 0 || n >= size_array(shell->args))
	{
		arg_value = ft_strdup("");
		if (!arg_value)
			arg_value = NULL;
		return (arg_value);
	}
	arg_value = ft_strdup(shell->args[n]);
	return (arg_value);
}

int	write_line(char *line, t_command_list *new, char *del)
{
	if (line != NULL && ft_strncmp(line, del, ft_strlen(del)) == 0
		&& line[ft_strlen(del)] == '\0')
	{
		free(line);
		return (0);
	}
	if (line != NULL)
		write(new->fd_heredoc, line, ft_strlen(line));
	write(new->fd_heredoc, "\n", 1);
	if (line)
		free(line);
	return (1);
}
