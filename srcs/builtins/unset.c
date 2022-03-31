/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:37:01 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/31 19:48:31 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_unset_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg)
	{
		if (!ft_isalpha(arg[0]))
			return (1);
		while (arg[i])
		{
			if (!ft_isalpha(arg[i]) && !ft_isdigit(arg[i]) && arg[i] != '_')
				return (1);
			i++;
		}
	}
	return (0);
}

int	unset_cmd(char **args, t_env *env)
{
	int		i;
	t_env	*tmp;

	i = 1;
	while (args[i])
	{
		while (args[i] && check_unset_arg(args[i]))
		{
			ft_putstr_fd("minishell: unset : `", 1);
			ft_putstr_fd(args[i], 1);
			ft_putstr_fd("': not a valid identifier\n", 1);
			i++;
		}
		if (!args[i])
			break ;
		while (env->next)
		{
			if (env->var[0] && !ft_strcmp(env->var[0], args[i]))
			{
				tmp = env;
				env->prev->next = env->next;
				env->next->prev = env->prev;
				env = env->next;
				free(tmp);
			}
			else
				env = env->next;
		}
		while (env->prev)
			env = env->prev;
		i++;
	}
	return (0);
}
