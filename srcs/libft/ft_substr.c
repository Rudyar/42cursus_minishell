/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:15:19 by arudy             #+#    #+#             */
/*   Updated: 2022/04/15 11:25:42 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static size_t	malloc_size(char const *s, unsigned int start, size_t len)
{
	size_t	size;

	size = 0;
	if (start > ft_strlen(s))
		return (size);
	while (s[start] && size < len)
	{
		size++;
		start++;
	}
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len, t_data *data)
{
	size_t	i;
	size_t	size;
	char	*dst;

	if (!s)
		return (NULL);
	i = 0;
	size = malloc_size(s, start, len);
	dst = ft_malloc(sizeof(char) * (size + 1), data);
	while (i < size && s[start])
		dst[i++] = s[start++];
	dst[i] = '\0';
	return (dst);
}
