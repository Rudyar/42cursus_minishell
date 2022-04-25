/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:58:13 by arudy             #+#    #+#             */
/*   Updated: 2022/04/25 15:36:31 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

static void	exec_cmd(t_cmd *lst, t_data *data)
{
	if (check_builtins(lst, data))
		return ;
	if (create_bin_path(data, lst))
		return ;
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
	if (lst->in > 2)
		close(lst->in);
	if (lst->out > 2)
		close(lst->out);
}

static void	wait_fork(t_cmd *lst, t_data *data)
{
	int	status;

	(void)data;
	while (lst)
	{
		waitpid(lst->fork, &status, 0);
		lst = lst->next;
	}
	// Gérer le retour du waitpid qui est stocké dans status
	// pour la mettre dans la g_exit_value
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
		lst = lst->next;
	}
	wait_fork(head_lst, data);
}

// void	start_exec(t_cmd *lst, t_data *data)
// {
// 	link_pipe(lst, data);
// 	// check_builtins(lst);
// 	while (lst)
// 	{
// 		lst->fork = fork();
// 		if (lst->fork < 0)
// 			exec_error("Fork error", lst, data);
// 		if (lst->fork == 0)
// 			exec_cmd(lst, data);
// 		if (lst->in != 0)
// 			close(lst->in);
// 		if (lst->out != 1)
// 			close(lst->out);
// 		if (lst->prev)
// 		{
// 			close(lst->prev->pipe[0]);
// 			close(lst->prev->pipe[1]);
// 		}
// 		lst = lst->next;
// 	}
// 	wait(NULL);
// }
