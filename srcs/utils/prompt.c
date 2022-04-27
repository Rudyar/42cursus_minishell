/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:41:07 by arudy             #+#    #+#             */
/*   Updated: 2022/04/27 15:21:51 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*prompt_without_env(t_data *data)
{
	char	*prompt;
	char	cwd[1024];

	getcwd(cwd, sizeof(cwd));
	prompt = ft_strdup(cwd, data);
	prompt = ft_strjoin(prompt, "$ ", data);
	return (prompt);
}

char	*home_prompt(char *prompt, char *cwd, char *home, t_data *data)
{
	if (!ft_strncmp(cwd, home, ft_strlen(home)))
	{
		prompt = ft_strjoin_char(prompt, '~', data);
		cwd = ft_substr(cwd, ft_strlen(home), ft_strlen(cwd), data);
		prompt = ft_strjoin(prompt, cwd, data);
	}
	else
		prompt = ft_strjoin(prompt, cwd, data);
	ft_free(cwd, data);
	return (prompt);
}

char	*get_prompt(t_data *data, char **envp)
{
	char	s[1024];
	char	*cwd;
	char	*prompt;
	char	*user;
	char	*home;

	getcwd(s, sizeof(s));
	cwd = ft_strdup(s, data);
	user = ft_strdup(ft_getenv(data->env, "USER"), data);
	home = ft_strdup(ft_getenv(data->env, "HOME"), data);
	if (!user || !home || !envp[0])
		return (prompt_without_env(data));
	prompt = ft_strdup("\001\033[1;32m\002", data);
	prompt = ft_strjoin(prompt, user, data);
	prompt = ft_strjoin(prompt, "@minishell\001\033[0m\002", data);
	prompt = ft_strjoin_char(prompt, ':', data);
	prompt = ft_strjoin(prompt, "\001\033[1;36m\002", data);
	prompt = home_prompt(prompt, cwd, home, data);
	prompt = ft_strjoin(prompt, "\001\033[0m\002", data);
	prompt = ft_strjoin(prompt, "$ ", data);
	return (prompt);
}
