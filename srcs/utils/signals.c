/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:47:04 by arudy             #+#    #+#             */
/*   Updated: 2022/05/06 10:38:10 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_exit_status;

void	sig_reset(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

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

void	sig_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		close(0);
		g_exit_status = 130;
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
	}
	else if (sig == SIGQUIT)
		ft_putstr_fd("\b\b  \b\b", 1);
}

void	sig_handler_heredoc(void)
{
	signal(SIGINT, sig_heredoc);
	signal(SIGQUIT, sig_heredoc);
}
