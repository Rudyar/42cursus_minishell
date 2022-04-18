/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:22:46 by arudy             #+#    #+#             */
/*   Updated: 2022/04/18 15:02:53 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int		parsing(char *line, t_data *data);
int		first_check(char *s);
int		check_redir(char *s, int *i);
int		check_tokens(t_data *data);
int		find_cmd_length(t_token *lst);
int		is_word(t_token_type type);
int		scan_dollar(t_data *data, t_token *lst);
int		scan_tokens(t_data *data, t_token *lst);
t_token	*del_whitespaces(t_token **lst, t_data *data);
int		parsing_return(char *line, t_data *data);
void	check_builtins(t_cmd *lst);
void	create_bin_path(t_data *data, t_cmd *lst);
void	cmd_lst_addback(t_cmd **head, t_cmd *new, t_cmd *prev);
t_cmd	*fill_cmd_data(t_cmd *cmd, int i);
void	redir(t_token **tokens);
char	*check_line(char *s, t_data *data);
int		scan_dollar(t_data *data, t_token *lst);
char	*ft_getenv(t_env *env, char *s);
char	*join_tmp(char *s1, char *s2, t_data *data);
int		check_next_char_dollar(char *s, int *i);
char	*get_env_var_return(int *i);
t_cmd	*cmd_lst_last(t_cmd *lst);

#endif
