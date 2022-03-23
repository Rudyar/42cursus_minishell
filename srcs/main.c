/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:19:49 by arudy             #+#    #+#             */
/*   Updated: 2022/03/23 18:42:24 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*line;
	char	**env_path;
	t_token	*token;

	(void)ac;
	(void)envp;
	(void)av;
	if (ac != 1)
		return (0);
	env_path = get_full_path(envp);
	while (1)
	{
		line = readline("Minishell : ");
		if (line)
		{
			lexer(&token, line);
			free(line);
		}
	}
	return (0);
}
