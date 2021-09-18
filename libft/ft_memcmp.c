/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssobchak <ssobchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:45:32 by ssobchak          #+#    #+#             */
/*   Updated: 2020/11/02 22:34:43 by ssobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s21;

	s11 = (unsigned char *)s1;
	s21 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((s11[i] - s21[i]) == 0)
			i++;
		else
			return (s11[i] - s21[i]);
	}
	return (0);
}
