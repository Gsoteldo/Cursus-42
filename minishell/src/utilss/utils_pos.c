/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:29:10 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/21 14:40:49 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief: Un string en el alfabeto y devuelve su índice.
 *
 * La función recorre el array de strings `alphabet` para encontrar
 * la primera coincidencia con el string `str`. Si se encuentra una
 * coincidencia, devuelve el índice de la posición correspondiente
 * en el array.
 * Si el string es un espacio `" "`, devuelve 0 inmediatamente.
 * Si no encuentra coincidencia, retorna `NOT_OPERATOR`, que indica
 * que el string no pertenece al conjunto de operadores válidos.
 *
 * @alphabet: Array de strings donde se busca el string.
 * @str: String que se desea buscar en el alfabeto.
 *
 * @return: El índice del string en el array `alphabet` o `NOT_OPERATOR`
 * si no se encuentra.
 */
int	idstr(char **alphabet, char *str)
{
	int	i;

	i = -1;
	if (!alphabet || !str)
		return (-1);
	if (ft_strcmp(str, " ") == 0)
		return (0);
	while (alphabet[++i])
	{
		if (ft_strcmp(alphabet[i], str) == 0)
			return (i);
	}
	return (14);
}

/**
 * Busca la posición de un carácter en una cadena, comenzando desde una posición
 * dada.
 *
 * @param str La cadena en la que se realizará la búsqueda.
 * @param chr El carácter que se desea encontrar.
 * @param start La posición desde donde se comenzará la búsqueda.
 * @return La posición del carácter en la cadena, o -1 si no se encuentra o los
 * parámetros son inválidos.
 */
int	ft_chrpos(char *str, int chr, int start)
{
	int	i;
	int	len;

	len = (int)ft_strlen(str);
	if (!str || chr < 0 || start < 0)
		return (-1);
	i = start - 1;
	while (++i < len && str[i])
		if (str[i] == chr)
			return (i);
	return (-1);
}

/**
 * Función que busca un carácter en un arreglo de cadenas de caracteres.
 *
 * @param alphabet Arreglo de cadenas de caracteres.
 * @param c Carácter a buscar.
 * @return El índice del carácter en el arreglo si se encuentra, -1
 * si no se encuentra.
 */
int	idx(char **alphabet, char c)
{
	int	i;

	i = -1;
	while (alphabet[++i])
	{
		if (ft_chrpos(alphabet[i], c, 0) != -1)
			return (i);
	}
	return (i);
}

/**
 * index_of - Encuentra el índice de la n-ésima aparición de una subcadena
 * en una cadena.
 * @str: La cadena en la que se buscará.
 * @search: La subcadena que se buscará dentro de la cadena principal.
 * @n: El número de la aparición que se desea encontrar (1 para la primera,
 * 2 para la segunda, etc.).
 *
 * Devuelve el índice de la n-ésima aparición de la subcadena en la cadena
 * principal.
 * Si la subcadena no se encuentra n veces, devuelve el índice del final de
 * la cadena.
 */
int	index_of(char *str, char *search, int n)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strncmp(&str[i], search, ft_strlen(search)) == 0)
			n--;
		if (n <= 0)
			return (i);
		i++;
	}
	return (i);
}

/**
 * index_newline
 * @brief Encuentra el índice de la primera aparición de un espacio o
 * tabulación en una cadena de texto.
 *
 * Esta función busca el índice del primer espacio o tabulación en la
 * cadena de texto proporcionada.
 * Si la cadena comienza con una tabulación, se considera el índice de
 * la tabulación.
 *
 * @param str La cadena de texto en la que se buscará el espacio o tabulación.
 * @return El índice del primer espacio o tabulación encontrado en la cadena de 
 * texto.
 */
int	index_newline(char *str)
{
	int	space_index;
	int	tab_index;

	space_index = index_of(str, " ", 1);
	tab_index = index_of(str, "\t", 1);
	if (tab_index || str[0] == '\t')
	{
		if (tab_index < space_index)
			space_index = tab_index;
	}
	return (space_index);
}
