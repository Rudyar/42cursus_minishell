/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:58:13 by arudy             #+#    #+#             */
/*   Updated: 2022/04/30 11:46:25 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_exit_status;

static void	wait_fork(t_cmd *lst)
{
	int		status;

	while (lst)
	{
		if (lst->fork > 0)
		{
			waitpid(lst->fork, &status, 0);
			g_exit_status = status % 255;
		}
		if (g_exit_status == 127)
			lst->error = 1;
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	while (lst)
	{
		if (lst->error && ft_strncmp(lst->cmd[0], "./", 2))
			error(lst->cmd[0], NULL, "command not found");
		lst = lst->prev;
	}
}

static int	exec_cmd(t_cmd *lst, t_data *data)
{
	if (!create_bin_path(data, lst))
		execve(lst->bin_path, lst->cmd, data->env_char);
	else if (!ft_strncmp(lst->cmd[0], "./", 2))
		return (executable_error(lst, data));
	else
		return (exit_fork(lst, data, 127));
	if (!ft_strncmp(lst->cmd[0], "./", 2))
		return (executable_error(lst, data));
	if (errno == EACCES)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(lst->cmd[0]);
		return (exit_fork(lst, data, 126));
	}
	return (exit_fork(lst, data, 127));
}

static void	launch_ugo(t_cmd *lst, t_data *data)
{
	if (lst->in < 0 || lst->out < 0)
		exit(exit_fork(lst, data, 1));
	if (lst->in > 2)
		if (dup2(lst->in, STDIN_FILENO) == -1)
			exec_error("Bad file descriptor", lst, data);
	if (lst->out > 2)
		if (dup2(lst->out, STDOUT_FILENO) == -1)
			exec_error("Bad file descriptor", lst, data);
	if (lst->next)
		close(lst->pipe[0]);
	if (check_builtins(lst))
		exit(exit_fork(lst, data, exec_builtins(lst, data)));
	else
		exit(exec_cmd(lst, data));
}

void	start_exec(t_cmd *lst, t_data *data)
{
	t_cmd	*head_lst;

	head_lst = lst;
	while (lst)
	{
		link_pipe(lst, data);
		if (lst->cmd_no_args)
		{
			lst->fork = fork();
			if (lst->fork < 0)
				exec_error("fork failed: Resource temporarily unavailable", \
				lst, data);
			if (lst->fork == 0)
				launch_ugo(lst, data);
		}
		if (lst->in > 2)
			close(lst->in);
		if (lst->out > 2)
			close(lst->out);
		lst = lst->next;
	}
	wait_fork(head_lst);
}
