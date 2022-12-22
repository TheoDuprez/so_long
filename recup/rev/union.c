/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:20:50 by tduprez           #+#    #+#             */
/*   Updated: 2022/12/15 14:33:58 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_union(char *s1, char *s2)
{
	int asc[128];
	int i = 0;
	while (i < 128)
	{
		asc[i] = 0;
		i++;
	}
	i = 0;
	while (s1 && s1[i])
	{
		if (asc[(int)s1[i]] == 0)
		{
			write(1, &s1[i], 1);
			asc[(int)s1[i]] = 1;
		}
		i++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		if (asc[(int)s2[i]] == 0)
		{
			asc[(int)s2[i]] = 1;
			write(1, &s2[i], 1);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_union(argv[1], argv[2]);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
