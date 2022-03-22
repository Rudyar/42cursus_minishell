/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:29:09 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/22 18:30:36 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_env(char *var, char **envp)
{
	int		i;
	char	*value;

	i = 0;
	value = NULL;
	while (envp[i])
	{
		if (!ft_strncmp(var, envp[i], ft_strlen(var) - 1))
		{
			value = ft_substr(envp[i], ft_strlen(var), ft_strlen(envp[i]));
			if (!value)
			{
				ft_putstr_fd("Substr problem\n", 2);
				return (NULL);
				// EXIT FREE
			}
			break ;
		}
		i++;
	}
	if (!value)
		return (NULL);
	return (value);
}
