/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_whitespaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:49:49 by arudy             #+#    #+#             */
/*   Updated: 2022/05/03 11:48:19 by arudy            ###   ########.fr       */
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

static t_token	*create_data_token(t_token **lst, t_token *new, t_data *data)
{
	int		i;
	char	**dollar_splited;
	t_token	*head_new;

	i = 0;
	head_new = new;
	new->content = ft_strdup((*lst)->content, data);
	new->type = (*lst)->type;
	new->next = NULL;
	*lst = (*lst)->next;
	if (!is_word(new->type))
		return (new);
	while (*lst && is_word((*lst)->type))
	{
		printf("c : %c\n", (*lst)->content[0]);
		if ((*lst)->type == DOLLAR && !ft_is_whitespace((*lst)->content[0]))
		{
			dollar_splited = ft_split((*lst)->content, ' ', data);
			if (dollar_splited[0])
			{
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
		}
		else
			new->content = ft_strjoin(new->content, (*lst)->content, data);
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
