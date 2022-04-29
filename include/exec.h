/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:22:46 by arudy             #+#    #+#             */
/*   Updated: 2022/04/29 10:37:30 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

int		check_builtins(t_cmd *lst);
int		is_only_builtin(t_data *data);
int		loop(t_data *data, char **envp);
int		exec_builtins(t_cmd *lst, t_data *data);
int		executable_error(t_cmd *lst, t_data *data);
int		exit_fork(t_cmd *lst, t_data *data, int ret);
void	sig_handler(int sig);
void	sig_exec_handler(int sig);
void	link_pipe(t_cmd *lst, t_data *data);
void	start_exec(t_cmd *lst, t_data *data);
void	exec_error(char *msg, t_cmd *lst, t_data *data);

#endif
