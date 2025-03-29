/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_iterations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:47:44 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/12 20:19:28 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	other_iterations(t_minishell *shell)
{
	infile_management(shell);
	outfile_management(shell, shell->exec->pipe_aux);
}
