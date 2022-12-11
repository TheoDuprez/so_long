/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:06:01 by tduprez           #+#    #+#             */
/*   Updated: 2022/12/09 11:02:42 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlen_after_cariage(const char *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	while (s[i])
	{
		i++;
		j++;
	}
	return (j);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		y;
	char	*str;

	i = 0;
	y = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (free(s1), s1 = NULL, NULL);
		s1[0] = 0;
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str || !s2)
		return (free(s1), s1 = NULL, NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[y])
		str[i++] = s2[y++];
	str[i] = 0;
	return (free(s1), s1 = NULL, str);
}

int	ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	c = (unsigned char)c;
	if (!s || !c)
		return (0);
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
