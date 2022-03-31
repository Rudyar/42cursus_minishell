/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:26:20 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/31 19:10:08 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	env_cmd(t_env *env)
{
	int	i;

	while (env)
	{
		i = 0;
		while (env->var[i])
		{
			ft_putstr_fd(env->var[i], 1);
			++i;
		}
		ft_putstr_fd("\n", 1);
		env = env->next;
	}
	return (0);
}
