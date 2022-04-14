/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:05:27 by arudy             #+#    #+#             */
/*   Updated: 2022/04/14 17:44:18 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_word(t_token_type type)
{
	if (type == WORD || type == DOLLAR
		|| type == IN_DQUOTE || type == IN_QUOTE)
		return (1);
	return (0);
}

void	fill_cmd_data(t_cmd *cmd, int i)
{
	cmd->cmd[i] = NULL;
	cmd->bin_path = NULL;
	cmd->is_builtin = 0;
	cmd->in = 0;
	cmd->out = 0;
	cmd->fork = 0;
	cmd->pipe[0] = 0;
	cmd->pipe[1] = 0;
}

t_cmd	*cmd_lst_last(t_cmd *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	cmd_lst_addback(t_cmd **head, t_cmd *new, t_cmd *prev)
{
	t_cmd	*tmp;

	if (new)
	{
		new->next = NULL;
		new->prev = prev;
		if (*head)
		{
			tmp = cmd_lst_last(*head);
			tmp->next = new;
		}
		else
			*head = new;
	}
}
