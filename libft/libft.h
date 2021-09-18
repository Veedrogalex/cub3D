/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssobchak <ssobchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:54:24 by ssobchak          #+#    #+#             */
/*   Updated: 2021/04/23 22:16:57 by ssobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_lst
{
	int				fd;
	char			*save;
	struct s_lst	*next;
}					t_lst;

void			clearfdlst(int fd, t_lst **head);
t_lst			*ft_lstnew(int fd);
int				ft_searchnl(char *s);
int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_itoa(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
char			*ft_strdup(const char *s1);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strrchr(const char *s, int c);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
int				ft_atoi(const char *str);
void			ft_bzero(void *str, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int symbol);
int				ft_isascii(int c);
int				ft_isdigit(int i);
int				ft_isprint(int c);
void			*ft_memccpy(void *dst, void *src, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *dest, int c, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);

#endif
