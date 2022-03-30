/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:22:46 by arudy             #+#    #+#             */
/*   Updated: 2022/03/30 12:01:08 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>

# include "libft.h"
# include "parsing.h"
# include "builtins.h"
# include "exec.h"
# include "lexer.h"

typedef struct s_history	t_history;
typedef struct s_cmd		t_cmd;
typedef struct s_data		t_data;

// typedef struct s_garbage
// {
// 	void				*ptr;
// 	struct s_garbage	*next;
// }	t_garbage;

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
	int				in;
	int				out;
	pid_t			fork;
	int				pipe[2];
	struct s_cmd	*next;
	struct s_cmd	*prev;
};

struct	s_data
{
	t_history	*history;
	t_env		*env;
	t_cmd		*cmd_lst;
	int			nb_cmd;
	char		*current_path;
};

t_env	*init_env(char **envp);
void	ft_free(t_env *env);

#endif
