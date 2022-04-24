/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:19:49 by arudy             #+#    #+#             */
/*   Updated: 2022/04/24 12:41:32 by arudy            ###   ########.fr       */
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

int	exit_line(char *line, t_data *data)
{
	free_all(data);
	free(line);
	printf("exit\n");
	exit(0);
}

int	loop(t_data *data, char **envp)
{
	char	*line;
	char	*prompt;

	while (1)
	{
		prompt = get_prompt(data, envp);
		line = readline(prompt);
		ft_free(prompt, data);
		if (*line)
		{
			add_history(line);
			if (ft_strcmp(line, "exit") == 0)
				return (exit_line(line, data));
			if (parsing(line, data) == 0)
			{
				start_exec(data->cmd_lst, data);
				free_lst(data);
			}
		}
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	(void)av;
	(void)ac;
	data = init_data(envp);
	loop(data, envp);
	free_all(data);
	return (0);
}
