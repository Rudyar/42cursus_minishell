/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:47:16 by arudy             #+#    #+#             */
/*   Updated: 2022/04/08 14:51:25 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*scan_tokens(t_data *data, t_token *lst)
{
	t_token	*head;
	t_token	*prev;

	head = NULL;
	prev = NULL;
	if (scan_redir(lst))
		return (NULL);
	if (scan_dollar(data, lst))
		return (NULL);
	print_token_lst(&lst);
	return (NULL);
}
