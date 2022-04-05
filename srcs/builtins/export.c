/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:42:32 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/04 19:11:41 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_value(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	check_export_arg(char *arg)
{
	int	i;

	i = 0;
	if (!check_value(arg))
		return (1);
	while (arg[i])
	{
		if (!ft_isalpha(arg[i]) && !ft_isdigit(arg[i]) && arg[i] != '=')
			return (1);
		i++;
	}
	return (0);
}

int	check_exist(char *arg, t_env *env)
{
	char *var;

	while (env)
	{
		if (env->var[0])
		{
			var = ft_strjoin_char(env->var[0], '=');
			if (!ft_strcmp(var, arg))
			{
				free(var);
				return (1);
			}
			free(var);
		}
		env = env->next;
	}
	return (0);
}

void	update_var(char *arg, t_env *env)
{
	char **var;

	var = ft_nsplit(arg, '=', 2);
	printf("var[1] = %s\n", env->var[1]);
	free(var);
	// while (env)
	// {
	// 	if (env->var[0])
	// 	{

	// 	}
	// }
}

int	export_cmd(char **args, t_env *env)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (args[i] && !check_export_arg(args[i]))
		{
			// if (check_exist(args[i], env))
			// 	update_var(args[i], env);
			// else
			ft_env_addback(env, ft_env_lstnew(args[i], env));
		}
		else
			error("export", args[i], "not a valid identifier");
		i++;
	}
	return (0);
}
