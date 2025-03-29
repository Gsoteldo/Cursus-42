/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:42:38 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 17:43:18 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_get_env(t_minishell *shell, char *str)
{
	int	i;

	i = -1;
	while (shell->envp[++i])
	{
		if (ft_strncmp(shell->envp[i], str, ft_strlen(str)) == 0)
		{
			if (shell->envp[i][ft_strlen(str)] == '=')
				return (shell->envp[i] + ft_strlen(str) + 1);
		}
	}
	return (NULL);
}

static void	free_aux(char **aux)
{
	if (*aux)
	{
		free(*aux);
		*aux = NULL;
	}
}

char	*get_whole_env_line(t_minishell *shell, char *str)
{
	int		i;
	char	*equal;
	char	*aux;

	i = -1;
	while (shell->envp[++i])
	{
		equal = ft_strchr(shell->envp[i], '=');
		if (equal)
		{
			aux = ft_substr(shell->envp[i], 0, equal - shell->envp[i]);
			if (!aux)
				return (NULL);
			if (ft_strcmp(aux, str) == 0)
			{
				free(aux);
				return (shell->envp[i]);
			}
			free_aux(&aux);
		}
		else if (ft_strcmp(shell->envp[i], str) == 0)
			return (shell->envp[i]);
	}
	free_aux(&aux);
	return (NULL);
}

void	print_header(t_minishell *shell)
{
	if (size_array(shell->envp) > 3)
	{
		ft_printf("███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     \
██╗     \n");
		ft_printf("████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     \
██║     \n");
		ft_printf("██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     \
██║     \n");
		ft_printf("██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     \
██║     \n");
		ft_printf("██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗\
███████╗\n");
		ft_printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝\
╚══════╝\n");
	}
	else if (size_array(shell->envp) < 3)
	{
		ft_printf("███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     \
██╗     \n");
		ft_printf("████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     \
██║     \n");
		ft_printf("██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     \
██║     SIN ENTORNO\n");
		ft_printf("██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     \
██║     \n");
		ft_printf("██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗\
███████╗\n");
		ft_printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝\
╚══════╝\n");
	}
}

int	is_not_all_whitespaces(char *command)
{
	int	i;

	if (!command)
		return (0);
	i = 0;
	if (command[0] == '\0')
		return (0);
	while (command[i] != '\0')
	{
		if (command[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
