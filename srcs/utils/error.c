/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:23:24 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/03 11:03:37 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	*error(char *cmd, char *arg, char *msg)
{
	ft_putstr_fd("minishell: ", 1);
	if (cmd)
	{
		ft_putstr_fd(cmd, 1);
		ft_putstr_fd(": ", 1);
	}
	if (arg)
	{
		ft_putstr_fd(arg, 1);
		ft_putstr_fd(": ", 1);
	}
	if (msg)
		ft_putstr_fd(msg, 1);
	ft_putstr_fd("\n", 1);
	return (NULL);
}
