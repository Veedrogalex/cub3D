/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssobchak <ssobchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:45:07 by ssobchak          #+#    #+#             */
/*   Updated: 2021/04/23 17:47:09 by ssobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char sym, char const *cut)
{
	int	i;

	i = 0;
	if (sym)
	{
		while (cut[i])
		{
			if (sym == cut[i])
				return (1);
			i++;
		}
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	left;
	unsigned int	right;
	char			*ret;

	if (s1[0] == '\0')
		return ((char *)s1);
	left = 0;
	right = ft_strlen(s1) - 1;
	while (ft_check((char)s1[left], set) == 1 && s1[left])
		left++;
	while (ft_check((char)s1[right], set) == 1 && right > left)
		right--;
	ret = (char *)malloc(sizeof(char) * (right - left + 2));
	if (!ret)
		return (NULL);
	i = 0;
	ret[i] = (char)s1[left];
	while (left <= right)
	{
		ret[++i] = (char)s1[++left];
	}
	ret[i] = '\0';
	return (ret);
}
