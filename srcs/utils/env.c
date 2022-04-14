/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:54:28 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/14 13:01:51 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**dup_env(t_env *env)
{
	int		i;
	char	**dest;
	char	*tmp;
	char	*tmp2;

	i = 0;
	dest = malloc(sizeof(char *) * (ft_lstsize(env) + 1));
	if (!dest)
		return (NULL);
	while (env)
	{
		tmp2 = ft_strdup(env->var[0]);
		tmp = ft_strjoin_char(tmp2, '=');
		if (env->var[1])
			tmp = ft_strjoin(tmp, env->var[1]);
		dest[i] = tmp;
		i++;
		env = env->next;
	}
	dest[i] = NULL;
	return (dest);
}
