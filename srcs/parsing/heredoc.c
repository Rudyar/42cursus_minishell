/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:14:39 by arudy             #+#    #+#             */
/*   Updated: 2022/05/02 19:01:50 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	copy_in_heredoc(int fd, char *s, t_data *data)
{
	int		i;
	char	*dst;

	i = 0;
	if (!s)
		return ;
	dst = find_dollar_value(data, s, i);
	write(fd, dst, ft_strlen(dst));
}

int	check_eof(char *line, char *eof, t_data *data)
{
	int		i;
	char	*dst;

	i = 0;
	dst = ft_strdup(line, data);
	dst = find_dollar_value(data, dst, i);
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
		if (!line || !strcmp(line, eof) || check_eof(line, eof, data))
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
	copy_in_heredoc(fd, content, data);
	close(fd);
	return (file_name);
}
