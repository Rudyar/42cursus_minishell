/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:22:42 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/19 16:46:11 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_exit_status;

t_env	*init_env(char **envp, t_data *data)
{
	int		i;
	t_env	*env;
	t_env	*tmp;

	i = 1;
	if (!envp[0])
		return (NULL);
	env = ft_env_lstnew(envp[0], NULL, data);
	if (envp[i])
	{
		env->next = ft_env_lstnew(envp[i], env, data);
		i++;
		tmp = env->next;
		while (envp[i])
		{
			tmp->next = ft_env_lstnew(envp[i], tmp, data);
			tmp = tmp->next;
			i++;
			if (!envp[i])
				tmp->next = NULL;
		}
	}
	else
		env->next = NULL;
	return (env);
}

t_data	*init_data(char **envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		ft_putstr_fd("minishell: can't malloc data\n", 2);
		exit(EXIT_FAILURE);
	}
	data->garbage = malloc(sizeof(t_garbage));
	if (!data->garbage)
	{
		ft_putstr_fd("minishell: can't malloc data\n", 2);
		free(data);
		exit(EXIT_FAILURE);
	}
	data->garbage->ptr = NULL;
	data->env = init_env(envp, data);
	data->env_char = dup_env(data->env, data);
	data->cmd_lst = NULL;
	data->current_path = NULL;
	data->history = NULL;
	data->nb_cmd = 0;
	data->tokens = NULL;
	g_exit_status = 0;
	return (data);
}
