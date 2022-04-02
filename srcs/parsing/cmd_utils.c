/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:05:27 by arudy             #+#    #+#             */
/*   Updated: 2022/04/02 12:25:42 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_cmd	*cmd_lst_last(t_cmd *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	cmd_lst_addback(t_cmd **head, t_cmd *new)
{
	t_cmd	*tmp;

	if (new)
	{
		if (*head)
		{
			tmp = cmd_lst_last(*head);
			tmp->next = new;
		}
		else
			*head = new;
	}
}
