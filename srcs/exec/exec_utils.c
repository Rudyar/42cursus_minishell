/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:03:42 by arudy             #+#    #+#             */
/*   Updated: 2022/04/28 16:46:32 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_exit_status;

int	exec_builtins(t_cmd *lst, t_data *data)
{
	if (!ft_strncmp(lst->cmd[0], "cd", 3))
		return (cd_cmd(lst->cmd, data));
	else if (!ft_strncmp(lst->cmd[0], "pwd", 4))
		return (pwd_cmd());
	else if (!ft_strncmp(lst->cmd[0], "echo", 5))
		return (echo_cmd(lst->cmd));
	else if (!ft_strncmp(lst->cmd[0], "env", 4))
		return (env_cmd(data));
	else if (!ft_strncmp(lst->cmd[0], "export", 7))
		return (export_cmd(lst->cmd, data));
	else if (!ft_strncmp(lst->cmd[0], "unset", 6))
		return (unset_cmd(lst->cmd, data));
	else if (!ft_strncmp(lst->cmd[0], "exit", 6))
		return (exit_cmd(lst->cmd, data));
	return (0);
}

int	check_builtins(t_cmd *lst)
{
	if (!lst->cmd[0])
		return (0);
	if (!ft_strncmp(lst->cmd[0], "cd", 3))
		return (1);
	else if (!ft_strncmp(lst->cmd[0], "pwd", 4))
		return (1);
	else if (!ft_strncmp(lst->cmd[0], "echo", 5))
		return (1);
	else if (!ft_strncmp(lst->cmd[0], "env", 4))
		return (1);
	else if (!ft_strncmp(lst->cmd[0], "export", 7))
		return (1);
	else if (!ft_strncmp(lst->cmd[0], "unset", 6))
		return (1);
	else if (!ft_strncmp(lst->cmd[0], "exit", 6))
		return (1);
	return (0);
}

void	exec_error(char *msg, t_cmd *lst, t_data *data)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(lst->cmd[0], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	free_all(data);
	exit(g_exit_status);
}

int	exit_fork(t_cmd *lst, t_data *data, int ret)
{
	if (lst->in > 2)
		close(lst->in);
	if (lst->out > 2)
		close(lst->out);
	free_all(data);
	return (ret);
}

int	executable_error(t_cmd *lst, t_data *data)
{
	struct stat	st;

	if (lstat(lst->cmd[0], &st) == -1)
	{
		error(lst->cmd[0], NULL, "No such file or directory");
		return (exit_fork(lst, data, 127));
	}
	else if ((st.st_mode & S_IFMT) == S_IFDIR)
		error(lst->cmd[0], NULL, "Is a directory");
	else
		error(lst->cmd[0], NULL, "Permission denied");
	return (exit_fork(lst, data, 126));
}
