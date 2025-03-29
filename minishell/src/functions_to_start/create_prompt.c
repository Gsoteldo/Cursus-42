/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:34:23 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 02:44:22 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_env_static(char **envp)
{
	char	*env;
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "USER=", 5))
		{
			env = ft_strdup(envp[i] + 5);
			return (env);
		}
	}
	return (NULL);
}

static char	*get_line_for_prompt(char **envp)
{
	char	*temp;
	char	*prompt;
	char	*complete_prompt;

	complete_prompt = NULL;
	prompt = NULL;
	if (envp)
	{
		temp = get_env_static(envp);
		if (temp != NULL)
		{
			complete_prompt = ft_strjoin(COLOR_LIGHT_BLUE, temp);
			prompt = ft_strjoin(complete_prompt, COLOR_RESET "@");
			free(complete_prompt);
			free(temp);
		}
		else
			prompt = ft_strdup("");
	}
	else
		prompt = ft_strdup("");
	return (prompt);
}

char	*first_part_prompt(char *prompt, char *aux)
{
	char	*complete_prompt;

	complete_prompt = ft_strjoin(prompt, aux);
	if (complete_prompt == NULL)
	{
		free(prompt);
		free(aux);
		return (NULL);
	}
	free(prompt);
	free(aux);
	prompt = ft_strjoin(complete_prompt, "::");
	if (prompt == NULL)
	{
		free(complete_prompt);
		return (NULL);
	}
	free(complete_prompt);
	return (prompt);
}

char	*second_part_prompt(char *prompt)
{
	char	*complete_prompt;

	complete_prompt = ft_strjoin(prompt, COLOR_ORANGE "minishell bash-bros> ");
	if (complete_prompt == NULL)
	{
		free(prompt);
		return (NULL);
	}
	free(prompt);
	prompt = ft_strjoin(complete_prompt, COLOR_RESET);
	if (prompt == NULL)
	{
		free(complete_prompt);
		return (NULL);
	}
	free(complete_prompt);
	return (prompt);
}

char	*create_prompt(char *pwd_line, char **envp)
{
	char	*prompt;
	char	*aux;

	aux = NULL;
	prompt = NULL;
	prompt = get_line_for_prompt(envp);
	aux = ft_strjoin(COLOR_GREEN, pwd_line);
	if (aux == NULL)
	{
		free(prompt);
		return (NULL);
	}
	prompt = first_part_prompt(prompt, aux);
	prompt = second_part_prompt(prompt);
	return (prompt);
}
