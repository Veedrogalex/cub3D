/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssobchak <ssobchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 22:37:00 by ssobchak          #+#    #+#             */
/*   Updated: 2021/04/23 17:48:17 by ssobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ret;
	size_t			l1;
	size_t			l2;
	size_t			i;
	size_t			j;

	j = 0;
	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!ret)
		return (NULL);
	while (l1--)
	{
		ret[i] = s1[i];
		i++;
	}
	while (l2--)
		ret[i++] = s2[j++];
	ret[i] = '\0';
	free((void *)s1);
	return (ret);
}
