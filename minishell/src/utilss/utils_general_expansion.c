/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general_expansion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:18:52 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/23 00:01:10 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*free_and_reserve(char *line, char *temp, char **aux)
{
	char	*str;

	if (temp == NULL)
	{
		free(*aux);
		free(temp);
		return (NULL);
	}
	str = ft_strdup(temp);
	if (str == NULL)
	{
		free(temp);
		free(*aux);
		return (NULL);
	}
	free(line);
	free(temp);
	free(*aux);
	return (str);
}

static char	*else_case(t_minishell *shell, char *str, int *j, char *line)
{
	int		i;
	char	*temp;
	char	*aux;

	aux = NULL;
	i = *j + 1;
	if (ft_strstr(str + *j + 1, "$") != 0)
	{
		while (str[i] != '\0' && str[i] != '$')
			i++;
		aux = process_line_with_expansion(shell, str + i);
		if (aux != NULL)
		{
			if (line != NULL)
				temp = ft_strjoin(line, aux);
			else
				temp = ft_strdup(aux);
			line = free_and_reserve(line, temp, &aux);
		}
		else
			line = ft_strdup("");
	}
	else
		line = ft_strdup("");
	return (line);
}

static char	*case_is_digit(t_minishell *shell, char *str, int *j)
{
	char	*line;
	int		i;

	i = *j + 1;
	while (ft_isdigit(str[i + 1]) && str[i + 1] != '\0')
		i++;
	if (str[i + 1] == '\0')
		line = ft_strdup("");
	else
	{
		if (ft_strstr(str + *j + 1, "$") != 0)
			line = process_line_with_expansion(shell, str + i + 1);
		else
			line = ft_strdup("");
	}
	return (line);
}

/**
 * expansion_heredoc - Expande variables y parámetros en una cadena heredoc.
 *
 * @shell: Puntero a la estructura principal del programa (t_minishell).
 * @j: Puntero al índice actual en la cadena que se está procesando.
 * @str: Cadena de entrada que contiene las variables o parámetros a expandir.
 *
 * Esta función realiza la expansión de variables y parámetros en una cadena 
 * heredoc.
 * Soporta las siguientes expansiones:
 * - $? : Expande al código de salida del último comando ejecutado.
 * - $$ : Expande al PID del proceso actual.
 * - $n : Expande al argumento n (donde n es un dígito).
 * - Variables de entorno: Expande variables definidas en el entorno.
 * - Caracteres no alfanuméricos: Maneja casos especiales donde el carácter 
 *   siguiente a '$' no es alfanumérico, '_', o el final de la cadena.
 *
 * La función también maneja casos complejos como:
 * - Expansión anidada de variables.
 * - Concatenación de resultados de expansión con el resto de la cadena.
 * - Manejo de caracteres especiales como comillas dobles.
 *
 * Retorna una nueva cadena con las expansiones realizadas. Si no se encuentra
 * una variable o parámetro válido, retorna una cadena vacía.
 *
 * Nota: La memoria asignada dinámicamente dentro de esta función debe ser
 * liberada por el llamador para evitar fugas de memoria.
 */
char	*expansion_heredoc(t_minishell *shell, int *j, char *str)
{
	char	*line;
	char	*aux;

	line = NULL;
	shell->exec->var_not_found = 0;
	aux = get_variable(str + *j);
	if (aux == NULL)
		return (NULL);
	if (str[*j + 1] == '?')
		line = ft_itoa(shell->code);
	else if (str[*j + 1] == '$')
		line = expansion_pid(shell, j, str);
	else if (ft_isdigit(str[*j + 1]))
		line = case_is_digit(shell, str, j);
	else if (!ft_isalnum(str[*j + 1]) && str[*j + 1] != '_')
		line = case_not_alnum(shell, str, j, line);
	else if (is_in_env(aux, shell) == 1)
		line = env(shell, j, str);
	else
		line = else_case(shell, str, j, line);
	if (aux != NULL)
		free(aux);
	return (line);
}
