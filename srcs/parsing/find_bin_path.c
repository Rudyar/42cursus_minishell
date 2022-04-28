/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bin_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:23:25 by arudy             #+#    #+#             */
/*   Updated: 2022/04/28 15:38:23 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	**add_cmd_error(char **path, t_data *data)
{
	free_strs(path, data);
	return (NULL);
}

static char	**add_cmd(t_data *data, char *cmd)
{
	int		i;
	char	**path;

	i = 0;
	path = ft_split(ft_getenv(data->env, "PATH"), ':', data);
	if (!path)
		return (add_cmd_error(path, data));
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/", data);
		if (!path[i])
			return (add_cmd_error(path, data));
		path[i] = ft_strjoin(path[i], cmd, data);
		if (!path[i])
			return (add_cmd_error(path, data));
		i++;
	}
	return (path);
}

static int	find_bin_path(t_data *data, t_cmd *lst)
{
	int		i;
	char	**path;

	i = 0;
	path = add_cmd(data, lst->cmd[0]);
	if (!path)
		return (1);
	while (path[i])
	{
		if (access(path[i], F_OK) == 0)
		{
			lst->bin_path = ft_strdup(path[i], data);
			free_strs(path, data);
			return (0);
		}
		i++;
	}
	free_strs(path, data);
	return (127);
}

int	create_bin_path(t_data *data, t_cmd *lst)
{
	if (access(lst->cmd[0], F_OK) == 0)
		lst->bin_path = ft_strdup(lst->cmd[0], data);
	else
		return (find_bin_path(data, lst));
	return (0);
}
