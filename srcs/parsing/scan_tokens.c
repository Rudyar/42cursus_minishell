/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:47:16 by arudy             #+#    #+#             */
/*   Updated: 2022/04/18 15:02:38 by arudy            ###   ########.fr       */
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

static int	scan_redir(t_token *lst)
{
	while (lst)
	{
		if (is_redir_sign(lst->type))
		{
			lst = lst->next;
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
		lst = lst->next;
	}
	return (0);
}

int	scan_tokens(t_data *data, t_token *lst)
{
	if (scan_redir(lst))
		return (1);
	if (scan_dollar(data, lst))
		return (1);
	data->tokens = del_whitespaces(&lst, data);
	return (0);
}
