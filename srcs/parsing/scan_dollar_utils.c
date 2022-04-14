/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_dollar_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:12:52 by arudy             #+#    #+#             */
/*   Updated: 2022/04/14 10:29:20 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*join_tmp(char *s1, char *s2)
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

int	check_next_char_dollar(char *s, int *i)
{
	if (s[*i] && (ft_isalpha(s[*i]) || ft_isdigit(s[*i]) || s[*i] == '{'
			|| s[*i] == '}' || s[*i] == '_'))
		return (1);
	return (0);
}

char	*get_env_var_return(int *i)
{
	(*i)++;
	return (NULL);
}
