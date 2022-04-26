/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bin_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:23:25 by arudy             #+#    #+#             */
/*   Updated: 2022/04/26 12:40:46 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	**add_cmd_error(int n, char **path, t_data *data)
{
	if (n == 1)
	{
		ft_putstr_fd("Split problem in add_cmd\n", 2);
		return (NULL);
	}
	if (n == 2)
		ft_putstr_fd("Join problem in add_cmd\n", 2);
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
		return (add_cmd_error(1, path, data));
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/", data);
		if (!path[i])
			return (add_cmd_error(2, path, data));
		path[i] = ft_strjoin(path[i], cmd, data);
		if (!path[i])
			return (add_cmd_error(2, path, data));
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
