/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:19:49 by arudy             #+#    #+#             */
/*   Updated: 2022/04/13 16:12:22 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	(void)av;
	(void)ac;
	data = init_data(envp);
	// for (int i = 0; data->env_char[i]; i++)
		// printf("--- %s\n", data->env_char[i]);
	// pwd_cmd();
	// env_cmd(data);
	printf("===================================================================================\n");
	export_cmd(av, data);
	// unset_cmd(av, data);
	// echo_cmd(av);
	printf("===================================================================================\n");
	env_cmd(data);
	// for (int i = 0; data->env_char[i]; i++)
		// printf("--- %s\n", data->env_char[i]);
	ft_free(data);
	return (0);
}

// void	print_lst(t_cmd *lst)
// {
// 	int	i;

// 	while (lst)
// 	{
// 		i = 0;
// 		printf("---------\n");
// 		while (lst->cmd[i] != NULL)
// 		{
// 			printf("%s\n", lst->cmd[i]);
// 			i++;
// 		}
// 		printf("---------\n");
// 		if (lst->next == NULL)
// 			break ;
// 		lst = lst->next;
// 	}
// }

// int	main(int ac, char **av, char **envp)
// {
// 	char	*line;
// 	t_data	*data;

// 	(void)av;
// 	(void)ac;
// 	data = init_data(envp);
// 	while (1)
// 	{
// 		line = readline("Minishell : ");
// 		if (*line)
// 		{
// 			if (parsing(line, data) == 0)
// 			{
// 				// execve(data->cmd_lst->bin_path, data->cmd_lst->cmd, envp);
// 				// printf("coucouc\n");
// 				// exec
// 				// print_token_lst(&data->tokens);
// 				// print_lst(data->cmd_lst);
// 				free_lst(data);
// 			}
// 		}
// 	}
// 	ft_free(data);
// 	return (0);
// }
