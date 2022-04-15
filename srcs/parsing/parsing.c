/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:02:20 by arudy             #+#    #+#             */
/*   Updated: 2022/04/15 11:26:31 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// t_cmd	*parse_cmd(t_data *data, t_token **tokens, int size, t_cmd *new)
// {
// 	int	i;

// 	i = 0;
// 	new->cmd = ft_malloc(sizeof(char *) * (size + 1));
// 	while (*tokens && i < size)
// 	{
// 		if ((*tokens)->type == WORD)
// 			new->cmd[i] = ft_strdup((*tokens)->content);
// 		if ((*tokens)->type == IN_DQUOTE || (*tokens)->type == DOLLAR)
// 			new->cmd[i] = scan_dollar(data, (*tokens)->content);
// 		if ((*tokens)->type == PIPE || (*tokens)->type == HERE_DOC
// 			|| (*tokens)->type == DGREATER || (*tokens)->type == REDIR_IN
// 			|| (*tokens)->type == REDIR_OUT || (*tokens)->type == WHITE_SPACE)
// 			new->cmd[i] = ft_strdup((*tokens)->content);
// 		*tokens = (*tokens)->next;
// 		i++;
// 	}
// 	fill_cmd_data(new, i);
// 	return (new);
// }

// t_cmd	*create_cmd_lst(t_data *data, t_token **tokens)
// {
// 	int		size;
// 	t_token	*head_tokens;
// 	t_cmd	*head;
// 	t_cmd	*new;
// 	t_cmd	*prev;

// 	head = NULL;
// 	prev = NULL;
// 	head_tokens = *tokens;
// 	while (*tokens)
// 	{
// 		size = find_cmd_length(*tokens);
// 		new = ft_malloc(sizeof(t_cmd));
// 		new = parse_cmd(data, tokens, size, new);
// 		if (!new)
// 			return (NULL);
// 		if (*tokens)
// 			*tokens = (*tokens)->next;
// 		cmd_lst_addback(&head, new, prev);
// 		prev = new;
// 	}
// 	*tokens = head_tokens;
// 	return (head);
// }

int	parsing_return(char *line, t_data *data)
{
	ft_free(line, data);
	return (1);
}

int	parsing(char *line, t_data *data)
{
	t_token	*tokens_lst;

	tokens_lst = NULL;
	if (first_check(line))
		return (parsing_return(line, data));
	line = check_line(line, data);
	if (!line)
		return (1);
	if (lexer(line, &tokens_lst, data))
		return (parsing_return(line, data));
	data->tokens = scan_tokens(data, tokens_lst);
	if (!data->tokens)
	{
		free_token_lst(&tokens_lst, data);
		return (parsing_return(line, data));
	}
	free_token_lst(&tokens_lst, data);
	ft_free(line, data);
	return (0);
}

	// (void)data;
	// data->cmd_lst = create_cmd_lst(data, &data->tokens);
	// if (!data->cmd_lst)
	// {
	// 	ft_putstr_fd("Can't create cmd lst\n", 2);
	// 	return (1);
	// }
	// check_builtins(data->cmd_lst);
	// create_bin_path(data, data->cmd_lst);
