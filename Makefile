# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arudy <arudy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 17:19:21 by arudy             #+#    #+#              #
#    Updated: 2022/03/26 18:54:13 by arudy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${SRCS_MAIN} ${SRCS_PARSING} ${SRCS_LEXER} ${SRCS_LIBFT} ${SRCS_BUILTINS}

SRCS_MAIN = $(addprefix srcs/, main.c free.c init.c)

SRCS_PARSING = $(addprefix srcs/parsing/, get_full_path.c)

SRCS_LEXER = $(addprefix srcs/lexer/, lexer.c first_check.c \
				lexer_utils.c char_to_token.c token_manager.c)

SRCS_LIBFT = $(addprefix srcs/libft/, ft_putstr_fd.c ft_strlen.c \
				ft_strncmp.c ft_substr.c ft_split.c free_strs.c ft_strsjoin.c \
				ft_strdup.c ft_is_whitespace.c ft_strchr.c)

SRCS_BUILTINS = $(addprefix srcs/builtins/, echo.c cd.c env.c export.c pwd.c)

OBJS = ${SRCS:.c=.o}

NAME = minishell

CC = clang

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
