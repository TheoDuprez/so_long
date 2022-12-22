/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prime2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:24:27 by tduprez           #+#    #+#             */
/*   Updated: 2022/12/15 11:34:24 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int nb;

	nb = n;
	if (n < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

int	ft_prime(int n)
{
	int x;

	x = 2;
	if (n == 1)
		return (0);
	if (n == 2)
		return (1);
	while (x < n / x && n % x)
		x++;
	if (n % x)
		return (1);
	return (0);
}

void	ft_primer(int n)
{
	int x;

	x = 2;
	if (n == 0 || n == 1 || ft_prime(n))
	{
		ft_putnbr(n);
		return ;
	}
	while (1)
	{
		if (ft_prime(x) && !(n % x))
		{
			n = n / x;
			ft_putnbr(n);
			ft_putchar(' ');
			ft_putchar('x');
			ft_putchar(' ');
			if (ft_prime(n))
			{
				ft_putnbr(x);
				return ;
			}
			x--;
		}
		x++;
	}
}

int main(void)
{
	ft_primer(6466);
}
