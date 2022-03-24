/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:37:27 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/24 19:24:27 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_opt(char **args)
{
	int	i;

	i = 2;
	if (args[1] && (args[1][0] == '-' && args[1][1] == 'n'))
	{
		while (args[1][i] == 'n')
			i++;
		if (args[1][i] == '\0')
			return (1);
	}
	return (0);
}

int	echo_cmd(char **args)
{
	int	i;

	i = 1;
	if (!args[1])
	{
		ft_putstr_fd("\n", 1);
		return (0);
	}
	if (check_opt(args) && !args[2])
		return (0);
	if (check_opt(args))
		i = 2;
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		i++;
		if (args[i])
			ft_putstr_fd(" ", 1);
	}
	if (!check_opt(args))
		ft_putstr_fd("\n", 1);
	return (0);
}

// int main(int ac, char **av, char **envp)
// {
// 	(void)ac;
// 	(void)envp;
// 	echo(av);
// 	return (0);
// }
