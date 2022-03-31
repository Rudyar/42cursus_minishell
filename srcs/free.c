/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:57:22 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/31 18:48:31 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_env(t_env *lst)
{
	t_env	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

void	ft_free(t_data *data)
{
	free_env(data->env);
	free(data);
}

void	free_cmd_lst(t_cmd **lst)
{
	t_cmd	*tmp;
	int		i;

	while (*lst)
	{
		i = 0;
		tmp = *lst;
		while (tmp->cmd[i] != NULL)
		{
			free(tmp->cmd[i]);
			i++;
		}
		free(tmp->cmd);
		*lst = (*lst)->next;
		free(tmp);
	}
}

void	free_lst(t_data *data)
{
	free_token_lst(&data->tokens);
	free_cmd_lst(&data->cmd_lst);
}
