# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arudy <arudy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 17:19:21 by arudy             #+#    #+#              #
#    Updated: 2022/03/22 11:15:45 by arudy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${SRCS_PARSING} ${SRCS_LIBFT} srcs/main.c

SRCS_PARSING = $(addprefix srcs/parsing/, get_full_path.c)

SRCS_LIBFT = $(addprefix srcs/libft/, ft_putstr_fd.c ft_strlen.c \
				ft_strncmp.c ft_substr.c ft_split.c free_strs.c)

OBJS = ${SRCS:.c=.o}

NAME = minishell

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: ${NAME}

${NAME}:	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -lreadline -o ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
