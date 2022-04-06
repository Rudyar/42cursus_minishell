/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:22:34 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/06 19:21:42 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

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
	if (!ft_isalpha(arg[1]) && arg[1] != '_')
		return (1);
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalpha(arg[i]) && !ft_isdigit(arg[i]) && arg[i] != '='
			&& arg[i] != '_')
		{
			if (arg[i + 1] && arg[i] == '+' && arg[i + 1] == '=')
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_add_value(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (arg[i] && arg[i - 1] && arg[i] == '=' && arg[i - 1] == '+')
		return (1);
	return (0);
}

int	check_name(char **var, char *arg)
{
	int	i;

	i = ft_strlen(var[0]);
	if (!ft_strncmp(var[0], arg, i))
	{
		if (arg[i] && arg[i] == '=')
			return (1);
		else if (arg[i] && arg[i + 1] && arg[i] == '+' && arg[i + 1] == '=')
			return (2);
	}
	return (0);
}

int	check_exist(char *arg, t_env *env)
{
	int	check;

	while (env)
	{
		if (env->var[0])
		{
			check = check_name(env->var, arg);
			if (check)
			{
				if (check == 1)
					return (update_env_var(arg, env), 1);
				else
					return (update_add_env_var(arg, env), 1);
			}
		}
		env = env->next;
	}
	return (0);
}
