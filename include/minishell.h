/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:22:46 by arudy             #+#    #+#             */
/*   Updated: 2022/03/28 18:42:37 by lleveque         ###   ########.fr       */
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

typedef struct s_history
{
	struct s_history	*prev;
	char				*cmd;
	struct s_history	*next;
}	t_history;

typedef struct s_garbage
{
	void				*ptr;
	struct s_garbage	*next;
}	t_garbage;

typedef struct s_data
{
	t_history	history;
	t_env		env;
	char		*current_path;
}	t_data;

t_env	*init_env(char **envp);
void	ft_free(t_env *env);

#endif
