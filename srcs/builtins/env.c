/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:26:20 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/29 16:43:19 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	env_cmd(t_env *env)
{
	int	i;

	i = 1;
	while (env)
	{
		ft_putstr_fd(env->var, 1);
		ft_putstr_fd("\n", 1);
		env = env->next;
	}
	return (0);
}
