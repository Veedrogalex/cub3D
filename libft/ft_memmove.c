/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssobchak <ssobchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:18:37 by ssobchak          #+#    #+#             */
/*   Updated: 2021/04/23 17:52:22 by ssobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;

	i = 0;
	if (!src && !dst)
		return (dst);
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (dst1 > src1)
	{
		while (i < len--)
			dst1[len - 1] = src1[len - 1];
	}
	else
	{
		while (i++ < len)
			dst1[i] = src1[i];
	}
	return (dst);
}
