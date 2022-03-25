/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:26:20 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/25 09:54:05 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern char	**__environ;

int	env_cmd(t_env *env)
{
	while (env)
	{
		ft_putstr_fd(env->var, 1);
		ft_putstr_fd("\n", 1);
		env = env->next;
	}
	return (0);
}

// int main(int ac, char **av, char **envp)
// {
// 	(void)ac;
// 	(void)av;
// 	(void)envp;
// 	// char **var;
// 	// var=__environ;
// 	// for(int i = 0; var[i] != NULL; i++)
// 	// 	printf("%s\n", var[i]);
// 	env(envp);
// 	return (0);
// }
