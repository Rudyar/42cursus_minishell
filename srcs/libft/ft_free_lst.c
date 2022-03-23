/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:49:07 by arudy             #+#    #+#             */
/*   Updated: 2022/03/23 18:50:27 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_lst(t_token **lst)
{
	t_token	*tmp;

	while (*lst)
	{
		tmp = *lst;
		free(tmp->content);
		*lst = (*lst)->next;
		free(tmp);
	}
}
