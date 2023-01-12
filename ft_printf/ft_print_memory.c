/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:25:58 by tduprez           #+#    #+#             */
/*   Updated: 2022/11/22 14:43:18 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_memory(unsigned long nb, char *charset)
{
	int	count;

	count = 0;
	if (nb > 15)
		count += ft_print_memory(nb / 16, charset);
	if (nb % 16 >= 10)
		count += ft_putchar(charset[nb % 16 - 10]);
	else
		count += ft_putchar(nb % 16 + '0');
	return (count);
}
