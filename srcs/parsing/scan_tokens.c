/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:47:16 by arudy             #+#    #+#             */
/*   Updated: 2022/04/19 11:06:38 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	scan_redir(t_token *lst)
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

void	add_type(t_token *lst)
{
	while (lst)
	{
		if (lst && is_word(lst->type))
		{
			lst->type = CMD;
			lst = lst->next;
			while (lst && is_word(lst->type))
			{
				lst->type = ARG;
				lst = lst->next;
			}
		}
		if (lst && is_redir_sign(lst->type))
		{
			lst->next->type = lst->type;
			lst = lst->next;
		}
		if (lst)
			lst = lst->next;
	}
}

int	scan_tokens(t_data *data, t_token *lst)
{
	if (scan_redir(lst))
		return (1);
	if (scan_dollar(data, lst))
		return (1);
	data->tokens = del_whitespaces(&lst, data);
	add_type(data->tokens);
	return (0);
}
