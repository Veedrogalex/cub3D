/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssobchak <ssobchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:41:12 by ssobchak          #+#    #+#             */
/*   Updated: 2020/11/05 16:40:59 by ssobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s21;

	s11 = (unsigned char *)s1;
	s21 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s11[i] != '\0')
	{
		if ((s11[i] - s21[i]) == 0 && i != n - 1)
			i++;
		else
			return (s11[i] - s21[i]);
	}
	return (s11[i] - s21[i]);
}
