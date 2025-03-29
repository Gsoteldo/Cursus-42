/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_iteration.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:47:52 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 22:16:19 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	infile_management(t_minishell *shell)
{
	int	fd_in;

	if (shell->exec->infile)
	{
		fd_in = open(shell->exec->infile, O_RDONLY);
		if (fd_in < 0)
		{
			if (access(shell->exec->infile, F_OK) == -1)
				error_no_cmd(RED "Error\n" END "File not found\n", 1, shell);
			else if (access(shell->exec->infile, R_OK) == -1)
				error_no_cmd(RED "Error\n" END "Cannot read input\n", 1, shell);
			else
				error_no_cmd(RED "Error\n" END "Error open input\n", 1, shell);
		}
		dup2(fd_in, STDIN_FILENO);
		close_fd(&fd_in, "fd_in");
	}
	else
	{
		if (dup2(shell->exec->pipe_father[READ], STDIN_FILENO) == -1)
			error_no_cmd(RED "Error\n" END "dup2 failed in STDIN\n", 1, shell);
	}
	close_fd(&shell->exec->pipe_father[READ], "shell->exec->pipe_father[READ]");
	close_fd(&shell->exec->pipe_father[WRITE], \
		"shell->exec->pipe_father[WRITE]");
}

static void	check_outfile(t_minishell *shell)
{
	if (shell->exec->outfile != NULL)
	{
		if (shell->exec->outfile && shell->exec->output_type == WRITE_OUTFILE)
			shell->exec->fd[WRITE] = open(shell->exec->outfile, \
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (shell->exec->outfile && \
			shell->exec->output_type == APPEND_OUTFILE)
			shell->exec->fd[WRITE] = open(shell->exec->outfile, \
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
		shell->exec->fd[WRITE] = -1;
	if (shell->exec->outfile == NULL && shell->exec->fd[WRITE] < 0)
		shell->exec->fd[WRITE] = shell->exec->tmp_out;
}

void	last_iteration(t_minishell *shell)
{
	check_outfile(shell);
	if (shell->exec->fd[WRITE] < 0)
	{
		if (access(shell->exec->outfile, F_OK) == -1)
			error_no_cmd(RED "Error\n" END "File not found++\n", 1, shell);
		else if (access(shell->exec->outfile, W_OK) == -1)
			error_no_cmd(RED "Error\n" END "Cannot write output\n", 1, shell);
		else
			error_no_cmd(RED "Error\n" END "Error opening output\n", 1, shell);
	}
	if (dup2(shell->exec->fd[WRITE], STDOUT_FILENO) == -1)
		error_no_cmd(RED "Error\n" END "dup2 failed in STDOUT\n", 1, shell);
	close_fd(&shell->exec->fd[WRITE], "shell->exec->fd[WRITE]");
	infile_management(shell);
}
