/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:14:39 by arudy             #+#    #+#             */
/*   Updated: 2022/05/04 13:13:58 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	copy_in_heredoc(int fd, char *s, t_token *lst, t_data *data)
{
	int		i;
	char	*dst;

	i = 0;
	if (!s)
		return ;
	if (lst->type == HERE_DOC_EXPEND)
		dst = find_dollar_value(data, s, i);
	else
	{
		dst = ft_strdup(s, data);
		ft_free(s, data);
	}
	write(fd, dst, ft_strlen(dst));
	ft_free(dst, data);
}

int	check_eof(char *line, char *eof, t_data *data)
{
	char	*dst;

	dst = ft_strdup(line, data);
	if (!ft_strcmp(dst, eof))
	{
		ft_free(dst, data);
		return (1);
	}
	ft_free(dst, data);
	return (0);
}

char	*heredoc_loop(char *eof, t_data *data)
{
	char	*line;
	char	*content;

	content = NULL;
	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(line, eof) || check_eof(line, eof, data))
			break ;
		if (!content)
			content = ft_strdup(line, data);
		else
			content = ft_strjoin(content, line, data);
		content = ft_strjoin_char(content, '\n', data);
		free(line);
	}
	return (heredoc_return(content, line, eof, data));
}

char	*manage_heredoc(t_token *lst, t_data *data)
{
	int		fd;
	char	*content;
	char	*file_name;

	file_name = heredoc_filename(data);
	content = heredoc_loop(lst->content, data);
	fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(lst->content);
		return (ft_free(file_name, data), NULL);
	}
	copy_in_heredoc(fd, content, lst, data);
	close(fd);
	return (file_name);
}
