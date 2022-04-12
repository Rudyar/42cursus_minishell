/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:25:20 by arudy             #+#    #+#             */
/*   Updated: 2022/04/12 16:58:56 by arudy            ###   ########.fr       */
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

void	manage_whitespaces(t_token **lst, t_token **prev, t_token **head)
{
	t_token	*new;

	new = copy_tokens(lst, WHITE_SPACE, *prev, 1);
	if (!new)
		return ;
	token_lst_addback(head, new);
	*prev = new;
	while (*lst && (*lst)->type == WHITE_SPACE)
		*lst = (*lst)->next;
	*lst = (*lst)->prev;
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
		if ((*lst)->type == WHITE_SPACE)
			manage_whitespaces(lst, &prev, &head);
		if (*lst)
			*lst = (*lst)->next;
	}
	return (head);
}

int	lexer(char *s, t_token **tokens_lst)
{
	t_token	*char_token;
	t_token	*tmp;

	char_token = char_to_token(s);
	if (!char_token)
	{
		ft_putstr_fd("Can't create token from line\n", 2);
		return (1);
	}
	tmp = char_token;
	*tokens_lst = concat_tokens(&char_token);
	if (!tokens_lst)
	{
		ft_putstr_fd("Can't create tokens from token\n", 2);
		free_token_lst(&tmp);
		return (1);
	}
	free_token_lst(&tmp);
	return (0);
}
