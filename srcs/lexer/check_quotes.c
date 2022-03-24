/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:35:41 by arudy             #+#    #+#             */
/*   Updated: 2022/03/23 19:05:26 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	find_next_quote(char *str, char c, int	*i)
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
			if (find_next_quote(str, DQUOTE, &i))
				return (ft_putstr_fd("minishell: syntax error \
near unexpected token \"\n", 2), 1);
		}
		if (str[i] == QUOTE)
		{
			i++;
			if (find_next_quote(str, QUOTE, &i))
				return (ft_putstr_fd("minishell: syntax error \
near unexpected token \'\n", 2), 1);
		}
	}
	return (0);
}
