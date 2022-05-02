/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:54:28 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/02 16:12:47 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	set_env(t_env *env, t_data *data, char *var, char *value)
{
	while (env)
	{
		if (env->var && !ft_strcmp(env->var[0], var))
		{
			if (env->var[1])
				ft_free(env->var[1], data);
			if (value)
				env->var[1] = value;
			else
				env->var[1] = NULL;
			break ;
		}
		if (!env->next)
			break ;
		env = env->next;
	}
	// if (!ft_strcmp("_", var) && !ft_getenv(data->env, "_"))
		// ft_env_addback(data->env, ft_env_lstnew(ft_strjoin(var, value, data), env, data));
	// OLDPWD TOUT CA POUR CD
	// if (!env)
		// ft_env_addback(data->env, ft_env_lstnew(ft_strjoin(var, value, data), env));
}

char	**dup_env(t_env *env, t_data *data)
{
	int		i;
	char	**dest;
	char	*tmp;
	char	*tmp2;

	i = 0;
	if (!env)
		return (NULL);
	dest = ft_malloc(sizeof(char *) * (ft_lstsize(env) + 1), data);
	while (env)
	{
		tmp2 = ft_strdup(env->var[0], data);
		tmp = ft_strjoin_char(tmp2, '=', data);
		if (env->var[1])
			tmp = ft_strjoin(tmp, env->var[1], data);
		dest[i] = tmp;
		i++;
		env = env->next;
	}
	if (!ft_getenv(data->env, "PATH"))
		dest[i++] = ft_strdup("PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin: \
					/usr/bin:/sbin:/bin", data);
	dest[i] = NULL;
	return (dest);
}
