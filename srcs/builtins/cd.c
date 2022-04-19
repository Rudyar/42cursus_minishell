/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:42:57 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/19 13:48:27 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	go_home(char *path)
{
	if ((path[0] == '~' && path[1] == '\0')
		|| (path[0] == '-' && path[1] == '-' && path[2] == '\0'))
		return (1);
	return (0);
}

int	check_path(char *path)
{
	void		*dir;
	struct stat	st;

	dir = opendir(path);
	if (dir)
	{
		closedir(dir);
		return (0);
	}
	closedir(dir);
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(path, 2);
	if (stat(path, &st) == -1)
		ft_putstr_fd(": No such file or directory\n", 2);
	else if (S_ISDIR(st.st_mode))
		ft_putstr_fd(": Permission denied\n", 2);
	else
		ft_putstr_fd(": Not a directory\n", 2);
	return (1);
}

int	set_home(t_data *data)
{
	char	*path;

	path = ft_getenv(data->env, "HOME=");
	if (!path)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (0);
	}
	chdir(path);
	free(path);
	return (0);
}

int	set_oldpwd(t_data *data)
{
	char	*path;

	path = ft_getenv(data->env, "OLDPWD=");
	if (!path)
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
		return (0);
	}
	chdir(path);
	free(path);
	return (0);
}

int	cd_cmd(char **args, t_data *data)
{
	if (args[0] && args[1] && args[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (0);
	}
	if (!args[1] || (args(args[1][0] == '~' && args[1][1] == '\0')
		|| (args[1][0] == '-' && args[1][1] == '-' && args[1][2] == '\0')))
		return (set_home(data));
	if (args[1][0] == '-' && args[1][1] == '\0')
		return (set_oldpwd(data));
	if (check_path(args[1]))
		return (0);
	chdir(args[1]);
	return (0);
}
