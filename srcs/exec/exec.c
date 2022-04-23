/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:58:13 by arudy             #+#    #+#             */
/*   Updated: 2022/04/24 00:49:21 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	exec_cmd(t_cmd *lst, t_data *data)
{
	// if (!lst->prev && lst->in != 0)
	// {
	// 	if (dup2(lst->in,  STDIN_FILENO) == -1)
	// 		exec_error("Dup2 error", lst, data);
	// }
	// else if (lst->prev && lst->in == 0)
	// {
	// 	close(lst->prev->pipe[1]);
	// 	if (dup2(lst->prev->pipe[0], STDIN_FILENO) == -1)
	// 		exec_error("Dup2 error", lst, data);
	// }
	// else if (lst->prev && lst->in != 0)
	// {
	// 	if (dup2(lst->in,  STDIN_FILENO) == -1)
	// 		exec_error("Dup2 error", lst, data);
	// }
	// if (lst->next && lst->out == 1)
	// {
	// 	close(lst->pipe[0]);
	// 	if (dup2(lst->pipe[1], STDOUT_FILENO) == -1)
	// 		exec_error("Dup2 error", lst, data);
	// }
	// else if (lst->next && lst->out != 1)
	// {
	// 	if (dup2(lst->out, STDOUT_FILENO) == -1 )
	// 		exec_error("Dup2 error", lst, data);
	// }
	// else if (!lst->next && lst->out != 1)
	// {
	// 	if (dup2(lst->out, STDOUT_FILENO) == -1)
	// 		exec_error("Dup2 error", lst, data);
	// }
	if (check_builtins(lst, data))
		return ;
	if (create_bin_path(data, lst))
		return ;
	execve(lst->bin_path, lst->cmd, data->env_char);
}

// void	waitfork(t_cmd *lst)
// {
// 	while (lst)
// 	{
// 		wait(&lst->fork);
// 		lst = lst->next;
// 	}
// }

void	start_exec(t_cmd *lst, t_data *data)
{
	link_pipe(lst, data);
	// check_builtins(lst);
	// t_cmd *a = lst;
	while (lst)
	{
		lst->fork = fork();
		if (lst->fork < 0)
			exec_error("Fork error", lst, data);
		if (lst->fork == 0)
			exec_cmd(lst, data);
		if (lst->in != 0)
			close(lst->in);
		if (lst->out != 1)
			close(lst->out);
		if (lst->prev)
		{
			close(lst->prev->pipe[0]);
			close(lst->prev->pipe[1]);
		}
		lst = lst->next;
	}
	// waitfork(a);
	wait(NULL);
}
