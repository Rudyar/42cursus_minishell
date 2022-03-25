/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:26:20 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/25 16:21:24 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_env_args(char **args)
{
	int		i;
	size_t	j;

	i = 1;
	j = 0;
	if (!args)
		return (1);
	while (args[i])
	{
		while (args[i][j])
		{
			printf("%c\n", args[i][j]);
			if (args[i][j] == '=')
				break ;
			j++;
		}
		if (j == ft_strlen(args[i]) - 1)
			return (1);
		i++;
	}
	return (0);
}

int	env_cmd(char **args, t_env *env)
{
	int	i;

	i = 1;
	if (check_env_args(args))
		return (0);
	while (env)
	{
		ft_putstr_fd(env->var, 1);
		ft_putstr_fd("\n", 1);
		env = env->next;
	}
	if (!args)
		return (0);
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
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
// 	env_cmd(av, envp);
// 	return (0);
// }
