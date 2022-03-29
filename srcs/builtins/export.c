/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:42:32 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/28 19:14:31 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// int	is_unvalid(char c)
// {
// 	if (c == '=')
// }

// int	check_export_arg(char *arg)
// {
// 	int	i;

// 	i = 0;
// 	if (arg)
// 	{
// 		if (arg[0] == '=')
// 		while (arg[i])
// 		{

// 		}
// 	}
// }

int	export_cmd(char **args, t_env *envp)
{
	int	i;

	i = 1;

	// while (args[i])
	// {
	// 	*envp = ft_strsjoin(*envp, args[i]);
	// 	i++;
	// }
	(void)envp;
	(void)args;
	return (0);
}
