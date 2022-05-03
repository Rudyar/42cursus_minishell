/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_tokens_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:21:43 by arudy             #+#    #+#             */
/*   Updated: 2022/05/03 02:53:01 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_word(t_token_type type)
{
	if (type == WORD || type == DOLLAR
		|| type == IN_DQUOTE || type == IN_QUOTE)
		return (1);
	return (0);
}

int	is_redir_sign(t_token_type token)
{
	if (token == HERE_DOC)
		return (1);
	if (token == DGREATER)
		return (1);
	if (token == REDIR_IN)
		return (1);
	if (token == REDIR_OUT)
		return (1);
	if (token == HERE_DOC_EXPEND)
		return (1);
	return (0);
}
