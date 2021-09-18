/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssobchak <ssobchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:39:38 by ssobchak          #+#    #+#             */
/*   Updated: 2021/04/23 17:20:04 by ssobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_searchnl(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

t_lst	*ft_lstnew(int fd)
{
	t_lst			*lst;

	lst = (t_lst *)malloc(sizeof(t_lst));
	if (!lst)
		return (NULL);
	if (lst)
	{
		lst->fd = fd;
		lst->save = NULL;
		lst->next = NULL;
	}
	return (lst);
}

void	clearfdlst(int fd, t_lst **head)
{
	t_lst			*del;
	t_lst			*pred;

	del = *head;
	pred = NULL;
	while (del)
	{
		if (del->fd == fd)
		{
			if (pred)
				pred->next = del->next;
			else
				*head = del->next;
			free(del->save);
			free(del);
			return ;
		}
		else
			pred = del;
		del = del->next;
	}
}
