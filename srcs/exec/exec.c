/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:58:13 by arudy             #+#    #+#             */
/*   Updated: 2022/04/21 17:56:00 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	exec_cmd(t_cmd *lst, t_data *data)
{
	if (create_bin_path(data, lst))
		return ;
	// check if builtin
	if (!lst->prev && lst->in != 0)
	{
		if (dup2(lst->in,  STDIN_FILENO) == -1)
			exec_error("Dup2 error", lst, data);
	}
	else if (lst->prev && lst->in == 0)
	{
		if (dup2(lst->prev->pipe[0],  STDIN_FILENO) == -1)
			exec_error("Dup2 error", lst, data);
		close(lst->pipe[1]);
	}
	else if (lst->prev)
	{
		if (dup2(lst->in,  STDIN_FILENO) == -1)
			exec_error("Dup2 error", lst, data);
	}
	if (!lst->next && lst->out != 1)
	{
		if (dup2(lst->out, STDOUT_FILENO) == -1)
			exec_error("Dup2 error", lst, data);
	}
	else if (lst->next && lst->out == 1)
	{
		if (dup2(lst->out, STDOUT_FILENO) == -1)
			exec_error("Dup2 error", lst, data);
		close(lst->pipe[0]);
	}
	else if (lst->next)
	{
		if (dup2(lst->out, STDOUT_FILENO) == -1)
			exec_error("Dup2 error", lst, data);
	}
	execve(lst->bin_path, lst->cmd, data->env_char);
}

void	start_exec(t_cmd *lst, t_data *data)
{
	link_pipe(lst, data);
	while (lst)
	{
		lst->fork = fork();
		if (lst->fork < 0)
		exec_error("Fork error", lst, data);
		if (lst->fork == 0)
			exec_cmd(lst, data);
		lst = lst->next;
	}
	wait(NULL);
}
