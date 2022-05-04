/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_dollar_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:15:48 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/04 16:13:04 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_heredoc(t_token *lst)
{
	if (lst->prev)
	{
		if (lst->prev->type == HERE_DOC_EXPEND || lst->prev->type == HERE_DOC)
			return (1);
		if (lst->prev->prev && lst->prev->type == WHITE_SPACE)
			if (lst->prev->prev->type == HERE_DOC_EXPEND || \
				lst->prev->prev->type == HERE_DOC)
				return (1);
	}
	return (0);
}

int	is_dollar_char_valid(char c, int n)
{
	if (n == 1)
	{
		if (!ft_isalpha(c) && c != '{' && c != '}' && c != '_')
			return (1);
	}
	else
		if (!ft_isdigit(c) && !ft_isalpha(c) && c != '{' && c != '}'
			&& c != '_')
			return (1);
	return (0);
}
