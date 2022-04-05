/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:26:20 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/04 19:27:24 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	env_cmd(t_env *env)
{
	while (env)
	{
		if (env->var[0])
		{
			ft_putstr_fd(env->var[0], 1);
			ft_putstr_fd("=", 1);
			if (env->var[1])
				ft_putstr_fd(env->var[1], 1);
			ft_putstr_fd("\n", 1);
		}
		env = env->next;
	}
	return (0);
}
