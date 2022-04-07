/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:52:38 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/06 15:33:29 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static size_t	malloc_size(char const *s, size_t i, char c)
{
	size_t	size;

	size = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

static size_t	mine_substr(char const *s, size_t i, char *strs, char c)
{
	size_t	j;

	if (!s)
		return (0);
	j = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		strs[j] = s[i];
		i++;
		j++;
	}
	strs[j] = '\0';
	return (i);
}

char	**split_copy(char *s, char **strs, char c, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && j < n)
	{
		if (j == n - 1)
			strs[j] = malloc(sizeof(char) * (malloc_size(s, i, 0) + 1));
		else
			strs[j] = malloc(sizeof(char) * (malloc_size(s, i, c) + 1));
		if (!strs[j])
		{
			ft_free_split(strs);
			return (NULL);
		}
		if (j == n - 1)
			i = mine_substr(s, i, strs[j], 0);
		else
			i = mine_substr(s, i, strs[j], c);
		i++;
		j++;
	}
	return (strs);
}

char	**ft_nsplit(char *s, char c, size_t n)
{
	char	**strs;
	int		i;

	i = 0;
	strs = malloc(sizeof(char *) * (n + 1));
	if (!strs || !s)
		return (NULL);
	strs = split_copy(s, strs, c, n);
	strs[n] = 0;
	return (strs);
}
