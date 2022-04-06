/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:42:32 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/06 20:02:42 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	update_add_env_var(char *arg, t_env *env)
{
	char	**var;
	char	*value;

	var = ft_nsplit(arg, '=', 2);
	if (env->var[1])
	{
		value = ft_strjoin(env->var[1], var[1]);
		env->var[1] = value;
		free(var[0]);
		free(var[1]);
	}
	else
	{
		free(env->var[0]);
		free(env->var);
		env->var = malloc(sizeof(char *) * 2);
		env->var[0] = name_without_plus(var[0]);
		env->var[1] = NULL;
	}
	free(var);
}

void	update_env_var(char *arg, t_env *env)
{
	char	**var;

	var = ft_nsplit(arg, '=', 2);
	if (env->var[1])
	{
		free(env->var[1]);
		env->var[1] = var[1];
		free(var[0]);
	}
	else
	{
		free(env->var[0]);
		free(env->var);
		env->var = malloc(sizeof(char *) * 2);
		env->var[0] = var[0];
		env->var[1] = NULL;
	}
	free(var);
}

void	add_env_var(char *arg, t_env *env)
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
	ft_env_addback(env, ft_env_lstnew(var, NULL));
}

int	export_cmd(char **args, t_env *env)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (args[i] && !check_export_arg(args[i]))
		{
			if (check_exist(args[i], env))
			{
				i++;
				continue ;
			}
			else
			{
				if (check_add_value(args[i]))
					add_env_var(args[i], env);
				else
					ft_env_addback(env, ft_env_lstnew(args[i], NULL));
			}
		}
		else
			error("export", args[i], "not a valid identifier");
		i++;
	}
	return (0);
}
