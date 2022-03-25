/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:19:49 by arudy             #+#    #+#             */
/*   Updated: 2022/03/25 09:48:57 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*line;
	t_env	*env;
	t_token	*token;

	(void)av;
	if (ac != 1)
		return (0);
	env = init_env(envp);
	while (1)
	{
		line = readline("Minishell : ");
		if (line)
		{
			lexer(&token, line);
			free(line);
		}
	}
	ft_free(env);
	return (0);
}
