/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssobchak <ssobchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:56:49 by ssobchak          #+#    #+#             */
/*   Updated: 2021/04/23 17:50:03 by ssobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nstr(char const *s1, char c)
{
	int	strn;
	int	bloc;

	strn = 0;
	bloc = 0;
	if (!*s1)
		return (0);
	while (*s1)
	{
		if (*s1 == c)
			bloc = 0;
		else if (bloc == 0)
		{
			bloc = 1;
			strn++;
		}
		s1++;
	}
	return (strn);
}

static int	lens(char const *s2, char c, int i)
{
	int	length;

	length = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}

static char	**freee(char const **dst, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (NULL);
}

static char	**array(char const *s, char **dst, char c, int l)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dst[j] = (char *)malloc(sizeof(char) * lens(s, c, i) + 1);
		if (!dst[j])
			return (freee((char const **)dst, j));
		while (s[i] != '\0' && s[i] != c)
			dst[j][k++] = s[i++];
		dst[j][k] = '\0';
		j++;
	}
	dst[j] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		l;

	if (!s)
		return (NULL);
	l = nstr(s, c);
	dst = (char **)malloc(sizeof(char *) * (l + 1));
	if (!dst)
		return (NULL);
	return (array(s, dst, c, l));
}
