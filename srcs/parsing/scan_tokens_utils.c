/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_tokens_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:21:43 by arudy             #+#    #+#             */
/*   Updated: 2022/04/14 11:30:57 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	check_builtins(t_cmd *lst)
{
	while (lst)
	{
		if (ft_strncmp(lst->cmd[0], "cd", 3) == 0)
			lst->is_builtin = 1;
		else if (ft_strncmp(lst->cmd[0], "pwd", 4) == 0)
			lst->is_builtin = 1;
		else if (ft_strncmp(lst->cmd[0], "echo", 5) == 0)
			lst->is_builtin = 1;
		else if (ft_strncmp(lst->cmd[0], "env", 4) == 0)
			lst->is_builtin = 1;
		else if (ft_strncmp(lst->cmd[0], "export", 7) == 0)
			lst->is_builtin = 1;
		else if (ft_strncmp(lst->cmd[0], "unset", 6) == 0)
			lst->is_builtin = 1;
		else if (ft_strncmp(lst->cmd[0], "exit", 6) == 0)
			lst->is_builtin = 1;
		else
			lst->is_builtin = 0;
		lst = lst->next;
	}
}
