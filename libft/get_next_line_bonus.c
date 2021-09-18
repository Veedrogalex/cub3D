/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssobchak <ssobchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:36:35 by ssobchak          #+#    #+#             */
/*   Updated: 2021/04/23 18:08:23 by ssobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BSIZE 50

static char	*sf_norm_line(char *str)
{
	int				i;
	int				len;
	char			*line;

	if (!str)
		return (0);
	len = 0;
	i = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*sf_cut_line(char *src)
{
	char			*dst;
	int				i;
	int				lenc;

	if (!src)
		return (0);
	lenc = 0;
	i = 0;
	while (src[lenc] != '\0' && src[lenc] != '\n')
		lenc++;
	if (src[lenc] == '\0')
	{
		free(src);
		return (0);
	}
	dst = (char *)malloc(sizeof(char) * (ft_strlen(src) - lenc + 1));
	if (!dst)
		return (0);
	lenc++;
	while (src[lenc])
		dst[i++] = src[lenc++];
	dst[i] = '\0';
	free(src);
	return (dst);
}

static int	ternfonc(int r)
{
	if (r == 0)
		return (0);
	return (1);
}

static int	sf_read_line(int fd, char **line, char **stat, t_lst **hd)
{
	char			*buffer;
	int				reader;

	buffer = (char *)malloc(sizeof(char) * (BSIZE + 1));
	if (!buffer)
		return (-1);
	reader = 1;
	while ((reader != 0) && (!ft_searchnl(*stat)))
	{
		reader = read(fd, buffer, BSIZE);
		if (reader == -1)
		{
			clearfdlst(fd, hd);
			free(buffer);
			return (-1);
		}
		buffer[reader] = '\0';
		*stat = ft_strjoin(*stat, buffer);
	}
	free(buffer);
	*line = sf_norm_line(*stat);
	*stat = sf_cut_line(*stat);
	if (reader == 0)
		clearfdlst(fd, hd);
	return (ternfonc(reader));
}

int	get_next_line(int fd, char **line)
{
	static t_lst	*head;
	t_lst			*tmp;

	if (fd < 0 || !line)
		return (-1);
	if (head == NULL)
		head = ft_lstnew(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = ft_lstnew(fd);
		tmp = tmp->next;
	}
	return (sf_read_line(tmp->fd, line, &tmp->save, &head));
}
