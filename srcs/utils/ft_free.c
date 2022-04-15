/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:57:22 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/15 16:37:56 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_garbage(t_garbage *garbage)
{
	t_garbage	*tmp;

	while (garbage->next)
	{
		tmp = garbage;
		if (garbage->ptr)
			free(garbage->ptr);
		garbage = garbage->next;
		free(tmp);
	}
	free(garbage->ptr);
	free(garbage);
}

void	free_env(t_env *lst, t_data *data)
{
	t_env	*tmp;
	int		i;

	if (!lst)
		return ;
	while (lst)
	{
		i = 0;
		tmp = lst;
		while (lst->var[i])
		{
			ft_free(lst->var[i], data);
			i++;
		}
		ft_free(lst->var, data);
		lst = lst->next;
		ft_free(tmp, data);
	}
}

void	remove_garbage(void *ptr, t_data *data)
{
	t_garbage	*tmp;

	while (data->garbage->ptr != ptr)
		data->garbage = data->garbage->next;
	tmp = data->garbage;
	if (!data->garbage->prev && !data->garbage->next)
		return ;
	if (!data->garbage->prev)
		data->garbage->next->prev = NULL;
	else if (!data->garbage->next)
	{
		data->garbage->prev->next = NULL;
		data->garbage = data->garbage->prev;
	}
	if (data->garbage->prev && data->garbage->next)
	{
		data->garbage->prev->next = data->garbage->next;
		data->garbage->next->prev = data->garbage->prev;
	}
	if (data->garbage->next)
		data->garbage = data->garbage->next;
	free(tmp);
	while (data->garbage->prev)
		data->garbage = data->garbage->prev;
}

void	ft_free(void *ptr, t_data *data)
{
	free(ptr);
	remove_garbage(ptr, data);
}

void	free_cmd_lst(t_cmd **lst, t_data *data)
{
	t_cmd	*tmp;
	int		i;

	while (*lst)
	{
		i = 0;
		tmp = *lst;
		while (tmp->cmd[i] != NULL)
		{
			ft_free(tmp->cmd[i], data);
			i++;
		}
		ft_free(tmp->bin_path, data);
		ft_free(tmp->cmd, data);
		*lst = (*lst)->next;
		ft_free(tmp, data);
	}
}

void	free_lst(t_data *data)
{
	free_token_lst(&data->tokens, data);
	free_cmd_lst(&data->cmd_lst, data);
}

void	free_all(t_data *data)
{
	ft_free_garbage(data->garbage);
	free(data);
}
