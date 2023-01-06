/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:38:48 by tduprez           #+#    #+#             */
/*   Updated: 2022/11/27 15:44:31 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_if_forest(va_list arg, char c)
{
	int	len;

	if (c == 'c')
		return (len = ft_putchar(va_arg(arg, int)));
	else if (c == 's')
		return (len = ft_putstr(va_arg(arg, char *)));
	else if (c == 'p')
		return (len = ft_putmemory((unsigned long)va_arg(arg, void *)));
	else if (c == 'd' || c == 'i')
		return (len = ft_putnbr(va_arg(arg, int)));
	else if (c == 'u')
		return (len = ft_putnbr_unsign(va_arg(arg, unsigned int)));
	else if (c == 'x')
		return (len = ft_putnbr_base(va_arg(arg, int), "abcdef"));
	else if (c == 'X')
		return (len = ft_putnbr_base(va_arg(arg, int), "ABCDEF"));
	else if (c == '%')
		return (len = ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	if (!s || write(1, 0, 0) == -1)
		return (-1);
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%' && ft_check(s[i + 1], "cspdiuxX%%") == 1)
		{
			i++;
			if (s[i] == '\0')
				return (len);
			len += ft_if_forest(arg, s[i]);
		}
		else if (s[i] != '%')
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
