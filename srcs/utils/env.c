/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:54:28 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/16 00:30:07 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
