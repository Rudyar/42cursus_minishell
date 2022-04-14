/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:36:45 by arudy             #+#    #+#             */
/*   Updated: 2022/04/14 10:27:06 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*exit_dollar_status(char *s)
{
	char	*dst;

	dst = NULL;
	(void)s;
	printf("Exit dollar status\n");
	return (dst);
}

static char	*copy_dollar(char *s, int *i)
{
	int		j;
	int		len;
	char	*dst;

	j = 0;
	len = 0;
	while (s[*i] && s[*i] == '$')
	{
		len++;
		(*i)++;
	}
	dst = malloc(sizeof(char) * (len + 2));
	if (!dst)
		return (NULL);
	dst[0] = '$';
	while (j++ < len)
		dst[j] = '$';
	dst[j] = '\0';
	return (dst);
}

static char	*get_env_var(t_data *data, char *s, int *i)
{
	char	*dst;
	char	*tmp;
	char	*env;

	tmp = NULL;
	dst = NULL;
	if (s[*i] && !ft_isalpha(s[*i]) && s[*i] != '{'
		&& s[*i] != '}' && s[*i] != '_')
		return (get_env_var_return(i));
	while (check_next_char_dollar(s, i))
	{
		if (s[*i] != '{' && s[*i] != '}')
			tmp = ft_strjoin_char(tmp, s[*i]);
		if (s[*i] == '}')
		{
			(*i)++;
			break ;
		}
		(*i)++;
	}
	env = ft_getenv(data->env, tmp);
	if (env)
		dst = ft_strdup(env);
	free(tmp);
	return (dst);
}

static char	*find_dollar_value(t_data *data, char *s, int i)
{
	char	*dst;
	char	*tmp;

	dst = NULL;
	while (s[i])
	{
		if (s[i] == '$')
		{
			i++;
			if (s[i] && s[i] == '?' && ((s[i + 1] && s[i + 1] == ' ')
					|| !s[i + 1]))
				tmp = (exit_dollar_status(s));
			else if (!s[i] || (s[i] && (s[i] == '$' || s[i] == ' ')))
				tmp = copy_dollar(s, &i);
			else
				tmp = get_env_var(data, s, &i);
			dst = join_tmp(dst, tmp);
			continue ;
		}
		if (s[i])
			dst = ft_strjoin_char(dst, s[i++]);
	}
	if (i == 0)
		return (s);
	return (dst);
}

int	scan_dollar(t_data *data, t_token *lst)
{
	int	i;

	while (lst)
	{
		i = 0;
		if (lst->type == IN_DQUOTE || lst->type == DOLLAR)
			lst->content = find_dollar_value(data, lst->content, i);
		lst = lst->next;
	}
	(void)data;
	return (0);
}
