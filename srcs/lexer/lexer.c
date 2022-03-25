/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:25:20 by arudy             #+#    #+#             */
/*   Updated: 2022/03/25 17:48:02 by arudy            ###   ########.fr       */
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
	while (lst && i < n)
	{
		new->content[i] = (*lst)->content[0];
		i++;
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
	t_token	*tmp;

	head = NULL;
	new = NULL;
	prev = NULL;
	tmp = *lst;
	while (*lst)
	{
		if ((*lst)->type == QUOTE || (*lst)->type == DQUOTE)
		{
			new = manage_quotes(lst, prev);
			token_lst_addback(&head, new);
			prev = new;
		}
		*lst = (*lst)->next;
	}
	// printf("---> %s\n\n", (*lst)->content);
	// while ((*lst)->prev != NULL)
	// {
	// 	(*lst) = (*lst)->prev;
	// }
	// print_token_lst(&tmp);
	// printf("----------------\n\n");
	return (head);
}

t_token	*lexer(char *s)
{
	t_token	*token;
	t_token	*tokens_lst;

	if (check_quotes(s))
		return (NULL);
	tokens_lst = NULL;
	token = char_to_token(s);
	if (!token)
	{
		printf("Can't create token from line\n");
		return (NULL);
	}
	// print_token_lst(&token);
	// printf("----------------\n\n");
	tokens_lst = concat_tokens(&token);
	if (!tokens_lst)
	{
		printf("Can't create tokens from token\n");
		return (NULL);
	}
	// while (token->prev != NULL)
	// {
	// 	token = token->prev;
	// }
	// print_token_lst(&token);
	// printf("----------------\n\n");
	free_token_lst(&token);
	return (tokens_lst);
}
