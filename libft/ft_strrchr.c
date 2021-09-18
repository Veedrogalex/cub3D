/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssobchak <ssobchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:37:17 by ssobchak          #+#    #+#             */
/*   Updated: 2020/11/02 17:58:13 by ssobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	symbol;
	char	*str;

	str = (char *)s + ft_strlen(s);
	symbol = (char)c;
	while (*str != symbol)
	{
		if (str == s)
			return (0);
		str--;
	}
	return (str);
}
