/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:29:22 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 19:29:23 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

//Caso del HOME (~)
char	*home_case(t_minishell *shell, char *cd_split, char *old_pwd, int *code)
{
	char	*home;

	home = ft_get_env(shell, "HOME");
	if (home == NULL)
	{
		print_no_exit("cd: HOME not set", " ");
		(*code) = 1;
		return (NULL);
	}
	cd_split = ft_strjoin(home, cd_split + 1);
	if (!cd_split)
	{
		print_no_exit("cd: HOME not set", " ");
		(*code) = 1;
		return (NULL);
	}
	if (chdir(cd_split) == -1)
	{
		print_no_exit("++cd: no such file or directory: ", cd_split);
		(*code) = 1;
	}
	else
		(*code) = change_pwd(shell, NULL, 1, old_pwd);
	return (cd_split);
}

int	go_to_old_pwd(t_minishell *shell, char *old_pwd)
{
	int		code;
	char	*temp_oldpwd;

	code = 0;
	temp_oldpwd = ft_get_env(shell, "OLDPWD");
	if (temp_oldpwd == NULL)
	{
		print_no_exit("cd: OLDPWD not set", " ");
		code = 1;
	}
	else if (chdir(temp_oldpwd) == -1)
		code = 1;
	else
		code = change_pwd(shell, NULL, 1, old_pwd);
	return (code);
}

int	all_changes(t_minishell *shell, char **cd_splitted)
{
	int	code;

	code = 0;
	if (cd_splitted[1] != NULL)
		code = directory_change(cd_splitted[1], shell);
	else
		code = directory_change(cd_splitted[0], shell);
	return (code);
}

static void	update_env_var(char **envp, char *var, char *value)
{
	int		i;
	char	*temp;

	i = -1;
	while (envp[++i] != NULL)
	{
		if (!ft_strncmp(envp[i], var, ft_strlen(var)))
		{
			temp = ft_strjoin(var, value);
			if (temp == NULL)
				exit(1);
			free(envp[i]);
			envp[i] = temp;
			return ;
		}
	}
}

int	change_pwd(t_minishell *shell, char *path, int flag, char *old_pwd)
{
	int		code;

	code = 0;
	path = getcwd(NULL, 0);
	if (flag == 1)
		update_env_var(shell->envp, "OLDPWD=", old_pwd);
	else
		update_env_var(shell->envp, "PWD", path);
	if (flag == 1)
		code = change_pwd(shell, NULL, 0, old_pwd);
	if (path)
		free(path);
	return (code);
}

// void	change_pwd(t_minishell *shell, char *path, int flag, char *old_pwd)
// {
// 	int		i;
// 	char	*temp;

// 	path = getcwd(NULL, 0);
// 	i = -1;
// 	while (shell->envp[++i] != NULL)
// 	{
// 		if (flag == 1 && shell->envp[i] != NULL
// 			&& !ft_strncmp(shell->envp[i], "OLDPWD", 6))
// 		{
// 			temp = ft_strjoin("OLDPWD=", old_pwd);
// 			free(shell->envp[i]);
// 			shell->envp[i] = temp;
// 		}
// 		if (flag == 0 && shell->envp[i] != NULL
// 			&& !ft_strncmp(shell->envp[i], "PWD", 3))
// 		{
// 			temp = ft_strjoin("PWD=", path);
// 			if (temp == NULL)
// 				exit(1);
// 			free(shell->envp[i]);
// 			shell->envp[i] = temp;
// 		}
// 	}
// 	if (flag == 1)
// 		change_pwd(shell, NULL, 0, old_pwd);
// 	if (path)
// 		free(path);
// 	shell->code = 0;
// }
