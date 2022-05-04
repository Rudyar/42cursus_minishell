/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_whitespaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:49:49 by arudy             #+#    #+#             */
/*   Updated: 2022/05/04 14:29:20 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*token_lst_new(t_token *prev, char *s, t_data *data)
{
	t_token	*new;

	new = ft_malloc(sizeof(t_token), data);
	new->content = ft_strdup(s, data);
	new->prev = prev;
	new->next = NULL;
	new->type = WORD;
	return (new);
}

static t_token	*split_dollar(t_token **lst, t_token *new, t_data *data, int n)
{
	int		i;
	char	**dollar_splited;

	i = 0;
	dollar_splited = ft_split((*lst)->content, ' ', data);
	if (dollar_splited[0])
	{
		if (n == 1)
			new->content = ft_strdup(dollar_splited[0], data);
		else
			new->content = ft_strjoin(new->content, dollar_splited[0], data);
		while (dollar_splited[++i])
		{
			new->next = token_lst_new(new, dollar_splited[i], data);
			new = new->next;
		}
		if ((*lst)->next)
		{
			new->next = token_lst_new(new, NULL, data);
			new = new->next;
		}
	}
	return (new);
}

static t_token	*create_data_token(t_token **lst, t_token *new, t_data *data)
{
	t_token	*head_new;

	head_new = new;
	new->content = ft_strdup((*lst)->content, data);
	new->type = (*lst)->type;
	if ((*lst)->type == DOLLAR)
	{
		new = split_dollar(lst, new, data, 1);
	}
	new->next = NULL;
	*lst = (*lst)->next;
	if (!is_word(new->type))
		return (new);
	while (*lst && is_word((*lst)->type))
	{
		if ((*lst)->type == DOLLAR && !ft_is_whitespace((*lst)->content[0]))
			split_dollar(lst, new, data, 2);
		else
		{
			if ((*lst)->type == DOLLAR)
				new->content = split_whitespaces(new->content, data);
			new->content = ft_strjoin(new->content, (*lst)->content, data);
		}
		*lst = (*lst)->next;
		new->type = WORD;
	}
	return (head_new);
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
