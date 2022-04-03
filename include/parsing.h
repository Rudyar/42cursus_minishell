/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:22:46 by arudy             #+#    #+#             */
/*   Updated: 2022/04/03 12:10:03 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int		parsing(char *line, t_data *data);
int		first_check(char *s);
int		check_line(char *s);
int		count_nb_cmd(t_token **lst);
int		find_cmd_length(t_token *lst);
void	cmd_lst_addback(t_cmd **head, t_cmd *new, t_cmd *prev);
char	*scan_dollar(t_data *data, char *s);
t_cmd	*cmd_lst_last(t_cmd *lst);
char	*ft_getenv(t_env *env, char *s);

#endif
