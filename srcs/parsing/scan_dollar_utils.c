/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_dollar_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:12:52 by arudy             #+#    #+#             */
/*   Updated: 2022/04/15 11:26:35 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*join_tmp(char *s1, char *s2, t_data *data)
{
	char	*dst;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	dst = ft_strjoin(s1, s2, data);
	if (!dst)
		return (NULL);
	ft_free(s2, data);
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
