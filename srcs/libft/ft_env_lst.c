/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:05:20 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/04 19:23:18 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_env	*ft_env_lstnew(char *content, t_env *prev)
{
	t_env	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->prev = prev;
	new->var = ft_nsplit(content, '=', 2);
	new->next = NULL;
	return (new);
}

void	ft_env_addback(t_env *env, t_env *new)
{
	while (env->next)
		env = env->next;
	env->next = new;
}
