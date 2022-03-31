/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:22:46 by arudy             #+#    #+#             */
/*   Updated: 2022/03/31 14:20:46 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "lexer.h"
# include "parsing.h"

void	ft_putstr_fd(char *s, int fd);
void	free_strs(char **strs);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_is_whitespace(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
t_env	*ft_env_lstnew(char *content, t_env *prev);
void	ft_env_addback(t_env *env, t_env *new);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
