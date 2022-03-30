/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:19:49 by arudy             #+#    #+#             */
/*   Updated: 2022/03/30 16:37:37 by lleveque         ###   ########.fr       */
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
	t_data	*data;

	(void)av;
	(void)ac;
	data = init_data(envp);
	while (1)
	{
		line = readline("Minishell : ");
		if (*line)
		{
			if (parsing(line, data) == 0)
			{
				// exec
				// print_token_lst(&data->tokens);
				free_token_lst(&data->tokens);
			}
			free(line);
		}
	}
	ft_free(data);
	return (0);
}
