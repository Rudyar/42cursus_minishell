/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:35:41 by arudy             #+#    #+#             */
/*   Updated: 2022/04/04 18:29:33 by arudy            ###   ########.fr       */
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

static int	check_quotes(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == DQUOTE)
		{
			(*i)++;
			if (next_quote(str, DQUOTE, i))
				return (ft_putstr_fd("minishell: syntax error \
near unexpected token \"\n", 2), 1);
			else
				return (0);
		}
		if (str[*i] == QUOTE)
		{
			(*i)++;
			if (next_quote(str, QUOTE, i))
				return (ft_putstr_fd("minishell: syntax error \
near unexpected token \'\n", 2), 1);
			else
				return (0);
		}
		(*i)++;
	}
	return (0);
}

static int	check_pipe(char *s, int *i)
{
	int	n;
	int	j;

	n = 0;
	j = 0;
	while (ft_is_whitespace(s[j]))
		j++;
	if (j == (*i))
		return (ft_putstr_fd("minishell: syntax error \
near unexpected token `|'\n", 2), 1);
	while (s[*i] == PIPE)
	{
		(*i)++;
		n++;
	}
	j = (*i);
	while (ft_is_whitespace(s[j]))
		j++;
	if (n > 1 || s[j] == '\0')
		return (ft_putstr_fd("minishell: syntax error \
near unexpected token `|'\n", 2), 1);
	return (0);
}

int	first_check(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == QUOTE || s[i] == DQUOTE)
		{
			if (check_quotes(s, &i))
				return (1);
		}
		if (s[i] == REDIR_IN || s[i] == REDIR_OUT)
		{
			if (check_redir(s, &i))
				return (1);
		}
		if (s[i] == PIPE)
		{
			if (check_pipe(s, &i))
				return (1);
			i--;
		}
		i++;
	}
	return (0);
}

int	check_tokens(t_token *lst)
{
	while (lst->next)
	{
		if (lst->type == HERE_DOC || lst->type == DGREATER \
			|| lst->type == REDIR_IN || lst->type == REDIR_OUT)
		{
			if (lst->next)
			{
				lst = lst->next;
				if (lst->type == HERE_DOC || lst->type == DGREATER \
					|| lst->type == REDIR_IN || lst->type == REDIR_OUT)
				{
					ft_putstr_fd("minishell: syntax error near \
unexpected token `", 2);
					ft_putstr_fd(lst->content, 2);
					ft_putstr_fd("'\n", 2);
					return (1);
				}
			}
		}
		lst = lst->next;
	}
	return (0);
}
