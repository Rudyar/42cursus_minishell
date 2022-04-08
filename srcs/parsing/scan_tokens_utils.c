/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_tokens_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:21:43 by arudy             #+#    #+#             */
/*   Updated: 2022/04/08 11:33:40 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_redir_sign(t_token_type token)
{
	if (token == HERE_DOC)
		return (1);
	if (token == DGREATER)
		return (1);
	if (token == REDIR_IN)
		return (1);
	if (token == REDIR_OUT)
		return (1);
	return (0);
}

int	scan_redir(t_token *lst)
{
	while (lst)
	{
		if (is_redir_sign(lst->type))
		{
			if (lst->next)
			{
				while (lst && lst->type == WHITE_SPACE)
					lst = lst->next;
				if (lst && is_redir_sign(lst->type))
				{
					ft_putstr_fd("minishell: syntax error near \
unexpected token `", 2);
					ft_putstr_fd(lst->content, 2);
					ft_putstr_fd("'\n", 2);
					return (1);
				}
			}
		}
		if (lst)
			lst = lst->next;
	}
	return (0);
}

// static int	count_nb_cmd(t_token *lst)
// {
// 	int	i;

// 	i = 1;
// 	while (lst)
// 	{
// 		if (lst->type == PIPE)
// 			i++;
// 		lst = lst->next;
// 	}
// 	return (i);
// }

// int	check_tokens(t_data *data)
// {
// 	if (valid_redir(data->tokens))
// 		return (1);
// 	data->nb_cmd = count_nb_cmd(data->tokens);
// 	return (0);
// }

void	check_builtins(t_cmd *lst)
{
	while (lst)
	{
		if (ft_strncmp(lst->cmd[0], "cd", 3) == 0)
			lst->is_builtin = 1;
		else if (ft_strncmp(lst->cmd[0], "pwd", 4) == 0)
			lst->is_builtin = 1;
		else if (ft_strncmp(lst->cmd[0], "echo", 5) == 0)
			lst->is_builtin = 1;
		else if (ft_strncmp(lst->cmd[0], "env", 4) == 0)
			lst->is_builtin = 1;
		else if (ft_strncmp(lst->cmd[0], "export", 7) == 0)
			lst->is_builtin = 1;
		else if (ft_strncmp(lst->cmd[0], "unset", 6) == 0)
			lst->is_builtin = 1;
		else if (ft_strncmp(lst->cmd[0], "exit", 6) == 0)
			lst->is_builtin = 1;
		else
			lst->is_builtin = 0;
		lst = lst->next;
	}
}
