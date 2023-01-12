/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmemory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:12:17 by tduprez           #+#    #+#             */
/*   Updated: 2022/11/22 16:07:56 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putmemory(unsigned long arg)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_print_memory(arg, "abcdef");
	return (count);
}
