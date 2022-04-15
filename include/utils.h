/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:52:06 by arudy             #+#    #+#             */
/*   Updated: 2022/04/15 16:26:25 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	ft_free(void *ptr, t_data *data);
void	ft_free_garbage(t_garbage *garbage);
void	free_lst(t_data *data);
void	free_all(t_data *data);
void	*ft_malloc(size_t size, t_data *data);
void	*error(char *cmd, char *arg, char *msg);
char	**dup_env(t_env *env, t_data *data);
t_data	*init_data(char **envp);

#endif
