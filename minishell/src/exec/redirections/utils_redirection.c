/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:40:49 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/03/22 02:14:49 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_lstsize_outfile(t_outfile *lst)
{
	int		i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	add_exec_output(t_minishell *shell, t_outfile *tmp)
{
	while (tmp && tmp->outfile)
	{
		shell->exec->output_redirection = 1;
		shell->exec->outfile = tmp->outfile;
		shell->exec->output_type = tmp->type;
		tmp = tmp->next;
	}
}

void	redirect_dev_null(t_minishell *shell)
{
	int	fd;

	fd = open("/dev/null", O_RDONLY);
	if (fd < 0)
	{
		error_no_cmd(RED "Error\n" END "open failed in /dev/null\n", 1, shell);
		return ;
	}
	if (dup2(fd, STDIN_FILENO) < 0)
		error_no_cmd(RED "Error\n" END "dup2 failed in STDIN\n", 1, shell);
	close_fd(&fd, "fd");
}
