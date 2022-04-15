/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:23:42 by arudy             #+#    #+#             */
/*   Updated: 2022/04/15 11:25:25 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*first_char(char c, t_data *data)
{
	char	*s;

	s = ft_malloc(sizeof(char) * 2, data);
	s[0] = c;
	s[1] = '\0';
	return (s);
}

char	*ft_strjoin_char(char *s, char c, t_data *data)
{
	int		i;
	char	*dst;

	i = 0;
	if (!c)
		return (NULL);
	if (!s)
		return (first_char(c, data));
	dst = ft_malloc(sizeof(char) * (ft_strlen(s) + 2), data);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = c;
	i++;
	dst[i] = '\0';
	ft_free(s, data);
	return (dst);
}
