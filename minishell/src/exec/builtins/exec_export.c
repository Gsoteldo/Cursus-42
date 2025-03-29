/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:13:33 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/23 00:22:55 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static char	**do_what_export_needs(t_minishell *shell, char *str, char **temp)
{
	char	**envp;
	char	**old_envp;
	int		size;

	envp = NULL;
	size = 0;
	old_envp = NULL;
	if (ft_strstr(str, "="))
		envp = add_array_str(shell, shell->envp, temp, size);
	else
	{
		if (get_whole_env_line(shell, str) == NULL)
		{
			old_envp = shell->envp;
			envp = add_str_double_pointer(shell->envp, str);
			if (old_envp)
				free_double_str(old_envp);
		}
		else
			return (shell->envp);
	}
	return (envp);
}

static void	print_message(char *message)
{
	ft_printf("minishell: export: `%s':", message);
	ft_printf("not a valid identifier\n");
}

static int	export_one_line(t_minishell *shell, int i)
{
	int		status;
	char	**temp;
	char	**args;

	status = 0;
	args = shell->command_list->args;
	temp = ft_split(args[i], '=');
	if (!temp)
		return (status);
	if (is_valid_format(temp, args[i]) == 1)
		shell->envp = do_what_export_needs(shell, args[i], temp);
	else
	{
		print_message(args[i]);
		status = 1;
	}
	if (temp)
	{
		free_double_str(temp);
		temp = NULL;
	}
	return (status);
}

void	exec_export(t_minishell *shell)
{
	int		i;
	int		status;
	char	**args;

	i = 1;
	status = 0;
	args = shell->command_list->args;
	if (size_array(args) == 1 && !ft_strcmp(args[0], "export"))
		exec_word_export_only(shell);
	else
	{
		while (args[i] != NULL)
		{
			status = export_one_line(shell, i);
			if (status == 1)
				break ;
			i++;
		}
	}
	shell->code = status;
}
