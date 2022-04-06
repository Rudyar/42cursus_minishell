/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:03:17 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/06 19:13:18 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*name_without_plus(char *s)
{
	int		i;
	char	*dest;

	i = 0;
	if (!s)
		return (NULL);
	dest = malloc(sizeof(char) * ft_strlen(s));
	if (!dest)
		return (NULL);
	while (s[i] && s[i] != '+')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	free(s);
	return (dest);
}
