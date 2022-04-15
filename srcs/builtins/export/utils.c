/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:03:17 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/15 11:23:53 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*name_without_plus(char *s, t_data *data)
{
	int		i;
	char	*dest;

	i = 0;
	if (!s)
		return (NULL);
	dest = ft_malloc(sizeof(char) * ft_strlen(s), data);
	while (s[i] && s[i] != '+')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// void	print_export(t_env *env)
// {
// 	char	**tmp;
// 	int		diff;

// 	diff = ft_strcmp(env->var[0], env->next->var[0]);
// 	env = env->next;
// 	while (env->next)
// 	{
// 		if (ft_strcmp(env->var, env->next->var) <)
// 	}
// }
