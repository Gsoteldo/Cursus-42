/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_config.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:47:19 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/28 22:05:54 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	is_fd_open(int fd, char *name)
{
	struct stat	buf;

	(void)name;
	if (fstat(fd, &buf) == 0)
	{
		return (1);
	}
	return (0);
}

static int	check_exists_and_readable(t_minishell *shell)
{
	char	**infiles;

	infiles = shell->command_list->infile;
	while (infiles && *infiles)
	{
		shell->exec->input = open(*infiles, O_RDONLY);
		is_fd_open(shell->exec->input, "shell->exec->input");
		if (shell->exec->input == -1)
		{
			if (access(*infiles, F_OK) == -1)
				print_no_exit(RED "Error\n" END "File not found", *infiles);
			else if (access(*infiles, W_OK) == -1)
				print_no_exit(RED "Error\n" END "Cannot write input", *infiles);
			else
				print_no_exit(RED "Error\n" END "Error open input", *infiles);
			if (shell->exec->input != -1)
				close_fd(&shell->exec->input, "shell->exec->input");
			return (0);
		}
		infiles++;
	}
	return (1);
}

void	reset_execution(t_minishell *shell)
{
	if (is_fd_open(shell->exec->tmp_in, "shell->exec->tmp_in"))
	{
		if (dup2(shell->exec->tmp_in, 0) < 0)
			printf("Error: dup2 failed\n");
		close_fd(&shell->exec->tmp_in, "shell->exec->tmp_in");
		shell->exec->tmp_in = -1;
	}
	if (is_fd_open(shell->exec->tmp_out, "shell->exec->tmp_out"))
	{
		if (dup2(shell->exec->tmp_out, 1) < 0)
			printf("Error: dup2 failed\n");
		close_fd(&shell->exec->tmp_out, "shell->exec->tmp_out");
		shell->exec->tmp_out = -1;
	}
	if (is_fd_open(shell->exec->input, "shell->exec->input"))
	{
		close_fd(&shell->exec->input, "shell->exec->input");
		shell->exec->input = -1;
	}
	if (is_fd_open(shell->exec->output, "shell->exec->output"))
	{
		close_fd(&shell->exec->output, "shell->exec->output");
		shell->exec->output = -1;
	}
}

void	init_redirections(t_minishell *shell)
{
	if (shell->exec->tmp_in == -1)
		shell->exec->tmp_in = dup(0);
	if (shell->exec->tmp_out == -1)
		shell->exec->tmp_out = dup(1);
	if (shell->command_list->infile)
	{
		if (check_exists_and_readable(shell))
		{
			if (dup2(shell->exec->input, STDIN_FILENO) < 0)
				error_no_cmd(RED "Error\n" END "dup2 failed in STDIN\n", 1, \
					shell);
			if (shell->exec->input != -1)
				close_fd(&shell->exec->input, "shell->exec->input");
		}
		else
		{
			redirect_dev_null(shell);
			return ;
		}
	}
	else
		shell->exec->input = dup(shell->exec->tmp_in);
	if (is_fd_open(shell->exec->input, "shell->exec->input"))
		close_fd(&shell->exec->input, "shell->exec->input");
}

void	handle_redirections(t_minishell *shell, t_command_list *aux)
{
	t_command_list	*list;
	t_outfile		*tmp;
	char			*last_infile;
	int				i;

	last_infile = NULL;
	printf("Entra por aca\n");
	if (aux == NULL)
		list = shell->command_list;
	else
		list = aux;
	tmp = list->outfile;
	while (list)
	{
		i = -1;
		while (list->infile && list->infile[++i])
			last_infile = list->infile[i];
		add_exec_output(shell, tmp);
		list = list->next;
	}
	if (last_infile)
	{
		shell->exec->input_redirection = 1;
		shell->exec->infile = last_infile;
	}
}
