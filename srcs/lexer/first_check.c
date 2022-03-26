/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:35:41 by arudy             #+#    #+#             */
/*   Updated: 2022/03/26 19:09:00 by arudy            ###   ########.fr       */
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

static int	count_char_occurences(char *s, t_token_type c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == (int)c)
		{
			while (s[i] == (int)c)
			{
				n++;
				i++;
			}
			return (n);
		}
		i++;
	}
	return (n);
}

int	first_check(char *s)
{
	if (check_quotes(s))
		return (1);
	if (count_char_occurences(s, REDIR_IN) > 2)
		return (ft_putstr_fd("minishell: syntax error \
near unexpected token `newline'\n", 2), 1);

	return (0);
}
