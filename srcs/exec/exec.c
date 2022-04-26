/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:58:13 by arudy             #+#    #+#             */
/*   Updated: 2022/04/26 15:52:38 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_exit_status;

static int exec_cmd(t_cmd *lst, t_data *data)
{
	if (check_builtins(lst))
		exit(exec_builtins(lst, data));
	if (!create_bin_path(data, lst))
		execve(lst->bin_path, lst->cmd, data->env_char);
	exit(127);
}

static void	launch_ugo(t_cmd *lst, t_data *data)
{
	if (lst->in < 0 || lst->out < 0)
		exit(1);
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

static void	wait_fork(t_cmd *lst)
{
	int		status;

	while (lst)
	{
		waitpid(lst->fork, &status, 0);
		g_exit_status = status % 255;
		if (g_exit_status == 127)
			lst->error = 1;
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	while (lst)
	{
		if (lst->error)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(lst->cmd[0], 2);
			ft_putstr_fd(": command not found\n", 2);
		}
		lst = lst->prev;
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
	wait_fork(head_lst);
}
