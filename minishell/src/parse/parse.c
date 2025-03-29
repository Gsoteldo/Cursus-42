/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:35:01 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/03/22 21:42:47 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Obtiene el índice de finalización de un comando en una cadena.
 *
 * Esta función busca el índice de finalización de un comando en la cadena 
 * proporcionada, considerando varios delimitadores de comandos como "&&", "&", 
 * "||", "|", "<<", "<", ">>", ">", y ";". Si encuentra uno de estos
 * delimitadores antes del final de la línea, devuelve el índice correspondiente.
 *
 * @param comand La cadena que contiene el comando a analizar.
 * @param end El índice inicial desde donde comenzar la búsqueda.
 * @return El índice de finalización del comando en la cadena.
 */
int	end_args(char *comand, int end)
{
	int		i;
	int		end_index;
	int		temp;
	char	**splitted;

	i = 0;
	end_index = 0;
	splitted = ft_split("| << < >> >", ' ');
	if (splitted == NULL)
		return (0);
	end_index = index_newline(comand + end);
	while (splitted[i])
	{
		temp = index_of(comand + end, splitted[i], 1);
		if (temp < end_index)
		{
			free_double_str(splitted);
			return (temp + end);
		}
		i++;
	}
	free_double_str(splitted);
	return (end_index + end);
}

/**
 * Función: end_comand
 * -------------------
 * Determina el índice donde finaliza un comando en una cadena dada, 
 * considerando operadores y comillas.
 *
 * @param comand Cadena de caracteres que representa el comando completo.
 * @param end Índice a partir del cual se debe buscar el final del comando.
 * @return El índice donde termina el comando o un valor especial si se 
 * encuentra un operador o cierre de comillas.
 */
int	end_comand(char *comand, int end)
{
	int		i;
	int		end_index;
	char	**splitted;
	int		temp;

	i = -1;
	splitted = ft_split("| << < >> >", ' ');
	end_index = get_close_quote(comand, end);
	if (end_index == 0 || end_index != -2)
		return (free_double_str(splitted), end_index);
	while (splitted[++i])
	{
		if (end > -1 && index_of(comand, splitted[i], 1) < end)
		{
			temp = index_of(comand, splitted[i], 1);
			return (free_double_str(splitted), temp);
		}
		if (index_of(comand, splitted[i], 1) == 0)
		{
			temp = ft_strlen(splitted[i]);
			return (free_double_str(splitted), temp);
		}
	}
	return (free_double_str(splitted), end);
}

/**
 * @brief Divide la línea de comando en argumentos separados y los
 * almacena en shell->args.
 *
 * Esta función procesa la línea de comando almacenada en `shell->line`,
 * ignorando espacios y tabulaciones, y separa los comandos y argumentos
 * utilizando los separadores definidos. Luego, agrega cada comando separado
 * al arreglo `shell->args`.
 *
 * @param shell Puntero a la estructura `t_minishell` que contiene la línea 
 * de comando y los argumentos.
 * @return Devuelve `1` si el proceso de división se realiza correctamente,
 * o `0` si ocurre un error.
 */
int	splitting_comand(t_minishell *shell)
{
	int		i;
	int		end;
	char	*comand;

	i = -1;
	shell->args = NULL;
	comand = NULL;
	while (shell->line[++i])
	{
		if (shell->line[i] == ' ' || shell->line[i] == '\t')
			continue ;
		end = find_end(shell->line, &i);
		if (!end)
			return (0);
		comand = ft_strndup(shell->line + i, end);
		if (!comand)
			return (free_error_splitting(shell, comand), 0);
		adding_double_args(shell, comand);
		if (!shell->args)
			return (free_error_splitting(shell, comand), 0);
		i += ft_strlen(comand) - 1;
		free(comand);
	}
	return (1);
}

/**
 * check_separators - Verifica la presencia de separadores consecutivos en
 * los argumentos.
 * @shell: Puntero a la estructura t_minishell que contiene los argumentos.
 *
 * Esta función recorre los argumentos proporcionados en la estructura 
 * t_minishell y verifica si hay separadores consecutivos. Si se encuentra
 * un separador seguido de otro separador, se imprime un mensaje de error
 * de sintaxis y se libera la memoria asignada a los argumentos. También
 * verifica si el último argumento es un separador, en cuyo caso también
 * se imprime un mensaje de error de sintaxis.
 *
 * Return: 1 si no hay errores de sintaxis, 0 en caso contrario.
 */
int	check_separators(t_minishell *shell)
{
	int	i;
	int	current_type;
	int	next_type;	

	i = -1;
	while (shell->args[++i])
	{
		current_type = is_separators(shell->args[i]);
		if (shell->args[i + 1] != NULL)
			next_type = is_separators(shell->args[i + 1]);
		else
			next_type = 0;
		if (current_type && next_type)
		{
			if ((current_type == 1 && next_type == 1) || current_type == 2)
			{
				printf("Error: syntax error near token `%s'\n", shell->args[i]);
				return (free_double_str(shell->args), 0);
			}
		}
		if (shell->args[i + 1] == NULL && current_type)
			return (printf("--Error: syntax error near token `%s'\n", \
				shell->args[i]), 0);
	}
	return (1);
}

/**
 * @brief Parsea la línea de comandos del minishell y genera una lista de
 * comandos.
 *
 * Esta función realiza varias operaciones de parsing en la línea de comandos
 * almacenada en el objeto `t_minishell`. Primero, inicializa los campos `args`
 * y `command_list` del objeto `t_minishell` a NULL. Luego, realiza las 
 * siguientes verificaciones y operaciones en orden:
 * 
 * 1. Verifica que las comillas en la línea de comandos estén balanceadas.
 * 2. Divide la línea de comandos en argumentos individuales.
 * 3. Verifica los separadores en la línea de comandos.
 * 4. Crea una lista de comandos a partir de los argumentos.
 * 
 * Si alguna de estas operaciones falla, la función retorna NULL. Si todas las
 * operaciones son exitosas, retorna la lista de comandos generada.
 *
 * @param shell Puntero al objeto `t_minishell` que contiene la línea de
 * comandos a parsear.
 * @return t_command_list* Puntero a la lista de comandos generada, o
 * NULL si alguna operación falla.
 */
t_command_list	*parsing(t_minishell *shell)
{
	if (shell->command_list)
	{
		free_command_list(shell);
		shell->command_list = NULL;
	}
	shell->command_list = NULL;
	shell->args = NULL;
	if (!checking_quotes(shell->line))
		return (NULL);
	if (!splitting_comand(shell))
		return (NULL);
	if (!check_separators(shell))
		return (NULL);
	if (!create_comand_list(shell))
	{
		free_double_str(shell->args);
		shell->args = NULL;
		return (NULL);
	}
	if (shell->command_list == NULL)
		return (NULL);
	return (shell->command_list);
}
