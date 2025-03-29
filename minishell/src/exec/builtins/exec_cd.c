/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:12:51 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 23:24:32 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	dollar_case(char *cd_splitted, t_minishell *cmd)
{
	int		status;
	char	*old_pwd;

	status = 0;
	cd_splitted = ft_get_env(cmd, cd_splitted + 1);
	if (cd_splitted)
	{
		old_pwd = getcwd(NULL, 0);
		if (chdir(cd_splitted) == -1)
		{
			print_no_exit("--cd: no such file or directory: ", cd_splitted);
			status = 1;
		}
		else
		{
			change_pwd(cmd, NULL, 1, old_pwd);
			status = 0;
		}
	}
	return (status);
}

static int	splitted_null(t_minishell *shell)
{
	char	*old_pwd;
	int		code;

	code = 0;
	old_pwd = getcwd(NULL, 0);
	if (ft_get_env(shell, "HOME") == NULL)
	{
		print_no_exit("cd: HOME not set", " ");
		code = 1;
	}
	else if (chdir(ft_get_env(shell, "HOME")) == -1)
	{
		print_no_exit("cd: HOME not set", " ");
		code = 1;
	}
	else if (ft_get_env(shell, "HOME") != NULL)
		code = change_pwd(shell, NULL, 1, old_pwd);
	else
	{
		print_no_exit("cd: HOME not set", " ");
		code = 1;
	}
	if (old_pwd)
		free(old_pwd);
	return (code);
}

int	directory_change(char *cd_splitted, t_minishell *shell)
{
	char	*old_pwd;
	int		code;

	code = 0;
	old_pwd = getcwd(NULL, 0);
	if (cd_splitted == NULL)
		code = splitted_null(shell);
	else if (cd_splitted[0] == '~')
		cd_splitted = home_case(shell, cd_splitted, old_pwd, &code);
	else if ((!ft_strncmp(cd_splitted, "-", 2)) != 0)
		code = go_to_old_pwd(shell, old_pwd);
	else if (ft_strchr(cd_splitted, '$') && ft_strchr(cd_splitted, ' ') == 0)
		code = dollar_case(cd_splitted, shell);
	else if (chdir(cd_splitted) == -1)
	{
		print_no_exit("**cd: no such file or directory: ", cd_splitted);
		code = 1;
	}
	else
		code = change_pwd(shell, NULL, 1, old_pwd);
	if (old_pwd)
		free(old_pwd);
	return (code);
}

void	exec_cd(t_minishell *shell)
{
	char	**cd_splitted;
	int		code;

	cd_splitted = shell->command_list->args;
	if (cd_splitted == NULL || ft_strlen(cd_splitted[0]) > 2)
	{
		print_no_exit("!!cd: no such file or directory: ", cd_splitted[0]);
		code = 1;
	}
	else if (size_array(cd_splitted) > 2)
	{
		print_no_exit("cd: too many arguments", " ");
		code = 1;
	}
	else if (cd_splitted[1] == NULL)
		code = splitted_null(shell);
	else
		code = all_changes(shell, cd_splitted);
	shell->code = code;
}
