/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_iteration.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:47:38 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 01:43:18 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	outfile_management(t_minishell *shell, int *pipe)
{
	int	fd_out;

	fd_out = -1;
	if (shell->exec->outfile != NULL)
	{
		if (shell->exec->outfile && shell->exec->output_type == WRITE_OUTFILE)
			fd_out = open(shell->exec->outfile, O_WRONLY | O_CREAT | O_TRUNC, \
				0644);
		else if (shell->exec->outfile \
			&& shell->exec->output_type == APPEND_OUTFILE)
			fd_out = open(shell->exec->outfile, O_WRONLY | O_CREAT | O_APPEND, \
				0644);
		if (dup2(fd_out, STDOUT_FILENO) < 0)
			error_no_cmd(RED "Error\n" END "dup2 failed in STDOUT\n", 1, shell);
		close_fd(&fd_out, "fd_out");
	}
	else
	{
		if (dup2(pipe[WRITE], STDOUT_FILENO) < 0)
			error_no_cmd(RED "Error\n" END "dup2 failed in STDOUT\n", 1, shell);
	}
	close_fd(&pipe[READ], "shell->exec->pipe_father[READ]");
	close_fd(&pipe[WRITE], "shell->exec->pipe_father[WRITE]");
}

void	first_iteration(t_minishell *shell)
{
	if (shell->exec->infile != NULL)
	{
		shell->exec->fd[READ] = open(shell->exec->infile, O_RDONLY);
		if (shell->exec->fd[READ] < 0)
		{
			if (access(shell->exec->infile, F_OK) == -1)
				error_no_cmd(RED "Error\n" END "File not found--\n", 1, shell);
			else if (access(shell->exec->infile, R_OK) == -1)
				error_no_cmd(RED "Error\n" END "Cannot read input\n", 1, shell);
			else
				error_no_cmd(RED "Error\n" END "Error open input\n", 1, shell);
			exit(1);
		}
	}
	else
		shell->exec->fd[READ] = shell->exec->tmp_in;
	if (dup2(shell->exec->fd[READ], STDIN_FILENO) < 0)
		error_no_cmd(RED "Error\n" END "dup2 failed in STDIN\n", 1, shell);
	if (shell->exec->infile != NULL)
		close_fd(&shell->exec->fd[READ], "shell->exec->fd[READ]");
	outfile_management(shell, shell->exec->pipe_father);
}
