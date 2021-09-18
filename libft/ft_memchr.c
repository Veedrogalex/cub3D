/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssobchak <ssobchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:09:33 by ssobchak          #+#    #+#             */
/*   Updated: 2020/11/02 19:30:25 by ssobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	symbol;
	size_t			i;

	i = 0;
	symbol = (unsigned char)c;
	str = (unsigned char *)s;
	while (i != n)
	{
		if (*str == symbol)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}
