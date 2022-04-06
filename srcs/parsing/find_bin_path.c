/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bin_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:23:25 by arudy             #+#    #+#             */
/*   Updated: 2022/04/06 12:13:37 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	**add_cmd_error(int n, char **path)
{
	if (n == 1)
	{
		ft_putstr_fd("Split problem in add_cmd\n", 2);
		return (NULL);
	}
	if (n == 2)
		ft_putstr_fd("Join problem in add_cmd\n", 2);
	free_strs(path);
	return (NULL);
}

static char	**add_cmd(t_data *data, char *cmd)
{
	int		i;
	char	**path;

	i = 0;
	path = ft_split(ft_getenv(data->env, "PATH"), ':');
	if (!path)
		return (add_cmd_error(1, path));
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		if (!path[i])
			return (add_cmd_error(2, path));
		path[i] = ft_strjoin(path[i], cmd);
		if (!path[i])
			return (add_cmd_error(2, path));
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
			lst->bin_path = ft_strdup(path[i]);
			free_strs(path);
			return (0);
		}
		i++;
	}
	ft_putstr_fd(lst->cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	free_strs(path);
	return (1);
}

void	create_bin_path(t_data *data, t_cmd *lst)
{
	while (lst)
	{
		if (access(lst->cmd[0], F_OK) == 0)
			lst->bin_path = ft_strdup(lst->cmd[0]);
		else
			find_bin_path(data, lst);
		printf("bin path : %s\n", lst->bin_path);
		lst = lst->next;
	}
}
