/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssobchak <ssobchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:07:14 by ssobchak          #+#    #+#             */
/*   Updated: 2021/04/23 17:48:40 by ssobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*ch;
	size_t		i;
	size_t		len;

	len = ft_strlen(s1);
	i = 0;
	ch = (char *)malloc((len + 1) * sizeof(char));
	if (!ch)
		return (NULL);
	while (i < len)
	{
		ch[i] = s1[i];
		i++;
	}
	ch[i] = '\0';
	return (ch);
}
