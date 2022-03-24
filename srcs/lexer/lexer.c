/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:25:20 by arudy             #+#    #+#             */
/*   Updated: 2022/03/23 19:05:00 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_lst(t_token **lst)
{
	while (*lst)
	{
		printf("token content : %s\n", (*lst)->content);
		printf("token type : %u\n", (*lst)->type);
		lst = &(*lst)->next;
	}
}

void	lexer(t_token **tokens_lst, char *s)
{
	t_token	*token;

	if (check_quotes(s))
		return ;
	token = char_to_token(s);
	if (!token)
	{
		printf("Pas new token\n\n");
		return ;
	}
	print_lst(&token);
	ft_free_lst(&token);
	(void)tokens_lst;
}
// Ret lst avec tous les tokens concat par type, donc changer le proto de la ft.
