/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:42:32 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/24 15:39:39 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	export(char **args, char ***envp)
{
	int	i;

	i = 1;

	// while (args[i])
	// {
		*envp = ft_strsjoin(*envp, args[i]);
	// 	i++;
	// }
	(void)envp;
	(void)args;
	return (0);
}

int main(int ac, char **av, char **envp)
{
	(void)ac;
	export(av, &envp);
	int i = 0;
	// while (envp[i])
	// {
	// 	printf("%s\n", envp[i]);
	// 	i++;
	// }
	i = 0;
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	// printf("%d\n", i);
	free(envp);
	return (0);
}
