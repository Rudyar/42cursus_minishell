/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:14:39 by arudy             #+#    #+#             */
/*   Updated: 2022/05/05 19:43:13 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_exit_status;

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

char	*heredoc_loop(char *eof, t_data *data, int dup_stdin)
{
	char	*line;
	char	*content;

	content = NULL;
	while (1)
	{
		line = readline("> ");
		if (g_exit_status == 130)
		{
			close(dup_stdin);
			close_all(data);
			free_all(data);
			exit (g_exit_status);
		}
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
	pid_t	pid;
	int		dup_stdin;

	g_exit_status = 0;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	dup_stdin = dup(0);
	file_name = heredoc_filename(data);
	pid = fork();
	if (pid < 0)
		exec_error("fork failed: Resource temporarily unavailable", data);
	if (pid == 0)
	{
		signal(SIGINT, sig_heredoc);
		signal(SIGQUIT, sig_heredoc);
		dup2(dup_stdin, 0);
		content = heredoc_loop(lst->content, data, dup_stdin);
		fd = ft_open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644, data);
		if (fd < 0)
		{
			ft_putstr_fd("minishell: ", 2);
			perror(lst->content);
			return (ft_free(file_name, data), NULL);
		}
		copy_in_heredoc(fd, content, lst, data);
		close(0);
		close(dup_stdin);
		close_all(data);
		free_all(data);
		exit (g_exit_status);
	}
	waitpid(pid, &g_exit_status, 0);
	g_exit_status = g_exit_status % 255;
	close(dup_stdin);
	return (file_name);
}
