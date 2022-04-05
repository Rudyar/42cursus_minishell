/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:46:15 by arudy             #+#    #+#             */
/*   Updated: 2022/04/04 17:20:54 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	redir_error_msg(int n, char c)
{
	if (n == 1)
	{
		if (c == '<')
			ft_putstr_fd("minishell: syntax error near \
unexpetecd token `newline'\n", 2);
		else
			ft_putstr_fd("minishell: syntax error near \
unexpected token `>'\n", 2);
	}
	if (n == 2)
	{
		ft_putstr_fd("minishell: syntax error \
near unexpected token `newline'\n", 2);
	}
	return (1);
}

static int	valid_redir(char *s, int *i, char c_type)
{
	int	n;
	int	j;

	n = 0;
	while (s[*i] == c_type)
	{
		n++;
		(*i)++;
	}
	if (n > 2)
		return (redir_error_msg(1, c_type));
	j = (*i);
	while (ft_is_whitespace(s[j]))
		j++;
	if (s[j] == '\0')
		return (redir_error_msg(2, 0));
	(*i)--;
	return (0);
}

int	check_redir(char *s, int *i)
{
	if (s[*i] == REDIR_IN)
		return (valid_redir(s, i, '<'));
	if (s[*i] == REDIR_OUT)
		return (valid_redir(s, i, '>'));
	return (0);
}
