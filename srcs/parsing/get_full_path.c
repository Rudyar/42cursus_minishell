/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:08:45 by arudy             #+#    #+#             */
/*   Updated: 2022/03/22 12:45:23 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	get_full_path_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit (EXIT_FAILURE);
}

char	**get_full_path(char **envp)
{
	int		i;
	char	*full_path;
	char	**path_splited;

	i = 0;
	full_path = NULL;
	while (envp[i++])
	{
		if (!ft_strncmp("PATH=", envp[i], 4))
		{
			full_path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			if (!full_path)
				get_full_path_error("Substr problem\n");
			break ;
		}
	}
	if (!full_path)
		get_full_path_error("Can't find PATH in envp\n");
	path_splited = ft_split(full_path, ':');
	free(full_path);
	if (!path_splited)
		get_full_path_error("Can't split PATH\n");
	return (path_splited);
}
