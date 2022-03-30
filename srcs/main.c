/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:19:49 by arudy             #+#    #+#             */
/*   Updated: 2022/03/30 11:54:26 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// int	main(int ac, char **av, char **envp)
// {
// 	t_env	*env;

// 	(void)av;
// 	(void)ac;
// 	env = init_env(envp);
// 	// export_cmd(av, env);
// 	unset_cmd(av, env);
// 	env_cmd(env);
// 	ft_free(env);
// 	return (0);
// }

int	main(int ac, char **av, char **envp)
{
	char	*line;
	t_env	*env;
	t_token	*tokens;
	t_data	data;

	(void)av;
	(void)ac;
	env = init_env(envp);
	tokens = NULL;
	while (1)
	{
		line = readline("Minishell : ");
		if (line)
		{
			if (parsing(line, &tokens, &data) == 0)
			{
				// exec
				// print_token_lst(&tokens);
				printf("%d\n", data.nb_cmd);
				free_token_lst(&tokens);
			}
			free(line);
		}
	}
	ft_free(env);
	return (0);
}
