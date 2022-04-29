/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:14:39 by arudy             #+#    #+#             */
/*   Updated: 2022/04/29 17:08:14 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*heredoc_filename(t_data *data)
{
	char	*file_name;

	file_name = ft_malloc(sizeof(char) * 8, data);
	file_name[0] = '.';
	file_name[1] = 1;
	file_name[2] = 2;
	file_name[3] = 3;
	file_name[4] = 4;
	file_name[5] = 5;
	file_name[6] = 6;
	file_name[7] = 0;
	return (file_name);
}

void	copy_in_heredoc(int fd, char *s, t_data *data)
{
	int		i;
	char	*dst;

	i = 0;
	dst = find_dollar_value(data, s, i);
	write(fd, dst, ft_strlen(dst));
}

int	manage_heredoc(t_cmd *cmd, t_token *lst, t_data *data)
{
	int		fd;
	char	*file_name;
	char	*line;
	char	*content;

	file_name = heredoc_filename(data);
	content = NULL;
	fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd < 0)
		return (ft_free(file_name, data), fd);
	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(line, lst->content))
			break;
		if (!content)
			content = ft_strdup(line, data);
		else
			content = ft_strjoin(content, line, data);
		content = ft_strjoin_char(content, '\n', data);
		free(line);
	}
	(void)cmd;
	if (content)
		copy_in_heredoc(fd, content, data);
	close(fd);
	unlink(file_name);
	ft_free(file_name, data);
	return (fd);
}
