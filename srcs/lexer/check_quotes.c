/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:35:41 by arudy             #+#    #+#             */
/*   Updated: 2022/03/23 11:45:40 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	find_next_quote(char *str, char c, int	*i)
{
	while (str[*i])
	{
		if (str[*i] == c)
			return (0);
		*i = *i + 1;
	}
	return (1);
}

int	check_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == DQUOTE)
		{
			i++;
			if (find_next_quote(str, DQUOTE, &i))
			{
				ft_putstr_fd("Minishell: syntax error near unexpected token \"\n", 2);
				return (1);
			}
		}
		if (str[i] == QUOTE)
		{
			i++;
			if (find_next_quote(str, QUOTE, &i))
			{
				ft_putstr_fd("Minishell: syntax error near unexpected token \'\n", 2);
				return (1);
			}
		}
		i++;
	}
	return (0);
}
