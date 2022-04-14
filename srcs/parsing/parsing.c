/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:02:20 by arudy             #+#    #+#             */
/*   Updated: 2022/04/14 18:10:49 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_cmd	*parse_cmd(t_data *data, t_token **tokens, int size, t_cmd *new)
{
	int	i;

	i = 0;
	new->cmd = malloc(sizeof(char *) * (size + 1));
	if (!new->cmd)
		return (NULL);
	while (*tokens && (*tokens)->type != PIPE)
	{
		if (*tokens && is_word((*tokens)->type))
		{
			new->cmd[i] = ft_strdup((*tokens)->content);
			*tokens = (*tokens)->next;
			while (*tokens && is_word((*tokens)->type))
			{
				new->cmd[i] = ft_strjoin(new->cmd[i], (*tokens)->content);
				*tokens = (*tokens)->next;
			}
		}
		while (*tokens && ((*tokens)->type == HERE_DOC
			|| (*tokens)->type == DGREATER || (*tokens)->type == REDIR_IN
			|| (*tokens)->type == REDIR_OUT || (*tokens)->type == WHITE_SPACE))
			*tokens = (*tokens)->next;
		i++;
	}
	fill_cmd_data(new, i);
	(void)data;
	if (*tokens)
		printf("yoyoyo : %s\n", (*tokens)->content);
	return (new);
}

t_cmd	*create_cmd_lst(t_data *data, t_token **tokens)
{
	int		size;
	t_token	*head_tokens;
	t_cmd	*head;
	t_cmd	*new;
	t_cmd	*prev;

	head = NULL;
	prev = NULL;
	head_tokens = *tokens;
	while (*tokens)
	{
		size = find_cmd_length(*tokens);
		new = malloc(sizeof(t_cmd));
		if (!new)
			return (NULL);
		new = parse_cmd(data, tokens, size, new);
		if (!new)
			return (NULL);
		cmd_lst_addback(&head, new, prev);
		prev = new;
		if (*tokens)
			*tokens = (*tokens)->next;
	}
	*tokens = head_tokens;
	return (head);
}

int	parsing_return(char *line)
{
	free(line);
	return (1);
}

int	parsing(char *line, t_data *data)
{
	if (first_check(line))
		return (parsing_return(line));
	line = check_line(line);
	if (!line)
		return (1);
	if (lexer(line, &data->tokens))
		return (parsing_return(line));
	if (scan_tokens(data, data->tokens))
		return (parsing_return(line));
	data->cmd_lst = create_cmd_lst(data, &data->tokens);
	if (!data->cmd_lst)
		return (parsing_return(line));
	// check_builtins(data->cmd_lst);
	// create_bin_path(data, data->cmd_lst);
	free(line);
	return (0);
}
