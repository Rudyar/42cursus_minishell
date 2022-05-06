/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:19:49 by arudy             #+#    #+#             */
/*   Updated: 2022/05/06 20:31:43 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	g_exit_status;

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	(void)av;
	(void)ac;
	// signal(SIGINT, SIG_IGN);
	// signal(SIGQUIT, SIG_IGN);
	g_exit_status = 0;
	data = init_data(envp);
	loop(data, envp);
	free_all(data);
	return (g_exit_status);
}
