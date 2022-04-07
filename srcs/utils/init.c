/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:22:42 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/07 18:42:17 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_env	*init_env(char **envp)
{
	int		i;
	t_env	*env;
	t_env	*tmp;

	i = 1;
	if (!envp[0])
		return (NULL);
	if (envp[0])
		env = ft_env_lstnew(envp[0], NULL);
	if (envp[i])
	{
		env->next = ft_env_lstnew(envp[i], env);
		i++;
		tmp = env->next;
		while (envp[i])
		{
			tmp->next = ft_env_lstnew(envp[i], tmp);
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
		exit (EXIT_FAILURE);
	}
	data->env = init_env(envp);
	if (data->env)
		data->env_char = dup_env(data->env);
	data->cmd_lst = NULL;
	data->current_path = NULL;
	data->history = NULL;
	data->nb_cmd = 0;
	data->tokens = NULL;
	return (data);
}
