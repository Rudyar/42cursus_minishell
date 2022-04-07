/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:42:32 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/07 19:40:38 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	update_add_env_var(t_env *env, char **var)
{
	char	*value;

	if (env->var[1])
	{
		if (var[1])
		{
			value = ft_strjoin(env->var[1], var[1]);
			env->var[1] = value;
			free(var[1]);
		}
		free(var[0]);
	}
	else
	{
		if (var[1])
		{
			free(env->var[0]);
			free(env->var);
			env->var = malloc(sizeof(char *) * 3);
			env->var[0] = name_without_plus(var[0]);
			env->var[1] = var[1];
			env->var[2] = NULL;
		}
		else
			free(var[0]);
	}
}

void	update_env_var(t_env *env, char **var)
{
	if (env->var[1])
	{
		free(env->var[1]);
		if (!var[1])
			env->var[1] = NULL;
		else
			env->var[1] = var[1];
		free(var[0]);
	}
	else
	{
		if (var[1])
		{
			free(env->var[0]);
			free(env->var);
			env->var = malloc(sizeof(char *) * 3);
			env->var[0] = var[0];
			env->var[1] = var[1];
			env->var[2] = NULL;
		}
		else
			free(var[0]);
	}
}

void	add_env_var(char *arg, t_env **env, int n)
{
	char	**tmp;
	char	*var;
	char	*tmp2;

	tmp = ft_nsplit(arg, '=', 2);
	var = name_without_plus(tmp[0]);
	tmp2 = var;
	var = ft_strjoin_char(tmp2, '=');
	if (tmp[1])
	{
		var = ft_strjoin(var, tmp[1]);
		free(tmp[1]);
	}
	free(tmp);
	if (n == 1)
		*env = ft_env_lstnew(var, NULL);
	if (n == 2)
		ft_env_addback(*env, ft_env_lstnew(var, NULL));
	free(var);
	free(tmp2);
}

int	export_cmd(char **args, t_data *data)
{
	int	i;

	i = 0;
	if (!args[1])
	{
		// print_export(env);
		return (0);
	}
	while (args[++i])
	{
		if (args[i] && !check_export_arg(args[i]))
		{
			if (!data->env)
			{
				if (!check_add_value(args[i]))
					data->env = ft_env_lstnew(args[i], NULL);
				else
					add_env_var(args[i], &data->env, 1);
				break ;
			}
			if (check_exist(args[i], data->env))
				continue ;
			else
			{
				if (check_add_value(args[i]))
					add_env_var(args[i], &data->env, 2);
				else
					ft_env_addback(data->env, ft_env_lstnew(args[i], NULL));
			}
		}
		else
			error("export", args[i], "not a valid identifier");
	}
	if (data->env_char)
		free_strs(data->env_char);
	if (data->env)
		data->env_char = dup_env(data->env);
	return (0);
}
