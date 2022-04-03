/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:36:45 by arudy             #+#    #+#             */
/*   Updated: 2022/04/03 11:49:58 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*exit_dollar_status(void)
{
	printf("Exit dollar status\n");
	return (NULL);
}

static char	*join_tmp(char *s1, char *s2)
{
	char	*dst;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	dst = ft_strjoin(s1, s2);
	if (!dst)
		return (NULL);
	free(s2);
	return (dst);
}

static char	*get_env_var(char *s, int *i)
{
	char	*dst;
	char	*tmp;
	char	*env;

	tmp = NULL;
	env = NULL;
	dst = NULL;
	while (s[*i] && s[*i] != ' ' && s[*i] != '$')
	{
		tmp = ft_strjoin_char(tmp, s[*i]);
		(*i)++;
	}
	env = getenv(tmp);
	if (!env)
		dst = NULL;
	else
		dst = ft_strdup(env);
	free(tmp);
	if (s[*i] && s[*i] != '$' && s[*i] != ' ')
		(*i)++;
	return (dst);
}

char	*scan_dollar(char *s)
{
	int		i;
	char	*dst;
	char	*tmp;

	i = 0;
	dst = NULL;
	while (s[i])
	{
		if (s[i] == '$')
		{
			i++;
			if (s[i] && s[i] == '?' && ((s[i + 1] && s[i + 1] == ' ')
					|| !s[i + 1]))
				tmp = (exit_dollar_status());
			else
				tmp = (get_env_var(s, &i));
			dst = join_tmp(dst, tmp);
			continue ;
		}
		if (s[i])
			dst = ft_strjoin_char(dst, s[i++]);
	}
	return (dst);
}
