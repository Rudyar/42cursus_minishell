/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:41:53 by arudy             #+#    #+#             */
/*   Updated: 2022/04/04 18:29:26 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_getenv(t_env *env, char *s)
{
	while (env)
	{
		if (env->var && !ft_strcmp(env->var[0], s))
			return (env->var[1]);
		env = env->next;
	}
	return (NULL);
}

int	find_cmd_length(t_token *lst)
{
	int	i;

	i = 0;
	while (lst && lst->type != PIPE)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	count_nb_cmd(t_token **lst)
{
	int	i;

	i = 1;
	while (*lst)
	{
		if ((*lst)->type == PIPE)
			i++;
		lst = &(*lst)->next;
	}
	return (i);
}

int	check_line(char *s)
{
	int	i;
	int	j;

	i = ft_strlen(s);
	j = 0;
	while (s[j] == ' ')
		j++;
	if (j == i)
		return (1);
	return (0);
}
