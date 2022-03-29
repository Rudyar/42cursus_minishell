/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:19:49 by arudy             #+#    #+#             */
/*   Updated: 2022/03/29 18:26:41 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_env	*env;

	(void)av;
	(void)ac;
	env = init_env(envp);
	// export_cmd(av, env);
	unset_cmd(av, env);
	env_cmd(env);
	ft_free(env);
	return (0);
}

// int	main(int ac, char **av, char **envp)
// {
// 	char	*line;
// 	t_env	*env;
// 	t_token	*tokens;

// 	(void)av;
// 	(void)ac;
// 	env = init_env(envp);
// 	tokens = NULL;
// 	while (1)
// 	{
// 		line = readline("Minishell : ");
// 		if (line)
// 		{
// 			if (parsing(line, &tokens) == 0)
// 			{
// 				// exec
// 				free_token_lst(&tokens);
// 			}
// 			free(line);
// 		}
// 	}
// 	ft_free(env);
// 	return (0);
// }

// int	main(int ac, char **av, char **envp)
// {
// 	char	*line;
// 	t_env	*env;
// 	t_token	*tokens;

// 	(void)av;
// 	(void)ac;
// 	// if (ac != 1)
// 		// return (0);
// 	env = init_env(envp);
// 	while (1)
// 	{
// 		line = readline("Minishell : ");
// 		if (line)
// 		{
// 			tokens = lexer(line);
// 			if (tokens != NULL)
// 			{

// 				free(line);
// 				free_token_lst(&tokens);
// 			}
// 		}
// 	}
// 	ft_free(env);
// 	return (0);
// }
