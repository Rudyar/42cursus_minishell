/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:22:46 by arudy             #+#    #+#             */
/*   Updated: 2022/04/06 19:05:57 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

int		echo_cmd(char **args);
int		cd_cmd(char **args);
int		env_cmd(t_env *env);
int		export_cmd(char **args, t_env *env);
int		check_value(char *arg);
int		check_add_value(char *arg);
int		check_exist(char *arg, t_env *env);
int		check_export_arg(char *arg);
void	update_env_var(char *arg, t_env *env);
void	update_add_env_var(char *arg, t_env *env);
char	*name_without_plus(char *s);
int		pwd_cmd(void);
int		unset_cmd(char **args, t_env **env);

#endif
