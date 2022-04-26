/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:19:49 by arudy             #+#    #+#             */
/*   Updated: 2022/04/26 15:26:14 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	g_exit_status;

// int	main(int ac, char **av, char **envp)
// {
// 	t_data	*data;
// 	(void)av;
// 	(void)ac;
// 	(void)envp;
// 	data = init_data(envp);
// 	// pwd_cmd();
// 	printf("=========================================================\n");
// 	// export_cmd(av, data);
// 	cd_cmd(av, data);
// 	// unset_cmd(av, data);
// 	// echo_cmd(av);
// 	printf("=========================================================\n");
// 	env_cmd(data);
// 	// for (int i = 0; data->env_char[i]; i++)
// 		// printf("--- %s\n", data->env_char[i]);
// 	free_all(data);
// 	return (0);
// }

int	loop(t_data *data, char **envp)
{
	char	*line;
	char	*prompt;

	while (1)
	{
		prompt = get_prompt(data, envp);
		line = readline(prompt);
		if (!line)
			break ;
		ft_free(prompt, data);
		if (*line)
		{
			add_history(line);
			if (parsing(line, data) == 0)
			{
				if (data->nb_cmd == 1 && check_builtins(data->cmd_lst))
					g_exit_status = exec_builtins(data->cmd_lst, data);
				else
					start_exec(data->cmd_lst, data);
				free_lst(data);
			}
		}
	}
	printf("exit\n");
	return (g_exit_status);
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	(void)av;
	(void)ac;
	data = init_data(envp);
	loop(data, envp);
	free_all(data);
	return (g_exit_status);
}
