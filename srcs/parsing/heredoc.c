/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:14:39 by arudy             #+#    #+#             */
/*   Updated: 2022/04/29 19:20:16 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*heredoc_filename(t_data *data)
{
	char	*filename;

	filename = ft_strdup("/tmp/", data);
	filename = ft_strjoin(filename, "heredoooooooc", data);
	return (filename);
}

void	copy_in_heredoc(int fd, char *s, t_data *data)
{
	int		i;
	char	*dst;

	i = 0;
	dst = find_dollar_value(data, s, i);
	write(fd, dst, ft_strlen(dst));
}

char	*heredoc_loop(t_token *lst, t_data *data)
{
	char	*line;
	char	*content;

	content = NULL;
	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(line, lst->content))
			break ;
		if (!content)
			content = ft_strdup(line, data);
		else
			content = ft_strjoin(content, line, data);
		content = ft_strjoin_char(content, '\n', data);
		free(line);
	}
	return (content);
}

int	manage_heredoc(t_cmd *cmd, t_token *lst, t_data *data)
{
	int		fd;
	char	*content;
	char	*file_name;

	(void)cmd;
	file_name = heredoc_filename(data);
	fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0777);
	content = heredoc_loop(lst, data);
	if (fd < 0 || !content)
		return (ft_free(file_name, data), fd);
	copy_in_heredoc(fd, content, data);
	ft_free(file_name, data);
	return (fd);
}
