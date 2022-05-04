# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 17:19:21 by arudy             #+#    #+#              #
#    Updated: 2022/05/04 13:17:00 by lleveque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${SRCS_MAIN} ${SRCS_UTILS} ${SRCS_PARSING} ${SRCS_LEXER} ${SRCS_LIBFT} \
		${SRCS_BUILTINS} ${SRCS_EXEC}

SRCS_MAIN = $(addprefix srcs/, main.c)

SRCS_UTILS = $(addprefix srcs/utils/, free/ft_free.c init.c error.c env.c\
				free/free_strs.c ft_malloc.c free/utils.c prompt.c)

SRCS_PARSING = $(addprefix srcs/parsing/, first_check.c \
				first_check_redir.c parsing.c parsing_utils.c \
				cmd_utils.c scan_dollar.c scan_dollar_utils.c \
				find_bin_path.c scan_tokens_utils.c scan_tokens.c \
				del_whitespaces.c heredoc.c heredoc_utils.c \
				scan_dollar_utils2.c)

SRCS_LEXER = $(addprefix srcs/lexer/, lexer.c lexer_utils.c \
				char_to_token.c token_manager.c)

SRCS_LIBFT = $(addprefix srcs/libft/, ft_putstr_fd.c ft_strlen.c \
				ft_strncmp.c ft_substr.c ft_split.c ft_env_lst.c \
				ft_strdup.c ft_is_whitespace.c ft_strchr.c ft_isalpha.c \
				ft_isdigit.c ft_calloc.c ft_bzero.c ft_nsplit.c ft_strcmp.c \
				ft_strjoin.c ft_strjoin_char.c ft_strcdup.c ft_lstsize.c \
				ft_atoll.c ft_itoa.c ft_atoi.c)

SRCS_BUILTINS = $(addprefix srcs/builtins/, echo.c cd.c env.c export/export.c \
				export/check.c export/utils.c pwd.c unset.c exit.c)

SRCS_EXEC = $(addprefix srcs/exec/, exec.c exec_utils.c exec_return.c loop.c \
				signals.c)

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

rc: fclean all
	${RM} ${OBJS} && clear

r: fclean all
	${RM} ${OBJS}
	valgrind --suppressions=ignoreleak --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --verbose ./${NAME}

.PHONY: all clean fclean re
