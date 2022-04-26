/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:58:13 by arudy             #+#    #+#             */
/*   Updated: 2022/04/26 11:37:11 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_exit_status;

static void	exec_cmd(t_cmd *lst, t_data *data)
{
	if (check_builtins(lst, data))
	{
		g_exit_status = exec_builtins(lst, data);
		return ;
	}
	if (create_bin_path(data, lst))
		g_exit_status = create_bin_path(data, lst);
	execve(lst->bin_path, lst->cmd, data->env_char);
	ft_putstr_fd("Pas exec\n", 2);
}

static void	launch_ugo(t_cmd *lst, t_data *data)
{
	if (lst->in == -1 || lst->out == -1)
	{
		free_all(data);
		exit(42);
	}
	if (lst->in > 2)
		if (dup2(lst->in, STDIN_FILENO) == -1)
			exec_error("Dup2 error 1", lst, data);
	if (lst->out > 2)
		if (dup2(lst->out, STDOUT_FILENO) == -1)
			exec_error("Dup2 error 2", lst, data);
	if (lst->next)
		close(lst->pipe[0]);
	exec_cmd(lst, data);
}

static void	wait_fork(t_cmd *lst, t_data *data)
{
	int	status;

	(void)data;
	while (lst)
	{
		waitpid(lst->fork, &status, 0);
		g_exit_status = status;
		lst = lst->next;
	}
}

void	start_exec(t_cmd *lst, t_data *data)
{
	t_cmd	*head_lst;

	head_lst = lst;
	while (lst)
	{
		link_pipe(lst, data);
		// if cmd
		lst->fork = fork();
		if (lst->fork < 0)
			exec_error("Fork error", lst, data);
		if (lst->fork == 0)
			launch_ugo(lst, data);
		if (lst->in > 2)
			close(lst->in);
		if (lst->out > 2)
			close(lst->out);
		lst = lst->next;
	}
	wait_fork(head_lst, data);
}
