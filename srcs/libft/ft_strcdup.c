/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:28:09 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/06 15:31:10 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_strcdup(char *s, char c)
{
	size_t	i;
	size_t	size;
	char	*dest;

	i = 0;
	size = 0;
	while (s && s[size] && s[size] != c)
		size++;
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while (s && s[i] && s[i] != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
