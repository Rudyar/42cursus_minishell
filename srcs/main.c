/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:19:49 by arudy             #+#    #+#             */
/*   Updated: 2022/03/22 13:18:07 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*line;
	char	**env_path;

	(void)av;
	(void)ac;
	(void)envp;
	if (ac != 1)
		return (0);
	env_path = get_full_path(envp);
	// while (1)
	// {
		line = readline("Minishell : ");
		printf("%s\n", line);
		free(line);
	// }
	free_strs(env_path);
	return (0);
}
