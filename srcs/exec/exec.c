/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:58:13 by arudy             #+#    #+#             */
/*   Updated: 2022/04/20 15:37:21 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// static void	exec_cmd(t_cmd *lst, t_data *data)
// {
// 	if (create_bin_path(data, lst))
// 		return ;
// 	// check if builtin
// 	if (dup2(lst->in, 0) == -1)
// 	{
// 		printf("Error dup2 \n");
// 		exit (42);
// 	}
// 	if (close(lst->pipe[0]))
// }

void	start_exec(t_cmd *lst, t_data *data)
{
	// Connecter tous les pipes avant l'exec
	// while (data->nb_cmd != 0)
	// {
	// 	if (pipe(lst->pipe))
	// 	{
	// 		printf("Error pipe \n");
	// 		exit (42);
	// 	}
	// 	lst->fork = fork();
	// 	if (lst->fork < 0)
	// 	{
	// 		printf("Error fork \n");
	// 		exit (42);
	// 	}
	// 	if (lst->fork == 0)
	// 		exec_cmd(lst, data);
	// 	data->nb_cmd--;
	// }
	// wait(NULL);
}
