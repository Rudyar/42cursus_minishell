/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:36:45 by arudy             #+#    #+#             */
/*   Updated: 2022/04/02 19:09:34 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// char	*exit_dollar_status(void)
// {
// 	printf("Exit dollar status\n");
// 	return (NULL);
// }

// static char	*ft_strjoin_no_free(char *s1, char *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	total_len;
// 	char	*dst;

// 	i = 0;
// 	j = 0;
// 	if (!s1 || !s2)
// 		return (NULL);
// 	total_len = ft_strlen(s1) + ft_strlen(s2);
// 	dst = malloc(sizeof(char) * (total_len + 1));
// 	if (!dst)
// 		return (NULL);
// 	while (s1[i] != '\0')
// 	{
// 		dst[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j] != '\0')
// 		dst[i++] = s2[j++];
// 	dst[i] = '\0';
// 	return (dst);
// }

// static char	*get_env_var(char *s, int *i)
// {
// 	char	*dst;
// 	char	*tmp;
// 	char	*env;

// 	tmp = NULL;
// 	env = NULL;
// 	dst = NULL;
// 	while (s[*i] && s[*i] != ' ' && s[*i] != '$')
// 	{
// 		tmp = ft_strjoin_char(tmp, s[*i]);
// 		(*i)++;
// 	}
// 	env = getenv(tmp);
// 	if (!env)
// 		dst = ft_strjoin_no_free("$", tmp);
// 	else
// 	{
// 		dst = ft_strdup(env);
// 		free(env);
// 	}
// 	free(tmp);
// 	if (s[*i])
// 		i++;
// 	return (dst);
// }

// char	*scan_dollar_var(char *s, int *i)
// {
// 	char	*tmp;
// 	char	*dst;

// 	tmp = NULL;
// 	dst = NULL;
// 	while (s[*i])
// 	{
// 		if (s[*i] == '$')
// 		{
// 			i++;
// 			tmp = get_env_var(s, &i);
// 			if (!dst)
// 				dst = ft_strdup(tmp);
// 			else
// 				dst = ft_strjoin(dst, tmp);
// 			free(tmp);
// 		}
// 		if (s[*i])
// 			dst = ft_strjoin_char(dst, s[*i]);
// 		if (s[*i])
// 			(*i)++;
// 	}
// 	return (dst);
// }

// static char	*get_env_var(char *s, int *i)
// {
// 	char	*dst;
// 	char	*tmp;
// 	char	*env;

// 	tmp = NULL;
// 	env = NULL;
// 	dst = NULL;
// 	while (s[*i] && s[*i] != ' ' && s[*i] != '$')
// 	{
// 		tmp = ft_strjoin_char(tmp, s[*i]);
// 		(*i)++;
// 	}
// 	env = getenv(tmp);
// 	if (!env)
// 		dst = NULL;
// 	else
// 	{
// 		dst = ft_strdup(env);
// 		free(env);
// 	}
// 	free(tmp);
// 	if (s[*i])
// 		(*i)++;
// 	return (dst);
// }

// char	*scan_dollar_var(char *s, int *i)
// {
// 	char	*tmp;
// 	char	*dst;

// 	dst = NULL;
// 	tmp = get_env_var(s, &i);
// 	if (!tmp)
// 		return (NULL);
// 	else
// 		dst = ft_strjoin(dst, tmp);
// 	free(tmp);
// 	return (dst);
// }

// char	*scan_dollar(char *s)
// {
// 	int		i;
// 	char	*dst;

// 	i = 0;
// 	dst = NULL;
// 	while (s[i])
// 	{
// 		if (s[i] == '$')
// 		{
// 			i++;
// 			if (s[i] && s[i] == '?' && s[i + 1] && s[i + 1] == ' ')
// 				dst = (exit_dollar_status());
// 			else
// 				dst = (scan_dollar_var(s, &i));
// 		}
// 		if (s[i])
// 		{
// 			dst = ft_strjoin_char(dst, s[i]);
// 			i++;
// 		}
// 	}
// 	return (dst);
// }
