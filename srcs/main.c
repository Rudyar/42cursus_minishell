/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:19:49 by arudy             #+#    #+#             */
/*   Updated: 2022/04/27 19:09:27 by lleveque         ###   ########.fr       */
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
	t_data	*data;

	(void)av;
	(void)ac;
	data = init_data(envp);
	loop(data, envp);
	free_all(data);
	return (g_exit_status);
}
