/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:17:25 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/18 17:33:12 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

long long	ft_atoll(char *n)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((n[i] >= 7 && n[i] <= 13) || n[i] == 32)
		i++;
	if (n[i] == '-' || n[i] == '+')
	{
		if (n[i] == '-')
			sign = -1;
		i++;
	}
	while (n[i] >= '0' && n[i] <= '9')
	{
		result = result * 10 + (n[i] - 48);
		i++;
	}
	if (sign == -1)
		return ((sign * result) % 256 + 256);
	else
		return ((sign * result) % 256);
}
