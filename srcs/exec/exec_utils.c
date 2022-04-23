/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:03:42 by arudy             #+#    #+#             */
/*   Updated: 2022/04/24 00:24:46 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_exit_status;

int	check_builtins(t_cmd *lst, t_data *data)
{
	if (ft_strncmp(lst->cmd[0], "cd", 3) == 0)
		return (cd_cmd(lst->cmd, data), 1);
	else if (ft_strncmp(lst->cmd[0], "pwd", 4) == 0)
		return (pwd_cmd(), 1);
	else if (ft_strncmp(lst->cmd[0], "echo", 5) == 0)
		return (echo_cmd(lst->cmd), 1);
	else if (ft_strncmp(lst->cmd[0], "env", 4) == 0)
		return (env_cmd(data), 1);
	else if (ft_strncmp(lst->cmd[0], "export", 7) == 0)
		return (export_cmd(lst->cmd, data), 1);
	else if (ft_strncmp(lst->cmd[0], "unset", 6) == 0)
		return (unset_cmd(lst->cmd, data), 1);
	else if (ft_strncmp(lst->cmd[0], "exit", 6) == 0)
		return (exit_cmd(lst->cmd, data), 1);
	printf("NOT BUILTINS\n");
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
