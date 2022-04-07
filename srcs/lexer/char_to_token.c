/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:36:57 by arudy             #+#    #+#             */
/*   Updated: 2022/04/07 14:56:16 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_token	*char_to_token_error(t_token **lst)
{
	if (*lst != NULL)
		free_token_lst(lst);
	printf("Can't create new token when reading line\n");
	return (NULL);
}

static t_token	*create_token(char c, t_token_type token_type, t_token *prev)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = malloc(sizeof(char) * 2);
	if (!new->content)
		return (NULL);
	new->content[0] = c;
	new->content[1] = '\0';
	new->type = token_type;
	new->prev = prev;
	new->next = NULL;
	return (new);
}

static t_token	*token_type(char c, t_token *prev)
{
	if (c == DQUOTE)
		return (create_token(c, DQUOTE, prev));
	else if (c == QUOTE)
		return (create_token(c, QUOTE, prev));
	else if (c == REDIR_IN)
		return (create_token(c, REDIR_IN, prev));
	else if (c == REDIR_OUT)
		return (create_token(c, REDIR_OUT, prev));
	else if (c == PIPE)
		return (create_token(c, PIPE, prev));
	else if (c == DOLLAR)
		return (create_token(c, DOLLAR, prev));
	else if (ft_is_whitespace(c))
		return (create_token(c, WHITE_SPACE, prev));
	else
		return (create_token(c, LETTER, prev));
	return (NULL);
}

t_token	*char_to_token(char *s)
{
	t_token	*head;
	t_token	*new;
	t_token	*prev;
	int		i;

	i = 0;
	while (s[i] && ft_is_whitespace(s[i]))
		i++;
	prev = NULL;
	new = token_type(s[i], prev);
	head = new;
	i++;
	while (s[i])
	{
		prev = new;
		new = token_type(s[i], prev);
		if (!new)
			return (char_to_token_error(&head));
		token_lst_addback(&head, new);
		i++;
	}
	return (head);
}
