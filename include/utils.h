/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:52:06 by arudy             #+#    #+#             */
/*   Updated: 2022/04/06 15:33:50 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

t_data	*init_data(char **envp);
void	ft_free(t_data *data);
void	free_lst(t_data *data);
void	*error(char *cmd, char *arg, char *msg);

#endif
