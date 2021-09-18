# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssobchak <ssobchak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 14:45:42 by ssobchak          #+#    #+#              #
#    Updated: 2021/02/15 15:48:53 by ssobchak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isdigit.c ft_memset.c ft_isprint.c ft_strjoin.c\
ft_atoi.c ft_strdup.c ft_memchr.c ft_memcmp.c ft_substr.c\
ft_strlcpy.c ft_tolower.c ft_bzero.c ft_memccpy.c ft_strlen.c\
ft_toupper.c ft_isalnum.c ft_strlcat.c ft_strchr.c ft_strtrim.c\
ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strrchr.c ft_putchar_fd.c\
ft_isascii.c ft_memmove.c ft_strnstr.c ft_calloc.c ft_putstr_fd.c\
ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_strmapi.c ft_itoa.c\
get_next_line_bonus.c get_next_line_utils_bonus.c\

OBJS = ${SRCS:.c=.o}

OBJSBONUS = ${BONUS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

bonus:	${OBJS} ${OBJSBONUS}
		ar rcs ${NAME} ${OBJS} ${OBJSBONUS}

all:	${NAME}

clean:
		${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re