/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssobchak <ssobchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:09:02 by ssobchak          #+#    #+#             */
/*   Updated: 2020/11/02 17:33:45 by ssobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	symbol;
	char	*str;

	str = (char *)s;
	symbol = (char)c;
	while (*str != symbol)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}
