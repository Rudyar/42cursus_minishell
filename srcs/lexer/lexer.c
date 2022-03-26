/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:25:20 by arudy             #+#    #+#             */
/*   Updated: 2022/03/26 18:55:10 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*copy_tokens(t_token **lst, t_token_type type, t_token *prev, int n)
{
	t_token	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = malloc(sizeof(char) * (n + 1));
	if (!new->content)
		return (NULL);
	while (*lst && i < n)
	{
		new->content[i] = (*lst)->content[0];
		i++;
		if ((*lst)->next != NULL)
			*lst = (*lst)->next;
	}
	new->content[i] = '\0';
	new->type = type;
	new->prev = prev;
	new->next = NULL;
	return (new);
}

static t_token	*concat_tokens(t_token **lst)
{
	t_token	*head;
	t_token	*new;
	t_token	*prev;

	head = NULL;
	new = NULL;
	prev = NULL;
	while (*lst)
	{
		if ((*lst)->type == QUOTE || (*lst)->type == DQUOTE)
			manage_quotes(lst, &prev, &head);
		if ((*lst)->type == LETTER)
		{
			new = copy_tokens(lst, WORD, prev, count_letters(*lst));
			token_lst_addback(&head, new);
			prev = new;
		}
		if ((*lst)->type == REDIR_IN || (*lst)->type == REDIR_OUT)
			manage_redir(lst, &prev, &head);
		*lst = (*lst)->next;
	}
	return (head);
}

t_token	*lexer(char *s)
{
	t_token	*token;
	t_token	*tokens_lst;
	t_token	*tmp;

	if (first_check(s))
		return (NULL);
	tokens_lst = NULL;
	token = char_to_token(s);
	tmp = token;
	if (!token)
	{
		printf("Can't create token from line\n");
		return (NULL);
	}
	tokens_lst = concat_tokens(&token);
	if (!tokens_lst)
	{
		printf("Can't create tokens from token\n");
		free_token_lst(&tmp);
		return (NULL);
	}
	print_token_lst(&tokens_lst);
	free_token_lst(&tmp);
	return (tokens_lst);
}
