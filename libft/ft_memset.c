/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssobchak <ssobchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:08:27 by ssobchak          #+#    #+#             */
/*   Updated: 2021/04/23 17:50:31 by ssobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*dest1;
	unsigned char	symbol;

	dest1 = (unsigned char *)dest;
	symbol = (unsigned char)c;
	while (n > 0)
	{
		*dest1 = symbol;
		dest1++;
		n--;
	}
	return (dest);
}
