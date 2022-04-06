/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:36:21 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/05 17:35:46 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	pwd_cmd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putstr_fd(path, 1);
	ft_putstr_fd("\n", 1);
	free(path);
	return (0);
}
