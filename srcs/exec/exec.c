/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:58:13 by arudy             #+#    #+#             */
/*   Updated: 2022/04/25 19:14:00 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_exit_status;

static void	exec_cmd(t_cmd *lst, t_data *data)
{
	if (check_builtins(lst, data))
		exit (1);
	if (create_bin_path(data, lst))
		exit (1);
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
	if (lst->next && lst->next->in == lst->pipe[0])
		close(lst->pipe[0]);
	if (lst->prev && lst->prev->out == lst->prev->pipe[1] \
		&& lst->in == lst->prev->pipe[0])
		close(lst->prev->pipe[1]);
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
	link_pipe(lst, data);
	while (lst)
	{
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
