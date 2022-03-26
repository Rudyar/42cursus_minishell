/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:35:41 by arudy             #+#    #+#             */
/*   Updated: 2022/03/26 18:01:22 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	next_quote(char *str, char c, int	*i)
{
	while (str[*i])
	{
		if (str[*i] == c)
			return (0);
		(*i)++;
	}
	return (1);
}

int	check_quotes(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == DQUOTE)
		{
			i++;
			if (next_quote(str, DQUOTE, &i))
				return (ft_putstr_fd("minishell: syntax error \
near unexpected token \"\n", 2), 1);
		}
		if (str[i] == QUOTE)
		{
			i++;
			if (next_quote(str, QUOTE, &i))
				return (ft_putstr_fd("minishell: syntax error \
near unexpected token \'\n", 2), 1);
		}
	}
	return (0);
}

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
		if ((*lst)->next != NULL)
			*lst = (*lst)->next;
	}
	else
	{
		if ((*lst)->next != NULL)
			*lst = (*lst)->next;
		new = copy_tokens(lst, WORD, *prev, find_next_quote(*lst, QUOTE));
		if ((*lst)->next != NULL)
			*lst = (*lst)->next;
	}
	token_lst_addback(head, new);
	*prev = new;
}
