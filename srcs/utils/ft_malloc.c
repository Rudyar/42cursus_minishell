/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:09:12 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/15 22:41:20 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_garb_addback(t_data *data, t_garbage *new)
{
	while (data->garbage->next)
		data->garbage = data->garbage->next;
	new->prev = data->garbage;
	data->garbage->next = new;
	while (data->garbage->prev)
		data->garbage = data->garbage->prev;
}

t_garbage	*ft_garb_lstnew(void *ptr, t_data *data)
{
	t_garbage	*new;

	new = malloc(sizeof(*new));
	if (!new)
	{
		ft_free_garbage(data->garbage);
		printf("error");
		exit(1);
	}
	new->prev = NULL;
	new->ptr = ptr;
	new->next = NULL;
	return (new);
}

void	*ft_malloc(size_t size, t_data *data)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_free_garbage(data->garbage);
		printf("error");
		exit(1);
	}
	if (data->garbage->ptr)
		ft_garb_addback(data, ft_garb_lstnew(ptr, data));
	else
	{
		data->garbage->prev = NULL;
		data->garbage->ptr = ptr;
		data->garbage->next = NULL;
	}
	return (ptr);
}
