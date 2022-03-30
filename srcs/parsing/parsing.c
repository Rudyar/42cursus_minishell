/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:02:20 by arudy             #+#    #+#             */
/*   Updated: 2022/03/30 11:54:00 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	count_nb_cmd(t_token **lst)
{
	int	i;

	i = 0;
	while (*lst)
	{
		if ((*lst)->type == PIPE)
			i++;
		lst = &(*lst)->next;
	}
	return (i);
}

int	parsing(char *line, t_token **tokens_lst, t_data *data)
{
	if (first_check(line))
		return (1);
	if (lexer(line, tokens_lst))
		return (1);
	data->nb_cmd = count_nb_cmd(tokens_lst);
	return (0);
}
