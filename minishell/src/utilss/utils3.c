/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:10:00 by gabo              #+#    #+#             */
/*   Updated: 2025/03/22 17:43:37 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	separators_init(t_minishell *shell)
{
	shell->separators = add_str_double_pointer(shell->separators, "|");
	shell->separators = add_str_double_pointer(shell->separators, "<<");
	shell->separators = add_str_double_pointer(shell->separators, "<");
	shell->separators = add_str_double_pointer(shell->separators, ">>");
	shell->separators = add_str_double_pointer(shell->separators, ">");
}

int	get_separators_type(char *comand)
{
	if (!ft_strncmp(comand, "|", 1))
		return (NEXT_IS_PIPE);
	return (NO_NEXT);
}

int	is_separators(char *comand)
{
	if (get_separators_type(comand) != 0)
		return (1);
	if (!ft_strncmp(comand, "<<", 2) || !ft_strncmp(comand, "<", 1)
		|| !ft_strncmp(comand, ">>", 2) || !ft_strncmp(comand, ">", 1))
		return (2);
	return (0);
}

static void	free_double_null(char **str)
{
	free_double_str(str);
	str = NULL;
}

void	free_all_shell(t_minishell *shell)
{
	if (shell->builtins)
		free_double_null(shell->builtins);
	if (shell->line)
	{
		free(shell->line);
		shell->line = NULL;
	}
	if (shell->envp)
		free_double_null(shell->envp);
	if (shell->path)
		free_double_null(shell->path);
	if (shell->separators)
		free_double_null(shell->separators);
	if (shell->command_list)
	{
		free_command_list(shell);
		shell->command_list = NULL;
	}
	if (shell->exec)
	{
		free(shell->exec);
		shell->exec = NULL;
	}
}

/*
void	print_outfile(t_outfile *outfile)
{
	t_outfile	*tmp;
	int			i;

	i = 0;
	tmp = outfile;
	if (tmp == NULL)
	{
		printf("La lista de outfile está vacía.\n");
		return ;
  }
	while (tmp)
	{
		printf("Outfile %d: %s\n", i, tmp->outfile);
		printf("Type: %d\n", tmp->type);
		tmp = tmp->next;
		i++;
	}
}

void	print_list(t_command_list *command_list)
{
	t_command_list	*tmp;
	int				i;
	int				j;

	if (!command_list)
	{
		printf("La lista está vacía.\n");
		return;
	}
	i = 0;
	tmp = command_list;
	while (tmp)
	{
		j = 0;
		printf("\nNodo %d\n", i);
		if (tmp->command)
			printf("\nComando: %s\n", tmp->command);
		else
			printf("\nComando %d: (null)\n", i);
		if (tmp->args)
			print_str(tmp->args);
		if (tmp->todo_next)
			printf("Next: %d\n", tmp->todo_next);
		if (tmp->infile)
		{
			while (tmp->infile[j])
			{
				printf("Infile: %s\n", tmp->infile[j]);
				j++;
			}
		}
		else
			printf("Infile: (null)\n");
		if (tmp->outfile)
			print_outfile(tmp->outfile);
		if (tmp->heredoc_delimiter)
			printf("Heredoc: %s\n", tmp->heredoc_delimiter);
		else
			printf("Heredoc: (null)\n");
		if (tmp->quotes_type > 0)
			printf("Quotes: %d\n", tmp->quotes_type);
		else
			printf("Quotes: (null)\n");
		tmp = tmp->next;
		i++;
	}
}
*/
