/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:54:28 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/19 16:47:04 by lleveque         ###   ########.fr       */
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
		}
		env = env->next;
	}
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
	dest[i] = NULL;
	return (dest);
}
