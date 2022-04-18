/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:22:46 by arudy             #+#    #+#             */
/*   Updated: 2022/04/18 16:23:22 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int		first_check(char *s);
int		scan_redir(t_token *lst);
int		check_tokens(t_data *data);
int		check_redir(char *s, int *i);
int		find_cmd_length(t_token *lst);
int		parsing(char *line, t_data *data);
int		scan_dollar(t_data *data, t_token *lst);
int		check_next_char_dollar(char *s, int *i);
void	check_builtins(t_cmd *lst);
void	fill_cmd_data(t_cmd *cmd, int i);
void	create_bin_path(t_data *data, t_cmd *lst);
void	cmd_lst_addback(t_cmd **head, t_cmd *new, t_cmd *prev);
char	*get_env_var_return(int *i);
char	*ft_getenv(t_env *env, char *s);
char	*check_line(char *s, t_data *data);
char	*join_tmp(char *s1, char *s2, t_data *data);
t_cmd	*cmd_lst_last(t_cmd *lst);
t_token	*scan_tokens(t_data *data, t_token *lst);

#endif
