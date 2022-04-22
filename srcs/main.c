/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:19:49 by arudy             #+#    #+#             */
/*   Updated: 2022/04/22 12:53:04 by arudy            ###   ########.fr       */
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

int	main(int ac, char **av, char **envp)
{
	char	*line;
	t_data	*data;
	// char *tmp;
	// int len;

	(void)av;
	(void)ac;
	data = init_data(envp);
	while (1)
	{
		// if ((tmp = ft_getenv(data->env, "USER")))
		// {
		// 	ft_putstr_fd("\033[32;1m", 1);
		// 	ft_putstr_fd(tmp, 1);
		// 	ft_putstr_fd("@\033[0m:", 1);
		// 	free(tmp);
		// }
		// tmp = getcwd(NULL, 0);
		// len = ft_strlen(tmp);
		// // count_slash = 0;
		// // while (--len && count_slash < 3)
		// 	// if (tmp[len] == '/')
		// 		// count_slash++;
		// ft_putstr_fd("\e[1;34m", 1);
		// // while (tmp[++len])
		// 	ft_putstr_fd(tmp, 1);
		// ft_putstr_fd("$\e[0m ", 1);
		// free(tmp);
		line = readline("miniminimini : ");
		if (*line)
		{
			add_history(line);
			if (parsing(line, data) == 0)
			{
				start_exec(data->cmd_lst, data);
				free_lst(data);
			}
		}
	}
	free_all(data);
	return (0);
}
