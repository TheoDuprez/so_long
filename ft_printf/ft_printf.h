/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:55:53 by tduprez           #+#    #+#             */
/*   Updated: 2022/11/27 15:29:20 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

int	ft_putnbr(int nb);
int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_printf(const char *s, ...);
int	ft_putnbr_unsign(unsigned int nb);
int	ft_putnbr_base(unsigned int nb, char *charset);
int	ft_putmemory(unsigned long arg);
int	ft_print_memory(unsigned long nb, char *charset);
int	ft_if_forest(va_list arg, char c);

#endif
