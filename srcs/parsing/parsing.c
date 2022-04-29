/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:02:20 by arudy             #+#    #+#             */
/*   Updated: 2022/04/29 19:16:59 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// void	*lire(int fd)
// {
// 	fd = open("/tmp/heredoooooooc", O_RDONLY);
// 	perror("heredoc");
// 	printf("fd : %d\n", fd);
// 	char	a[999999];
// 	char	buffer;
// 	char	*new_a;
// 	int		i;
// 	int		len;

// 	i = 0;
// 	len = 0;
// 	a[i] = 0;
// 	while (read(fd, &buffer, 1) > 0)
// 	{
// 		a[i] = buffer;
// 		a[i + 1] = '\0';
// 		if (a[i] == '\n')
// 			break;
// 		i++;
// 	}
// 	if (!a[0])
// 		return (NULL);
// 	while (a[len] != '\0')
// 		len++;
// 	new_a = malloc(len + 1);
// 	if (!new_a)
// 		return (NULL);
// 	i = 0;
// 	while (a[i])
// 	{
// 		new_a[i] = a[i];
// 		i++;
// 	}
// 	new_a[i] = '\0';
// 	printf("new a %s\n", new_a);
// 	free(new_a);
// 	return (NULL);
// }

static t_token	*find_cmd_fd(t_cmd *new, t_token *lst, t_data *data)
{
	if (lst->type == REDIR_IN || lst->type == HERE_DOC)
	{
		if (new->in > 2)
			close(new->in);
		if (lst->type == REDIR_IN)
			new->in = open(lst->content, O_RDONLY);
		else if (lst->type == HERE_DOC)
		{
			new->in = manage_heredoc(new, lst, data);
			// lire(new->in);
		}
		if (new->in < 0)
			return (ft_putstr_fd("minishell: ", 2), \
				perror(lst->content), lst->next);
	}
	if (lst->type == REDIR_OUT || lst->type == DGREATER)
	{
		if (new->out > 2)
			close(new->out);
		if (lst->type == REDIR_OUT)
			new->out = open(lst->content, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (lst->type == DGREATER)
			new->out = open(lst->content, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (new->out < 0)
			return (ft_putstr_fd("minishell: ", 2), \
				perror(lst->content), lst->next);
	}
	return (lst->next);
}

static t_token	*find_cmd_data(t_token *lst, t_cmd *new, t_data *data)
{
	int	i;

	i = 0;
	new->cmd = ft_malloc(sizeof(char *) * (find_cmd_length(lst) + 1), data);
	while (lst && lst->type != PIPE)
	{
		if (lst->type == CMD)
		{
			new->cmd_no_args = ft_strdup(lst->content, data);
			new->cmd[i++] = ft_strdup(lst->content, data);
			lst = lst->next;
		}
		while (lst && lst->type == ARG)
		{
			new->cmd[i++] = ft_strdup(lst->content, data);
			lst = lst->next;
		}
		if (lst && is_redir_sign(lst->type))
		{
			lst = lst->next;
			lst = find_cmd_fd(new, lst, data);
		}
	}
	new->cmd[i] = NULL;
	return (lst);
}

static t_cmd	*create_cmd_lst(t_token *lst, t_data *data)
{
	t_cmd	*head;
	t_cmd	*new;
	t_cmd	*prev;

	head = NULL;
	new = NULL;
	prev = NULL;
	while (lst)
	{
		new = ft_malloc(sizeof(t_cmd), data);
		fill_cmd_data(new);
		lst = find_cmd_data(lst, new, data);
		cmd_lst_addback(&head, new, prev);
		prev = new;
		if (lst)
			lst = lst->next;
	}
	return (head);
}

int	parsing(char *line, t_data *data)
{
	t_token	*tokens_lst;

	tokens_lst = NULL;
	if (first_check(line))
		return (free(line), 1);
	line = check_line(line, data);
	if (!line)
		return (1);
	lexer(line, &tokens_lst, data);
	if (scan_tokens(data, tokens_lst))
		return (ft_free(line, data), 1);
	free_token_lst(&tokens_lst, data);
	data->cmd_lst = create_cmd_lst(data->tokens, data);
	return (0);
}
