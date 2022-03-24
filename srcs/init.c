/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:22:42 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/24 18:27:53 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env *ft_env_lstnew(char *content)
{
	t_env	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->var = content;
	new->next = NULL;
	return (new);
}

t_env *init_env(char **envp)
{
	int		i;
	t_env	*env;
	t_env	*tmp;

	i = 1;
	if (envp[0])
		env = ft_env_lstnew(envp[0]);
	if (envp[i])
	{
		env->next = ft_env_lstnew(envp[i]);
		i++;
		tmp = env->next;
		while (envp[i])
		{
			tmp->next = ft_env_lstnew(envp[i]);
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
