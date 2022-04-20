/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_whitespaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:49:49 by arudy             #+#    #+#             */
/*   Updated: 2022/04/20 11:10:47 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_token	*create_data_token(t_token **lst, t_token *new, t_data *data)
{
	new->content = ft_strdup((*lst)->content, data);
	new->type = (*lst)->type;
	new->next = NULL;
	*lst = (*lst)->next;
	if (!is_word(new->type))
		return (new);
	while (*lst && is_word((*lst)->type))
	{
		new->content = ft_strjoin(new->content, (*lst)->content, data);
		*lst = (*lst)->next;
		new->type = WORD;
	}
	return (new);
}

t_token	*del_whitespaces(t_token **lst, t_data *data)
{
	t_token	*head_lst;
	t_token	*head;
	t_token	*prev;
	t_token	*new;

	head = NULL;
	prev = NULL;
	head_lst = *lst;
	while (*lst)
	{
		new = ft_malloc(sizeof(t_token), data);
		new = create_data_token(lst, new, data);
		new->prev = prev;
		prev = new;
		token_lst_addback(&head, new);
		if (*lst && (*lst)->type == WHITE_SPACE)
			*lst = (*lst)->next;
	}
	*lst = head_lst;
	return (head);
}
