/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:42:32 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/29 19:37:00 by lleveque         ###   ########.fr       */
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

int	export_cmd(char **args, t_env *env)
{
	int	i;

	i = 1;
	while (args[i])
	{
		while (env->next)
			env = env->next;
		if (args[i] && !check_export_arg(args[i])/* && doesnt_exist()*/)
			ft_env_addback(env, ft_env_lstnew(args[i], env));
		else
		{
			ft_putstr_fd("minishell: export: `", 1);
			ft_putstr_fd(args[i], 1);
			ft_putstr_fd("': not a valid identifier\n", 1);
		}
		i++;
	}
	return (0);
}
