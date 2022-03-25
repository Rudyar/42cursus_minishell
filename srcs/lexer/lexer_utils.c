/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:49:07 by arudy             #+#    #+#             */
/*   Updated: 2022/03/25 18:48:54 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*token_lst_last(t_token *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	token_lst_addback(t_token **head, t_token *new)
{
	t_token	*tmp;

	if (new)
	{
		if (*head)
		{
			tmp = token_lst_last(*head);
			tmp->next = new;
		}
		else
			*head = new;
	}
}

void	free_token_lst(t_token **lst)
{
	t_token	*tmp;

	while (*lst)
	{
		tmp = *lst;
		free(tmp->content);
		*lst = (*lst)->next;
		free(tmp);
	}
}

void	print_token_lst(t_token **lst)
{
	while (*lst)
	{
		printf("token : %u | %s\n", (*lst)->type, (*lst)->content);
		lst = &(*lst)->next;
	}
}
