/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:22:46 by arudy             #+#    #+#             */
/*   Updated: 2022/04/27 19:13:39 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

int		check_builtins(t_cmd *lst);
int		loop(t_data *data, char **envp);
int		exec_builtins(t_cmd *lst, t_data *data);
void	sig_handler(int sig);
void	sig_exec_handler(int sig);
void	link_pipe(t_cmd *lst, t_data *data);
void	start_exec(t_cmd *lst, t_data *data);
void	exec_error(char *msg, t_cmd *lst, t_data *data);

#endif
