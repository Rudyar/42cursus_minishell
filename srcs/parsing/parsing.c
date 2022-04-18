/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:02:20 by arudy             #+#    #+#             */
/*   Updated: 2022/04/18 14:35:35 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	concat_words(t_data *data, t_token **tokens, char **new)
{
	(void)data;
	*new = ft_strdup((*tokens)->content, data);
	if (*tokens)
		*tokens = (*tokens)->next;
	while (*tokens && is_word((*tokens)->type))
	{
		*new = ft_strjoin(*new, (*tokens)->content, data);
		if (*tokens)
			*tokens = (*tokens)->next;
	}
}

t_cmd	*parse_cmd(t_data *data, t_token **tokens, int size, t_cmd *new)
{
	int	i;

	i = 0;
	new->cmd = ft_malloc(sizeof(char *) * (size + 1), data);
	while (*tokens && i < size)
	{
		if (*tokens && is_word((*tokens)->type))
			concat_words(data, tokens, &new->cmd[i]);
		while (*tokens && !is_word((*tokens)->type))
		{
			if ((*tokens)->type != WHITE_SPACE)
				redir(tokens);
			*tokens = (*tokens)->next;
		}
		i++;
	}
	return (fill_cmd_data(new, i));
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
		new = ft_malloc(sizeof(t_cmd), data);
		new = parse_cmd(data, tokens, size, new);
		if (!new)
			return (NULL);
		cmd_lst_addback(&head, new, prev);
		prev = new;
		while (*tokens && (*tokens)->type == WHITE_SPACE)
			*tokens = (*tokens)->next;
	}
	*tokens = head_tokens;
	return (head);
}

int	parsing(char *line, t_data *data)
{
	if (first_check(line))
		return (parsing_return(line, data));
	line = check_line(line, data);
	if (!line)
		return (1);
	if (lexer(line, &data->tokens, data))
		return (parsing_return(line, data));
	if (scan_tokens(data, data->tokens))
		return (parsing_return(line, data));
	data->cmd_lst = create_cmd_lst(data, &data->tokens);
	if (!data->cmd_lst)
		return (parsing_return(line, data));
	return (0);
}
