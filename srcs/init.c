/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:22:42 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/29 17:44:35 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env	*init_env(char **envp)
{
	int		i;
	t_env	*env;
	t_env	*tmp;

	i = 1;
	env = NULL;
	if (envp[0])
		env = ft_env_lstnew(envp[0], env);
	if (envp[i])
	{
		env->next = ft_env_lstnew(envp[i], env);
		i++;
		tmp = env->next;
		while (envp[i])
		{
			tmp->next = ft_env_lstnew(envp[i], tmp);
			tmp = tmp->next;
			i++;
			if (!envp[i])
				tmp->next = NULL;
		}
	}
	else
		env->next = NULL;
	return (env);
}
