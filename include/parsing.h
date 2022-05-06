/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:22:46 by arudy             #+#    #+#             */
/*   Updated: 2022/05/06 10:17:10 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int		first_check(char *s);
int		scan_redir(t_token *lst);
int		is_heredoc(t_token *lst);
int		check_tokens(t_data *data);
int		is_word(t_token_type type);
int		check_redir(char *s, int *i);
int		find_cmd_length(t_token *lst);
int		parsing(char *line, t_data *data);
int		is_redir_sign(t_token_type token);
int		is_dollar_char_valid(char c, int n);
int		scan_dollar(t_data *data, t_token *lst);
int		scan_tokens(t_data *data, t_token *lst);
int		scan_dollar(t_data *data, t_token *lst);
int		check_next_char_dollar(char *s, int *i);
int		create_bin_path(t_data *data, t_cmd *lst);
int		manage_heredoc(t_token *lst, t_data *data);
int		exit_heredoc_fork(t_data *data, int dup_stdin);
char	*ft_getenv(t_env *env, char *s);
char	*heredoc_filename(t_data *data);
char	*check_line(char *s, t_data *data);
char	*join_tmp(char *s1, char *s2, t_data *data);
char	*get_env_var_return(char *dst, t_data *data);
char	*get_env_var_return_error(int *i, t_data *data);
char	*split_whitespaces(char	*content, t_data *data);
char	*find_dollar_value(t_data *data, char *s, int i);
int		no_line_return(int i, char *eof, char *content, t_data *data);
// char	*no_line_return(int i, char *eof, char *content, t_data *data);
int		heredoc_return(char *content, char *line, char *eof, t_data *data);
// char	*heredoc_return(char *content, char *line, char *eof, t_data *data);
void	print_cmd_lst(t_cmd *lst);
void	cmd_lst_addback(t_cmd **head, t_cmd *new, t_cmd *prev);
t_cmd	*cmd_lst_last(t_cmd *lst);
t_cmd	*fill_cmd_data(t_cmd *cmd);
t_token	*find_cmd_fd_error(t_token *lst);
t_token	*del_whitespaces(t_token **lst, t_data *data);

#endif
