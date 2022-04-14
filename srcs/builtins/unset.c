/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:37:01 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/12 16:12:24 by lleveque         ###   ########.fr       */
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
		if (!ft_isalpha(arg[0]) && arg[0] != '_')
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

	while (env)
	{
		if (env->var[0] && !ft_strcmp(env->var[0], arg))
		{
			tmp = env;
			if (!env->prev && !env->next)
				return (NULL);
			if (!env->prev)
				env->next->prev = NULL;
			else if (!env->next)
			{
				env->prev->next = NULL;
				env = env->prev;
			}
			if (env->prev && env->next)
			{
				env->prev->next = env->next;
				env->next->prev = env->prev;
			}
			if (env->next)
				env = env->next;
			free_env_lst(tmp);
			break ;
		}
		else if (env->next)
			env = env->next;
		else
			break ;
	}
	while (env->prev)
		env = env->prev;
	return (env);
}

int	unset_cmd(char **args, t_data *data)
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
		if (data->env)
			data->env = unset_env_var(data->env, args[i]);
		i++;
	}
	free_strs(data->env_char);
	data->env_char = dup_env(data->env);
	return (0);
}
