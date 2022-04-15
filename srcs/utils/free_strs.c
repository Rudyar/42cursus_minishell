/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:24:06 by arudy             #+#    #+#             */
/*   Updated: 2022/04/15 11:26:57 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_strs(char **strs, t_data *data)
{
	int	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
	{
		ft_free(strs[i], data);
		i++;
	}
	ft_free(strs, data);
}
