/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:25:20 by arudy             #+#    #+#             */
/*   Updated: 2022/04/02 19:19:21 by lleveque         ###   ########.fr       */
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
	t_token	*prev;

	head = NULL;
	prev = NULL;
	while (*lst)
	{
		if ((*lst)->type == QUOTE || (*lst)->type == DQUOTE)
			manage_quotes(lst, &prev, &head);
		if ((*lst)->type == LETTER)
			manage_letters(lst, &prev, &head);
		if ((*lst)->type == REDIR_IN || (*lst)->type == REDIR_OUT)
			manage_redir(lst, &prev, &head);
		if ((*lst)->type == PIPE || (*lst)->type == DOLLAR)
			manage_else(lst, &prev, &head);
		*lst = (*lst)->next;
	}
	return (head);
}

int	lexer(char *s, t_token **tokens_lst)
{
	t_token	*token;
	t_token	*tmp;

	token = char_to_token(s);
	tmp = token;
	if (!token)
	{
		ft_putstr_fd("Can't create token from line\n", 2);
		return (1);
	}
	*tokens_lst = concat_tokens(&token);
	if (!tokens_lst)
	{
		ft_putstr_fd("Can't create tokens from token\n", 2);
		free_token_lst(&tmp);
		return (1);
	}
	free_token_lst(&tmp);
	return (0);
}
