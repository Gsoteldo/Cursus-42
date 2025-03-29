/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:30:42 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 22:19:27 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Obtiene la lista de rutas de acceso del entorno.
 *
 * La función `get_path` busca la variable de entorno `PATH` en el array de
 * strings `envp` y devuelve un array de strings que contiene las rutas de
 * acceso separadas por `:`. Si la variable de entorno `PATH` no está presente,
 * la función devuelve NULL.
 *
 * @param envp: Un puntero a un array de strings que contiene las variables de
 * entorno.
 * @return Un array de strings que contiene las rutas de acceso, o NULL si no se
 * encuentra la variable de entorno `PATH`.
 */
char	**get_path(char **envp)
{
	int		i;
	char	**str;

	i = 0;
	str = NULL;
	if (envp == NULL)
		return (NULL);
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			str = ft_split(envp[i] + 5, ':');
			if (str == NULL)
				return (NULL);
			return (str);
		}
		i++;
	}
	return (NULL);
}

/**
 * Busca un comando en las rutas de acceso.
 *
 * La función `search_path` busca un comando en las rutas de acceso del entorno.
 * Si el comando se encuentra en alguna de las rutas de acceso, la función
 * devuelve la ruta completa del comando. Si el comando no se encuentra en las
 * rutas de acceso, la función devuelve el nombre del comando sin la ruta.
 *
 * @param shell: Un puntero a una estructura `t_minishell` que contiene las
 * rutas de acceso.
 * @param cmd_splitted: Un array de strings que contiene el comando y sus
 * argumentos.
 * @return La ruta completa del comando si se encuentra en las rutas de acceso,
 * o el nombre del comando si no se encuentra.
 */
char	*search_path(t_minishell *shell, char **cmd_splitted)
{
	char	*line;
	char	*path_slash;
	int		i;

	i = 0;
	if (shell->path == NULL)
		return (NULL);
	while (shell->path[i] != NULL)
	{
		path_slash = ft_strjoin(shell->path[i], "/");
		if (path_slash == NULL)
			print_error(RED "Error\n" END "Malloc failed\n", NULL, 1);
		line = ft_strjoin(path_slash, cmd_splitted[0]);
		if (line == NULL)
			print_error(RED "Error\n" END "Malloc failed\n", NULL, 1);
		free(path_slash);
		if (access(line, F_OK | X_OK) == 0)
			return (line);
		free(line);
		i++;
	}
	return (cmd_splitted[0]);
}

char	**obtain_env_to_envp_array(char **envp)
{
	char	**new_envp;
	int		i;
	int		count;

	i = 0;
	count = 0;
	new_envp = NULL;
	if (envp == NULL || envp[0] == NULL)
		return (NULL);
	count = size_array(envp);
	new_envp = (char **)ft_calloc((count + 1), sizeof(char *));
	if (new_envp == NULL)
		return (NULL);
	while (envp[i] != NULL)
	{
		new_envp[i] = ft_strdup(envp[i]);
		if (new_envp[i] == NULL)
		{
			free_double_str(new_envp);
			return (NULL);
		}
		i++;
	}
	new_envp[i] = NULL;
	return (new_envp);
}

void	check_if_path_removed(t_minishell *shell)
{
	char	*pwd;

	pwd = getenv("PWD");
	if (pwd == NULL)
	{
		shell->path = NULL;
		return ;
	}
	else
	{
		if (shell->path)
			free_double_str(shell->path);
		shell->path = get_path(shell->envp);
		if (shell->path == NULL)
			return ;
	}
}
