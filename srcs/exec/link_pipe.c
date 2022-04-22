/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:57:01 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/22 12:51:39 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	link_pipe(t_cmd *lst, t_data *data)
{
	while (lst)
	{
		if (lst->next)
		{
			if (pipe(lst->pipe))
				exec_error("Pipe error", lst, data);
			// if (lst->out == 1)
			// 	lst->out = lst->pipe[1];
			// else
			// 	close(lst->pipe[1]);
			// if (lst->next->in == 0)
			// 	lst->next->in = lst->pipe[0];
			// else
			// 	close(lst->pipe[0]);
		}
		lst = lst->next;
	}
}

