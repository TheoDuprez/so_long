/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:45:09 by tduprez           #+#    #+#             */
/*   Updated: 2022/11/22 14:50:10 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nb, char *charset)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count += ft_putnbr_base(nb / 16, charset);
	if (nb % 16 >= 10)
		count += ft_putchar(charset[nb % 16 - 10]);
	else
		count += ft_putchar(nb % 16 + '0');
	return (count);
}
