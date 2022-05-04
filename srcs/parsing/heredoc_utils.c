/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:36:05 by arudy             #+#    #+#             */
/*   Updated: 2022/05/04 15:10:01 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*heredoc_filename(t_data *data)
{
	char		*filename;
	struct stat	st;

	filename = ft_strdup("/tmp/", data);
	filename = ft_strjoin_char(filename, '.', data);
	filename = ft_strjoin_char(filename, 8, data);
	if (lstat(filename, &st) == -1)
		return (filename);
	else
	{
		unlink(filename);
		perror(filename);
	}
	return (filename);
}

char	*no_line_return(int i, char *eof, char *content, t_data *data)
{
	char	p1;
	char	p2;

	p1 = '(';
	p2 = ')';
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("warning: here-document at line ", 2);
	ft_putstr_fd(ft_itoa(i, data), 2);
	ft_putstr_fd(" delimited by end-of-file ", 2);
	write(2, &p1, 1);
	ft_putstr_fd("wanted `", 2);
	ft_putstr_fd(eof, 2);
	ft_putstr_fd("'", 2);
	write(2, &p2, 1);
	ft_putstr_fd("\n", 2);
	return (content);
}

char	*heredoc_return(char *content, char *line, char *eof, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (content && content[i])
	{
		if (content[i] == '\n')
			j++;
		i++;
	}
	if (!line)
		return (no_line_return(j, eof, content, data));
	free(line);
	return (content);
}
