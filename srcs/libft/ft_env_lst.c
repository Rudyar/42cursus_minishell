/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:05:20 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/14 13:00:02 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**var_without_value(char *content)
{
	char	**var;

	var = malloc(sizeof(char *) * 2);
	var[0] = ft_strcdup(content, '=');
	var[1] = NULL;
	return (var);
}

t_env	*ft_env_lstnew(char *content, t_env *prev)
{
	int		i;
	t_env	*new;

	i = 0;
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->prev = prev;
	while (content[i] && content[i] != '=')
		i++;
	if (!content[i] || !content[i + 1])
		new->var = var_without_value(content);
	else
		new->var = ft_nsplit(content, '=', 2);
	new->next = NULL;
	return (new);
}

void	ft_env_addback(t_env *env, t_env *new)
{
	while (env->next)
		env = env->next;
	new->prev = env;
	env->next = new;
}
