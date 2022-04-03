/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:37:01 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/03 18:23:15 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_env_lst(t_env *env)
{
	int		i;

	i = 0;
	while (env->var[i])
	{
		free(env->var[i]);
		i++;
	}
	free(env->var);
	free(env);
}

int	check_unset_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg)
	{
		if (!ft_isalpha(arg[0]))
			return (1);
		while (arg[i])
		{
			if (!ft_isalpha(arg[i]) && !ft_isdigit(arg[i]) && arg[i] != '_')
				return (1);
			i++;
		}
	}
	return (0);
}

t_env	*unset_env_var(t_env *env, char *arg)
{
	t_env	*tmp;

	while (env->next)
	{
		if (env->var[0] && !ft_strcmp(env->var[0], arg))
		{
			tmp = env;
			if (env->prev)
				env->prev->next = env->next;
			if (env->next)
				env->next->prev = env->prev;
			env = env->next;
			break ;
		}
		else
			env = env->next;
	}
	while (env->prev)
		env = env->prev;
	return (env);
}

int	unset_cmd(char **args, t_env **env)
{
	int		i;

	i = 1;
	while (args[i])
	{
		while (args[i] && check_unset_arg(args[i]))
		{
			error("unset", args[i], "not a valid identifier");
			i++;
		}
		if (!args[i])
			break ;
		*env = unset_env_var(*env, args[i]);
		i++;
	}
	return (0);
}
