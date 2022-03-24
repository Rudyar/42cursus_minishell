/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:19:49 by arudy             #+#    #+#             */
/*   Updated: 2022/03/24 19:35:42 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **av, char **envp)
{
	// char	*line;
	// char	**env_path;
	t_env	*env;
	// t_token	*token;

	(void)ac;
	(void)envp;
	(void)av;
	(void)envp;
	if (ac != 1)
		return (0);
	env = init_env(envp);
	// env_path = get_full_path(envp);
	// while (1)
	// {
	// 	line = readline("Minishell : ");
	// 	if (line)
	// 	{
	// 		lexer(&token, line);
	// 		free(line);
	// 	}
	// }
	// free_strs(env_path);
	ft_free(env);
	return (0);
}

// int	main(int ac, char **av, char **envp)
// {
// 	char	*line;
// 	t_token	*token;

// 	(void)av;
// 	(void)envp;
// 	if (ac != 1)
// 		return (0);
// 	line = "Salut ca va ?''$$";
// 	lexer(&token, line);
// 	return (0);
// }
