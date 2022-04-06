/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:17:58 by arudy             #+#    #+#             */
/*   Updated: 2022/04/06 15:09:57 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_history	t_history;
typedef struct s_cmd		t_cmd;
typedef struct s_data		t_data;
typedef struct s_env		t_env;
typedef struct s_token		t_token;

typedef enum e_token_type
{
	WORD = 1,
	LETTER = 2,
	DQUOTE = '"',
	QUOTE = '\'',
	PIPE = '|',
	REDIR_IN = '<',
	REDIR_OUT = '>',
	DGREATER = 8,
	HERE_DOC = 9,
	DOLLAR = '$',
	WHITE_SPACE = 10,
	WORD_IN_DQUOTE = 11
}	t_token_type;

struct	s_history
{
	struct s_history	*prev;
	char				*cmd;
	struct s_history	*next;
};

struct	s_cmd
{
	char			**cmd;
	char			*bin_path;
	int				is_builtin;
	int				in;
	int				out;
	int				pipe[2];
	pid_t			fork;
	struct s_cmd	*next;
	struct s_cmd	*prev;
};

struct	s_data
{
	t_history	*history;
	t_env		*env;
	t_cmd		*cmd_lst;
	t_token		*tokens;
	int			nb_cmd;
	char		*current_path;
};

struct	s_env
{
	struct s_env	*prev;
	char			**var;
	struct s_env	*next;
};

struct	s_token
{
	char			*content;
	t_token_type	type;
	struct s_token	*next;
	struct s_token	*prev;
};

#endif
