/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:42:32 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/15 11:23:49 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	update_add_env_var(t_env *env, char **var, t_data *data)
{
	char	*value;

	if (env->var[1])
	{
		if (var[1])
		{
			value = ft_strjoin(env->var[1], var[1], data);
			env->var[1] = value;
			ft_free(var[1], data);
		}
		ft_free(var[0], data);
	}
	else
	{
		if (var && var[1])
		{
			ft_free(env->var[0], data);
			ft_free(env->var, data);
			env->var = ft_malloc(sizeof(char *) * 3, data);
			env->var[0] = name_without_plus(var[0], data);
			env->var[1] = var[1];
			env->var[2] = NULL;
		}
		ft_free(var[0], data);
	}
}

void	update_env_var(t_env *env, char **var, t_data *data)
{
	if (env->var[1])
	{
		ft_free(env->var[1], data);
		if (!var[1])
			env->var[1] = NULL;
		else
			env->var[1] = var[1];
		ft_free(var[0], data);
	}
	else
	{
		if (var[1])
		{
			ft_free(env->var[0], data);
			ft_free(env->var, data);
			env->var = ft_malloc(sizeof(char *) * 3, data);
			env->var[0] = var[0];
			env->var[1] = var[1];
			env->var[2] = NULL;
		}
		else
			ft_free(var[0], data);
	}
}

void	add_env_var(char *arg, t_env **env, int n, t_data *data)
{
	char	**tmp;
	char	*var;

	tmp = NULL;
	if (arg[ft_strlen(arg) - 1] != '=')
	{
		tmp = ft_nsplit(arg, '=', 2, data);
		var = name_without_plus(tmp[0], data);
		var = ft_strjoin_char(var, '=', data);
		ft_free(tmp[0], data);
	}
	else
		var = name_without_plus(arg, data);
	if (tmp != NULL && tmp[1])
	{
		var = ft_strjoin(var, tmp[1], data);
		ft_free(tmp[1], data);
		ft_free(tmp, data);
	}
	if (n == 1)
		*env = ft_env_lstnew(var, NULL, data);
	if (n == 2)
		ft_env_addback(*env, ft_env_lstnew(var, NULL, data));
	ft_free(var, data);
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
			if (!check_value(args[i]))
				continue ;
			if (!data->env)
			{
				if (!check_add_value(args[i]))
					data->env = ft_env_lstnew(args[i], NULL, data);
				else
					add_env_var(args[i], &data->env, 1, data);
				break ;
			}
			if (check_exist(args[i], data->env, data))
				continue ;
			else
			{
				if (check_add_value(args[i]))
					add_env_var(args[i], &data->env, 2, data);
				else
					ft_env_addback(data->env, ft_env_lstnew(args[i], NULL, data));
			}
		}
		else
			error("export", args[i], "not a valid identifier");
	}
	if (data->env_char)
		free_strs(data->env_char, data);
	if (data->env)
		data->env_char = dup_env(data->env, data);
	return (0);
}
