/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:22:46 by arudy             #+#    #+#             */
/*   Updated: 2022/04/06 15:31:51 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "lexer.h"
# include "parsing.h"

size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	free_strs(char **strs);
char	**ft_split(char const *s, char c);
char	**ft_nsplit(char *s, char c, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_char(char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_is_whitespace(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
t_env	*ft_env_lstnew(char *content, t_env *prev);
void	ft_env_addback(t_env *env, t_env *new);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strcdup(char *s, char c);

#endif
