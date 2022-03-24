/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:51:33 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/24 16:22:30 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**ft_strsjoin(char **tab, char *s)
{
	int		i;
	int		j;
	char	**dest;

	i = 0;
	j = 0;
	if (!tab || !s)
		return (NULL);
	while (tab[j])
	{
		if (ft_strchr(tab[j], '='))
			i++;
		j++;
	}
	printf("%d\n", i);
	dest = malloc(sizeof(char *) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (tab && tab[i])
	{
		if (ft_strchr(tab[j], '='))
		{
			dest[i] = ft_strdup(tab[j]);
			printf("%d\n", j);
			printf("%s\n", tab[j]);
			i++;
		}
		j++;
	}
	dest[i] = ft_strdup(s);
	return (dest);
}
