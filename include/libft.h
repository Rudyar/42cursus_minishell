/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:22:46 by arudy             #+#    #+#             */
/*   Updated: 2022/03/25 18:10:47 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "lexer.h"

void	ft_putstr_fd(char *s, int fd);
void	free_strs(char **strs);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	**ft_strsjoin(char **tab, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_is_whitespace(int c);

#endif
