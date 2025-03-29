/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:14:11 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 22:16:09 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	print_message(char *delimiter)
{
	printf("warning: Este no es el delimitador que estas buscando");
	printf(" (Buscas `%s')\n", delimiter);
}

void	read_from_stdin(t_minishell *shell, char *del, t_command_list *new)
{
	char	*line;

	while (1 && !g_signal)
	{
		line = readline("heredoc> ");
		if (!check_signal(shell, line, new))
			break ;
		if (!line)
		{
			print_message(new->heredoc_delimiter);
			break ;
		}
		if (ft_strncmp(line, del, ft_strlen(del)) == 0
			&& line[ft_strlen(del)] == '\0')
		{
			free(line);
			break ;
		}
		write(shell->command_list->fd_heredoc, line, ft_strlen(line));
		write(shell->command_list->fd_heredoc, "\n", 1);
		free(line);
	}
	free(del);
	if (shell->command_list->fd_heredoc != -1)
		close_fd(&shell->command_list->fd_heredoc, "fd_heredoc");
}

void	read_expansion(t_minishell *shell, char *delimiter, t_command_list *new)
{
	char	*line;
	char	*del;

	del = NULL;
	if (ft_strchr(delimiter, '$'))
		del = process_line_with_expansion(shell, del);
	else
		del = ft_strdup(delimiter);
	while (1 && !g_signal)
	{
		line = readline("heredoc> ");
		if (!check_signal(shell, line, new))
			break ;
		if (!line)
		{
			print_message(new->heredoc_delimiter);
			break ;
		}
		line = process_line_with_expansion(shell, line);
		if (write_line(line, new, del) == 0)
			break ;
	}
	free(del);
	if (new->fd_heredoc != -1)
		close_fd(&new->fd_heredoc, "fd_heredoc");
}

static char	*create_files(t_minishell *shell, t_command_list *new)
{
	char	*file;
	char	*id;

	shell->id_hd++;
	id = ft_itoa(shell->id_hd);
	if (!id)
		return (NULL);
	file = ft_strjoin("temp", id);
	new->fd_heredoc = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (new->fd_heredoc == -1)
	{
		if (access(file, W_OK) == -1)
			error_no_cmd(RED "Error\n" END "Cannot write temp\n", 1, shell);
		else
			error_no_cmd(RED "Error\n" END "Cannot open temp\n", 1, shell);
		exit(1);
	}
	shell->hd_files = add_str_double_pointer(shell->hd_files, file);
	free(id);
	return (file);
}

void	open_here_doc(t_minishell *shell, char *delimiter, t_command_list *new)
{
	char	*del;
	char	first_char;

	del = NULL;
	first_char = delimiter[0];
	signal_heredoc();
	del = create_files(shell, new);
	delimiter = ft_strtrim(delimiter, "\'\"");
	if (first_char == '\'' || first_char == '\"')
		read_from_stdin(shell, delimiter, new);
	else
		read_expansion(shell, delimiter, new);
	if (new->fd_heredoc != -1)
		close_fd(&new->fd_heredoc, "new->fd_heredoc");
	if ((shell->code == 10 || shell->code == 3))
		exit(shell->code);
	if (g_signal)
		shell->code = 130;
	else
	{
		new->infile = add_str_double_pointer(new->infile, del);
		free(del);
	}
	initialize_signals();
}
