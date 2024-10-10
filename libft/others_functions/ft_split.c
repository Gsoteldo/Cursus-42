/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:28:05 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:23:33 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Divide una cadena de texto en subcadenas basándose en un delimitador 
 * específico y retorna un arreglo de punteros a esas subcadenas.
 * Cuenta el número de subcadenas que resultarán al dividir la cadena de 
 * texto por el delimitador utilizando la función numstring.
 * Asigna memoria dinámicamente para un arreglo de punteros a subcadenas.
 * Verifica si la asignación de memoria fue exitosa. Si no fue exitosa, 
 * retorna nula.
 * Divide la cadena de texto en subcadenas y las almacena en el 
 * arreglo de punteros a subcadenas utilizando la función affect.
 * Retorna el arreglo de punteros a subcadenas.
 *
 * @param s: Cadena de texto a dividir.
 * @param c: Delimitador por el cual dividir la cadena de texto.
 * @return: Arreglo de punteros a subcadenas.
 */
static int	numstring(char const *s1, char c)
{
	int	comp;
	int	cles;

	comp = 0;
	cles = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			cles = 0;
		else if (cles == 0)
		{
			cles = 1;
			comp++;
		}
		s1++;
	}
	return (comp);
}

/**
 * Cuenta el número de caracteres en una subcadena.
 * Recorre la cadena de texto y cada vez que encuentra el delimitador, 
 * detiene el conteo y retorna el contador.
 *
 * @param s2: Cadena de texto de la que extraer la subcadena.
 * @param c: Delimitador por el cual dividir la cadena de texto.
 * @param i: Índice inicial de la subcadena.
 * @return: Longitud de la subcadena.
 */
static int	numchar(char const *s2, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		lenght++;
		i++;
	}
	return (lenght);
}

/**
 * Libera la memoria asignada a un arreglo de punteros a subcadenas.
 * Recorre el arreglo y libera cada subcadena, y luego libera el 
 * arreglo en sí.
 *
 * @param dst: Arreglo de punteros a subcadenas.
 * @param j: Índice final del arreglo.
 * @return: Nulo.
 */
static char	**ft_free(char const **dst, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (NULL);
}

/**
 * Divide la cadena de texto en subcadenas y las almacena en un 
 * arreglo de punteros a subcadenas.
 * Recorre la cadena de texto y cada vez que encuentra el 
 * delimitador, crea una nueva subcadena, la almacena en el arreglo 
 * y continúa con la próxima subcadena.
 *
 * @param s: Cadena de texto a dividir.
 * @param dst: Arreglo de punteros a subcadenas.
 * @param c: Delimitador por el cual dividir la cadena de texto.
 * @param l: Número de subcadenas.
 * @return: Arreglo de punteros a subcadenas.
 */
static char	**affect(char const *s, char **dst, char c, int l)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dst[j] = (char *)malloc(sizeof(char) * numchar(s, c, i) + 1);
		if (dst[j] == NULL)
			return (ft_free((char const **)dst, j));
		while (s[i] != '\0' && s[i] != c)
			dst[j][k++] = s[i++];
		dst[j][k] = '\0';
		j++;
	}
	dst[j] = 0;
	return (dst);
}

/**
 * Divide una cadena de texto en subcadenas basándose en un 
 * delimitador específico y retorna un arreglo de punteros a 
 * esas subcadenas.
 * Cuenta el número de subcadenas que resultarán al dividir la 
 * cadena de texto por el delimitador utilizando la función numstring.
 * Asigna memoria dinámicamente para un arreglo de punteros a subcadenas.
 * Verifica si la asignación de memoria fue exitosa. Si no 
 * fue exitosa, retorna nula.
 * Divide la cadena de texto en subcadenas y las almacena 
 * en el arreglo de punteros a subcadenas utilizando la función affect.
 * Retorna el arreglo de punteros a subcadenas.
 *
 * @param s: Cadena de texto a dividir.
 * @param c: Delimitador por el cual dividir la cadena de texto.
 * @return: Arreglo de punteros a subcadenas.
 */
char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		l;

	if (s == NULL)
		return (NULL);
	l = numstring(s, c);
	dst = (char **)malloc(sizeof(char *) * (l + 1));
	if (dst == NULL)
		return (NULL);
	return (affect(s, dst, c, l));
}
