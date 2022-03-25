/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:19:49 by arudy             #+#    #+#             */
/*   Updated: 2022/03/25 17:33:49 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*line;
	t_env	*env;
	t_token	*tokens;

	(void)av;
	if (ac != 1)
		return (0);
	env = init_env(envp);
	while (1)
	{
		line = readline("Minishell : ");
		if (line)
		{
			tokens = lexer(line);
			free(line);
			// print_token_lst(&tokens);
			free_token_lst(&tokens);
		}
	}
	ft_free(env);
	return (0);
}
