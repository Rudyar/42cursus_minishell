/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:41:53 by arudy             #+#    #+#             */
/*   Updated: 2022/04/07 16:34:08 by arudy            ###   ########.fr       */
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

static char	*trim_line(char *s)
{
	int				i;
	int				j;
	int				k;
	unsigned int	size;
	char			*ret;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	k = 0;
	while (ft_is_whitespace(s[i]))
		i++;
	while (ft_is_whitespace(s[j]) && j > i)
		j--;
	size = j - i;
	ret = malloc(sizeof(char) * (size + 2));
	if (!ret)
		return (NULL);
	while (i <= j)
		ret[k++] = s[i++];
	ret[k] = '\0';
	return (ret);
}

char	*check_line(char *s)
{
	int		i;
	int		j;
	char	*dst;

	i = ft_strlen(s);
	j = 0;
	dst = NULL;
	while (ft_is_whitespace(s[j]))
		j++;
	if (j == i)
		return (NULL);
	dst = trim_line(s);
	free(s);
	return (dst);
}
