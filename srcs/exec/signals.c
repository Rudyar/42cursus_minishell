/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:08:13 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/28 17:24:57 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_exit_status;

void	sig_exec_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("quit FORKKKKK\n", 1);
		g_exit_status = 130;
	}
	else if (sig == SIGQUIT)
		ft_putstr_fd("quit FORKKKKK\n", 1);
}
		// exit(130);
		// ft_putstr_fd("\b\b  \b\b", 1);

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_exit_status = 130;
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
		ft_putstr_fd("\b\b  \b\b", 1);
	return ;
}
