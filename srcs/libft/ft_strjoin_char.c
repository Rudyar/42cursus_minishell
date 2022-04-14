/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:23:42 by arudy             #+#    #+#             */
/*   Updated: 2022/04/14 12:38:18 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*first_char(char c)
{
	char	*s;

	s = malloc(sizeof(char) * 2);
	if (!s)
		return (NULL);
	s[0] = c;
	s[1] = '\0';
	return (s);
}

char	*ft_strjoin_char(char *s, char c)
{
	int		i;
	char	*dst;

	i = 0;
	if (!c)
		return (NULL);
	if (!s)
		return (first_char(c));
	dst = malloc(sizeof(char) * (ft_strlen(s) + 2));
	if (!dst)
		return (NULL);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = c;
	dst[i + 1] = '\0';
	return (dst);
}
