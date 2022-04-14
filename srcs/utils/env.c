/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:54:28 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/14 10:30:02 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**dup_env(t_env *env)
{
	int		i;
	char	**dest;
	char	*tmp;

	i = 0;
	dest = malloc(sizeof(char *) * (ft_lstsize(env) + 1));
	if (!dest)
		return (NULL);
	while (env)
	{
		tmp = ft_strjoin_char(env->var[0], '=');
		if (env->var[1])
			tmp = ft_strjoin(tmp, env->var[1]);
		dest[i] = tmp;
		i++;
		env = env->next;
	}
	dest[i] = NULL;
	return (dest);
}
