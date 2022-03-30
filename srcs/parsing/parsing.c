/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:02:20 by arudy             #+#    #+#             */
/*   Updated: 2022/03/30 18:50:03 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_cmd	*parse_cmd(t_token *tokens, t_data *data)
{
	(void)data;
	int	i;
	int	cmd_length;
	t_cmd	*new;

	i = 0;
	cmd_length = find_cmd_length(tokens);
	new = malloc(sizeof(t_cmd));
	new->cmd = malloc(sizeof(char *) * (i + 1));
	if (!new->cmd)
		return (NULL);
	while (j < i)
	{
		new->cmd[j] = ft_strdup((*tokens)->content);
		printf("%s\n", new->cmd[j]);
		j++;
	}
	new->cmd[j] = 0;
	return (new);
}

t_cmd	*create_cmd_lst(t_data *data)
{
	t_cmd	*lst;
	// t_cmd	*new;

	lst = parse_cmd(&data->tokens, data);
	return (lst);
}

int	parsing(char *line, t_data *data)
{
	if (first_check(line) || check_line(line))
		return (1);
	if (lexer(line, &data->tokens))
		return (1);
	data->nb_cmd = count_nb_cmd(&data->tokens);
	data->cmd_lst = create_cmd_lst(data);
	return (0);
}
