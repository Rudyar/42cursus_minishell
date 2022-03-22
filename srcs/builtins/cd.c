/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:42:57 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/22 18:59:03 by lleveque         ###   ########.fr       */
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
	void	*dir;

	dir = opendir(path);
	if (!dir)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (1);
	}
	closedir(dir);
	return (0);
}

int	set_home(char **envp)
{
	char	*path;

	path = get_env("HOME=", envp);
	chdir(path);
	free(path);
	return (0);
}

int	set_oldpwd(char **envp)
{
	char	*path;

	path = get_env("OLDPWD=", envp);
	chdir(path);
	free(path);
	return (0);
}

int	cd(char **args, char **envp)
{
	char	*path;

	(void)args;
	if (args[0] && args[1] && args[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (0);
	}
	if (!args[1] || go_home(args[1]))
		return (set_home(envp));
	if (args[1][0] == '-' && args[1][1] == '\0')
		return (set_oldpwd(envp));
	if (check_path(args[1]))
		return (0);
	chdir(args[1]);
	return (0);
}
