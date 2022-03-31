/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:19:08 by arudy             #+#    #+#             */
/*   Updated: 2022/03/31 14:19:23 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dst;

	dst = malloc(nmemb * size);
	if (!dst)
		return (NULL);
	ft_bzero(dst, nmemb * size);
	return (dst);
}
