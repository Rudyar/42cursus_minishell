/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:28:26 by arudy             #+#    #+#             */
/*   Updated: 2022/04/15 16:31:03 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

int		lexer(char *s, t_token **tokens_lst, t_data *data);
t_token	*char_to_token(char *s, t_data *data);
t_token	*token_lst_last(t_token *lst);
t_token	*copy_tokens(t_token **lst, t_token_type type, int n, t_data *data);
void	manage_quotes(t_token **lst, t_token **prev, t_token **head, t_data *data);
void	manage_letters(t_token **lst, t_token **prev, t_token **head, t_data *data);
void	manage_redir(t_token **lst, t_token **prev, t_token **head, t_data *data);
void	manage_else(t_token **lst, t_token **prev, t_token **head, t_data *data);
int		count_letters(t_token *lst);
void	free_token_lst(t_token **lst, t_data *data);
void	token_lst_addback(t_token **head, t_token *new);
void	print_token_lst(t_token *lst);

#endif
