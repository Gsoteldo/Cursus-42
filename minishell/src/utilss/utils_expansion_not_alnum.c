/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_expansion_not_alnum.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:18:34 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 17:52:14 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief En el caso de que estemos en el ultimo caracter de la cadena de
 * caracteres, se añade el caracter a la cadena que estamos construyendo
 * 
 * @param str: La cadena de caracteres que estamos procesando
 * @param j: La posición actual en la cadena de caracteres
 * @param line: La cadena de caracteres que estamos construyendo
 * 
 * @return char*
 */
static char	*case_last_char(char *str, int *j, char *line)
{
	char	*temp;

	temp = NULL;
	if (line != NULL)
		temp = ft_strjoin(line, str + *j);
	else
		temp = ft_strdup(str + *j);
	free(line);
	line = ft_strdup(temp);
	free(temp);
	return (line);
}

/**
 * @brief En el caso de que no sea un caracter alfanumerico, se añade el
 * caracter a la cadena que estamos construyendo. O en el caso de que no haya
 * nada en la linea que estemos contruyendo, se genera una nueva cadena con el
 * caracter
 *
 * @param shell: Estructura principal del programa
 * @param str: La cadena de caracteres que estamos procesando
 * @param j: La posición actual en la cadena de caracteres
 * 
 * @return char*
 */
static char	*case_else(char *str, char *line)
{
	char	*temp;

	temp = NULL;
	if (line != NULL)
		temp = ft_strjoin(line, str);
	else
		temp = ft_strdup(str);
	free(line);
	line = ft_strdup(temp);
	free(temp);
	return (line);
}

/**
 * @brief En el caso de que no sea un caracter alfanumerico, se añade el
 * caracter a la cadena que estamos construyendo. O en el caso de que no haya
 * nada en la linea que estemos contruyendo, se genera una nueva cadena con el
 * caracter
 * 
 * @param shell: Estructura principal del programa
 * @param str: La cadena de caracteres que estamos procesando
 * @param j: La posición actual en la cadena de caracteres
 * 
 * @return char*
 */
char	*case_not_alnum(t_minishell *shell, char *str, int *j, char *line)
{
	char	*temp;
	char	*aux;

	temp = NULL;
	aux = NULL;
	if (str[*j + 1] == '\0')
		line = case_last_char(str, j, line);
	else if (ft_strstr(str + *j + 1, "$") != 0)
	{
		line = ft_substr(str, 0, *j + 1);
		aux = process_line_with_expansion(shell, str + *j + 1);
		if (aux != NULL)
		{
			temp = ft_strjoin(line, aux);
			free(aux);
			free(line);
			line = ft_strdup(temp);
			free(temp);
		}
	}
	else
		line = case_else(str, line);
	return (line);
}
