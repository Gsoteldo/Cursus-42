/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:13:52 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 19:27:52 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static char	**check_if_error(t_minishell *shell)
{
	char	**lines_to_unset;
	char	**line;

	line = shell->command_list->args;
	if (size_array(line) == 1)
	{
		ft_printf("unset: not enough arguments\n");
		shell->code = 1;
		return (NULL);
	}
	else if (line[1][0] == '-')
	{
		ft_printf("unset: invalid option -- '%c'\n", line[1][1]);
		ft_printf("unset: usage: unset [name ...]\n");
		shell->code = 1;
		return (NULL);
	}
	lines_to_unset = ft_calloc(size_array(line), sizeof(char *));
	if (!lines_to_unset)
	{
		shell->code = 1;
		return (NULL);
	}
	return (lines_to_unset);
}

static void	each_line(t_minishell *shell, char **lines_to_unset, int i, int *k)
{
	char	*aux;
	char	**line;
	char	**envp;
	int		j;

	j = 0;
	envp = shell->envp;
	line = shell->command_list->args;
	while (envp[j] != NULL)
	{
		aux = ft_substr(envp[j], 0, ft_strchr(envp[j], '=') - envp[j]);
		if (ft_strcmp(aux, line[i]) == 0)
		{
			lines_to_unset[*k] = ft_strdup(envp[j]);
			(*k)++;
		}
		free(aux);
		j++;
	}
}

static char	**find_lines_to_unset(t_minishell *shell)
{
	char	**line;
	char	**lines_to_unset;
	int		i;
	int		k;

	i = 1;
	k = 0;
	line = shell->command_list->args;
	lines_to_unset = check_if_error(shell);
	if (lines_to_unset == NULL)
		return (NULL);
	while (line[i] != NULL)
	{
		each_line(shell, lines_to_unset, i, &k);
		i++;
	}
	lines_to_unset[k] = NULL;
	return (lines_to_unset);
}

void	exec_unset(t_minishell *shell)
{
	char	**line;

	line = NULL;
	if (shell == NULL || shell->command_list->args == NULL)
		return ;
	line = find_lines_to_unset(shell);
	if (line == NULL)
	{
		shell->code = 1;
		return ;
	}
	delete_var_envp(shell, line);
	free_double_str(line);
	shell->code = 0;
}
