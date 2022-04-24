/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:52:06 by arudy             #+#    #+#             */
/*   Updated: 2022/04/24 12:43:01 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	free_lst(t_data *data);
void	free_all(t_data *data);
void	ft_free(void *ptr, t_data *data);
void	free_env(t_env *lst, t_data *data);
void	ft_free_garbage(t_garbage *garbage);
void	*ft_malloc(size_t size, t_data *data);
void	*error(char *cmd, char *arg, char *msg);
void	free_cmd_lst(t_cmd **lst, t_data *data);
void	set_env(t_env *env, t_data *data, char *var, char *value);
char	**dup_env(t_env *env, t_data *data);
char	*get_prompt(t_data *data, char **envp);
t_data	*init_data(char **envp);

#endif
