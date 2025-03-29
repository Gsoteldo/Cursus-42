/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_variadica.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:51:15 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 21:18:03 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	total_length(int count, va_list args)
{
	size_t	length;
	int		i;

	length = 0;
	i = 0;
	while (i < count)
	{
		length += ft_strlen(va_arg(args, char *));
		i++;
	}
	return (length);
}

char	*ft_strjoin_variadica(int count, ...)
{
	char	*result;
	char	*str;
	va_list	args;
	size_t	total_len;
	size_t	index;

	va_start(args, count);
	index = 0;
	total_len = total_length(count, args);
	va_end(args);
	result = (char *)ft_calloc(total_len + 1, sizeof(char));
	if (!result)
		return (NULL);
	va_start(args, count);
	while ((int)index < count)
	{
		str = va_arg(args, char *);
		while (*str)
			result[index++] = *str++;
	}
	va_end(args);
	result[index] = '\0';
	return (result);
}
