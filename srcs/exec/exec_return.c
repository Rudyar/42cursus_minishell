/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_return.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:37:48 by arudy             #+#    #+#             */
/*   Updated: 2022/04/29 10:38:22 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_exit_status;

void	exec_error(char *msg, t_cmd *lst, t_data *data)
{
	(void)lst;
	error(NULL, NULL, msg);
	free_all(data);
	g_exit_status = 255;
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
