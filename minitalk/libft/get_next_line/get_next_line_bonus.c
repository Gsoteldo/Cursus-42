/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:35:25 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:20:07 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Libera la memoria asignada a buffer y devuelve la concatenación de 
 * buffer y line.
 *
 * @param buffer: El buffer a liberar.
 * @param line: La línea a concatenar con buffer.
 * @return: La concatenación de buffer y line.
 */
static char	*ft_free(char *buffer, char *line)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, line);
	free(buffer);
	return (tmp);
}

/**
 * Lee del archivo hasta encontrar un salto de línea o llegar al 
 * final del archivo.
 * Devuelve el contenido leído.
 *
 * @param fd: El descriptor de archivo del archivo a leer.
 * @param buffer: El buffer donde guardar el contenido leído.
 * @return: El contenido leído del archivo.
 */
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

/**
 * Extrae la primera línea de buffer.
 *
 * @param buffer: El buffer del cual extraer la línea.
 * @return: La primera línea de buffer.
 */
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

/**
 * Extrae el resto de buffer después de la primera línea.
 *
 * @param buffer: El buffer del cual extraer el resto.
 * @return: El resto de buffer después de la primera línea.
 */
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

/**
 * Lee una línea de un archivo abierto en un descriptor de 
 * archivo dado.
 * Devuelve la línea leída.
 *
 * @param fd: El descriptor de archivo del archivo a leer.
 * @return: La línea leída del archivo.
 */
char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer[fd]);
		buffer[fd] = 0;
		return (NULL);
	}
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	return (line);
}
