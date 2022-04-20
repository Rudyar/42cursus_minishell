/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:05:27 by arudy             #+#    #+#             */
/*   Updated: 2022/04/20 13:55:20 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	find_cmd_length(t_token *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst && (lst->type == CMD || lst->type == ARG))
			i++;
		lst = lst->next;
	}
	return (i);
}

t_cmd	*fill_cmd_data(t_cmd *cmd)
{
	cmd->in = 0;
	cmd->out = 1;
	cmd->fork = 0;
	cmd->cmd = NULL;
	cmd->pipe[0] = 0;
	cmd->pipe[1] = 0;
	cmd->is_builtin = 0;
	cmd->bin_path = NULL;
	return (cmd);
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
