/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:10:48 by gsoteldo          #+#    #+#             */
/*   Updated: 2023/11/14 16:36:48 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

void	ft_printchar(int c, int *total);
void	ft_printstring(char *str, int *total);
void	ft_printinteger(int num, int *total);
void	ft_printpointer(unsigned long long pointer, int *total);
void	ft_printhexa(unsigned int n, char c, int *total);
void	ft_printunsigned(unsigned int n, int *total);
int		ft_printf(const char *string, ...);

#endif
