/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_dollar_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:15:48 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/04 13:22:14 by lleveque         ###   ########.fr       */
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
