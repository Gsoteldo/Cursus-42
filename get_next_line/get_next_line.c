/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:19:26 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/04/05 17:18:01 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char *buffer, char *line)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, line);
	return (tmp);
}

static char	*read_file(int fd, char *buffer)
{
	char	*line;
	int		i;

	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	line = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!line)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, line, BUFFER_SIZE);
		if (i < 0)
		{
			free(line);
			return (NULL);
		}
		line[i] = 0;
		buffer = ft_free(buffer, line);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(line);
	return (buffer);
}

static char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*ft_next(char *buffer)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next = ft_calloc(sizeof(char), (ft_strlen(buffer) - i + 1));
	if (!next)
		return (NULL);
	i++;
	while (buffer[i])
	{
		next[j++] = buffer[i++];
	}
	next[j] = '\0';
	free(buffer);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
