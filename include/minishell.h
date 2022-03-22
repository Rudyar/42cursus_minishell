/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:22:46 by arudy             #+#    #+#             */
/*   Updated: 2022/03/22 18:57:58 by lleveque         ###   ########.fr       */
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
# include <dirent.h>

# include "libft.h"
# include "parsing.h"
# include "builtins.h"
# include "exec.h"
# include "utils.h"

typedef struct s_history
{
	struct s_history	*prev;
	char				*cmd;
	struct s_history	*next;
}	t_history;

typedef struct s_data
{
	t_history	history;
	char		*current_path;
}	t_data;

#endif
