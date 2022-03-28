/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:10:51 by arudy             #+#    #+#             */
/*   Updated: 2022/03/28 18:58:25 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	find_next_quote(t_token *lst, t_token_type type)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		if (lst->type == type)
			return (i);
		i++;
		lst = lst->next;
	}
	return (i);
}

void	manage_quotes(t_token **lst, t_token **prev, t_token **head)
{
	t_token	*new;

	new = NULL;
	if ((*lst)->type == DQUOTE)
	{
		if ((*lst)->next != NULL)
			*lst = (*lst)->next;
		new = copy_tokens(lst, WORD_IN_DQUOTE, *prev,
				find_next_quote(*lst, DQUOTE));
	}
	else
	{
		if ((*lst)->next != NULL)
			*lst = (*lst)->next;
		new = copy_tokens(lst, WORD, *prev, find_next_quote(*lst, QUOTE));
	}
	token_lst_addback(head, new);
	*prev = new;
}

void	manage_letters(t_token **lst, t_token **prev, t_token **head)
{
	t_token	*new;

	new = NULL;
	new = copy_tokens(lst, WORD, *prev, count_letters(*lst));
	token_lst_addback(head, new);
	*prev = new;
	if ((*lst)->next != NULL)
		*lst = (*lst)->prev;
}

void	manage_redir(t_token **lst, t_token **prev, t_token **head)
{
	t_token	*new;

	new = NULL;
	if ((*lst)->type == REDIR_IN)
	{
		if ((*lst)->next && (*lst)->next->type == REDIR_IN)
			new = copy_tokens(lst, HERE_DOC, *prev, 2);
		else
			new = copy_tokens(lst, REDIR_IN, *prev, 1);
	}
	else
	{
		if ((*lst)->next && (*lst)->next->type == REDIR_OUT)
			new = copy_tokens(lst, DGREATER, *prev, 2);
		else
			new = copy_tokens(lst, REDIR_OUT, *prev, 1);
	}
	token_lst_addback(head, new);
	*prev = new;
	*lst = (*lst)->prev;
}

void	manage_else(t_token **lst, t_token **prev, t_token **head)
{
	int		i;
	t_token	*new;
	t_token	*tmp;

	i = 0 ;
	new = NULL;
	tmp = *lst;
	if (tmp->type == DOLLAR)
	{
		while (tmp != NULL && (tmp->type == DOLLAR || tmp->type == LETTER))
		{
			i++;
			tmp = tmp->next;
		}
		new = copy_tokens(lst, (*lst)->type, *prev, i);
	}
	else
		new = copy_tokens(lst, (*lst)->type, *prev, 1);
	token_lst_addback(head, new);
	*prev = new;
	if ((*lst)->next != NULL)
		*lst = (*lst)->prev;
}
