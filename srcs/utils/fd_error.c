/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:38:45 by arudy             #+#    #+#             */
/*   Updated: 2022/05/10 14:00:56 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	fd_error_addback(t_fd_error *new, t_data *data)
{
	if (new)
	{
		if (data->fd_error)
		{
			while (data->fd_error->next)
				data->fd_error = data->fd_error->next;
			data->fd_error->next = new;
			new->prev = data->fd_error;
		}
	}
}

t_token	*new_fd_error(t_token *lst, t_data *data)
{
	t_fd_error	*new;

	new = ft_malloc(sizeof(t_fd_error), data);
	new->prev = NULL;
	new->content = ft_strdup(lst->content, data);
	new->errno_nb = errno;
	new->next = NULL;
	if (!data->fd_error)
		data->fd_error = new;
	else
		fd_error_addback(new, data);
	return (lst);
}

void	print_fd_error(t_data *data)
{
	while (data->fd_error)
	{
		ft_putstr_fd("minishell: ", 2);
		errno = data->fd_error->errno_nb;
		perror(data->fd_error->content);
		data->fd_error = data->fd_error->next;
	}
}
