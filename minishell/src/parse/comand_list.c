/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comand_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:54:26 by gabo              #+#    #+#             */
/*   Updated: 2025/03/21 23:58:35 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Libera la memoria de una lista de comandos.
 *
 * Esta función recorre una lista enlazada de estructuras t_command_list y libera
 * toda la memoria asignada para cada nodo, incluyendo los comandos, argumentos,
 * archivos de entrada y el propio nodo.
 *
 * @param command_list Un puntero a la lista de comandos que se va a liberar.
 */
// void	clear_command_list(t_command_list *command_list)
// {
// 	t_command_list	*tmp;

// 	while (command_list)
// 	{
// 		tmp = command_list->next;
// 		free(command_list->command);
// 		free_double_str(command_list->args);
// 		free(command_list->infile);
// 		free(command_list);
// 		command_list = tmp;
// 	}
// }

/**
 * @brief Crea una nueva estructura de t_command_list.
 *
 * Esta función asigna memoria para una nueva estructura de t_command_list,
 * inicializa sus campos a valores predeterminados y devuelve un puntero a la
 * nueva estructura. Si la asignación de memoria falla, devuelve NULL.
 *
 * @return t_command_list* Puntero a la nueva estructura t_command_list, o NULL
 * si la asignación de memoria falla.
 */
static t_command_list	*new_command(void)
{
	t_command_list	*new;

	new = (t_command_list *)ft_calloc(1, sizeof(t_command_list));
	if (!new)
		return (NULL);
	new->command = NULL;
	new->args = NULL;
	new->todo_next = NO_NEXT;
	new->infile = NULL;
	new->outfile = NULL;
	new->next = NULL;
	return (new);
}

/**
 * new_arg - Procesa y agrega nuevos argumentos a la lista de comandos.
 *
 * @args: Doble puntero a una lista de argumentos.
 * @new: Puntero a una estructura t_command_list donde se agregarán
 * los nuevos argumentos.
 *
 * Este función recorre la lista de argumentos y verifica si hay 
 * separadores
 * (>, >>, <, <<). Si encuentra un separador, llama a la función
 * append_redirections para manejar las redirecciones. Si no es un
 * separador, agrega el argumento a la lista de argumentos de la
 * estructura t_command_list.
 *
 * Retorna 1 si se procesaron los argumentos correctamente, o
 * 0 si hubo un error
 * (por ejemplo, si falla la asignación de memoria).
 */
int	new_arg(char ***args, t_command_list *new, t_minishell *shell)
{
	char	**temp;
	char	**old_args;

	temp = *args;
	while (*temp && !get_separators_type(*temp))
	{
		if (ft_strcmp(*temp, ">") == 0 || ft_strcmp(*temp, ">>") == 0
			|| ft_strcmp(*temp, "<") == 0 || ft_strcmp(*temp, "<<") == 0)
		{
			if (!append_redirections(&temp, new, shell))
				return (0);
		}
		else
		{
			old_args = new->args;
			new->args = add_str_double_pointer(new->args, *temp);
			if (old_args)
				free_double_str(old_args);
			if (!new->args)
				error_no_cmd("Error: malloc failed", 1, shell);
			temp++;
		}
	}
	*args = temp;
	return (1);
}

/**
 * @brief Añade un nuevo nodo a la lista de comandos.
 *
 * Esta función añade un nuevo nodo al final de la lista de comandos.
 * Si la lista está vacía, el nuevo nodo se convierte en el primer nodo.
 * Si la lista no está vacía, la función recorre la lista hasta el último nodo
 * y añade el nuevo nodo al final.
 *
 * @param new Puntero al nuevo nodo que se va a añadir.
 * @param shell Puntero a la lista de comandos.
 * @param tmp Puntero temporal utilizado para recorrer la lista.
 */
void	new_node(t_command_list **new, t_command_list **shell, \
t_command_list **tmp)
{
	if (!(*shell))
		*shell = *new;
	else
	{
		*tmp = *shell;
		while ((*tmp)->next)
			*tmp = (*tmp)->next;
		(*tmp)->next = *new;
	}
}

void	error_free(t_command_list *new, t_minishell *shell)
{
	free(new->command);
	free_double_str(new->args);
	free(new);
	free_command_list(shell);
}

/**
 * create_comand_list - Crea una lista de comandos a partir de los argumentos
 * proporcionados.
 * @shell: Puntero a la estructura t_minishell que contiene los argumentos
 * y la lista de comandos.
 *
 * Esta función recorre los argumentos en la estructura t_minishell
 * y crea una lista de comandos. Para cada argumento, se crea un nuevo
 * nodo de comando y se añade a la lista de comandos. Si se encuentra un
 * separador, se actualiza el campo todo_next del nodo de comando.
 * En caso de error al crear un nuevo comando o al duplicar el argumento,
 * la función limpia la lista de comandos y retorna 0.
 * Retorna 1 si la lista de comandos se crea correctamente.
 *
 * Retorno: 1 si la lista de comandos se crea correctamente, 0 en caso de error.
 */
int	create_comand_list(t_minishell *shell)
{
	t_command_list	*new;
	t_command_list	*tmp;
	char			**args;

	args = shell->args;
	while (shell->args && *shell->args && !get_separators_type(*shell->args))
	{
		new = new_command();
		if (!new)
			return (error_free(new, shell), 0);
		new_node(&new, &shell->command_list, &tmp);
		new->command = ft_strdup(*shell->args);
		if (!new->command)
			return (0);
		if (!new_arg(&shell->args, new, shell))
			return (error_free(new, shell), 0);
		if (shell->args && *shell->args)
			new->todo_next = get_separators_type(*shell->args);
		if (is_separators(new->command) && new->args)
			new->command = ft_strdup(new->args[0]);
		clear_quotes(new);
		if (shell->args && *shell->args)
			shell->args++;
	}
	return (free_double_str(args), 1);
}
