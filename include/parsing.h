/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:22:46 by arudy             #+#    #+#             */
/*   Updated: 2022/04/20 15:00:01 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int		first_check(char *s);
int		scan_redir(t_token *lst);
int		check_tokens(t_data *data);
int		is_word(t_token_type type);
int		check_redir(char *s, int *i);
int		find_cmd_length(t_token *lst);
int		parsing(char *line, t_data *data);
int		is_redir_sign(t_token_type token);
int		scan_dollar(t_data *data, t_token *lst);
int		scan_tokens(t_data *data, t_token *lst);
int		scan_dollar(t_data *data, t_token *lst);
int		check_next_char_dollar(char *s, int *i);
int		create_bin_path(t_data *data, t_cmd *lst);
void	check_builtins(t_cmd *lst);
void	cmd_lst_addback(t_cmd **head, t_cmd *new, t_cmd *prev);
char	*get_env_var_return(int *i);
char	*ft_getenv(t_env *env, char *s);
char	*check_line(char *s, t_data *data);
char	*join_tmp(char *s1, char *s2, t_data *data);
t_cmd	*cmd_lst_last(t_cmd *lst);
t_cmd	*fill_cmd_data(t_cmd *cmd);
t_token	*del_whitespaces(t_token **lst, t_data *data);

#endif
