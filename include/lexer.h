/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:28:26 by arudy             #+#    #+#             */
/*   Updated: 2022/03/26 19:05:52 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum e_token_type
{
	WORD = 1,
	LETTER = 2,
	DQUOTE = '"',
	QUOTE = '\'',
	PIPE = '|',
	REDIR_IN = '<',
	REDIR_OUT = '>',
	DGREATER = 8,
	HERE_DOC = 9,
	DOLLAR = '$',
	WHITE_SPACE = 10,
	WORD_IN_DQUOTE = 11
}	t_token_type;

typedef struct s_token
{
	char			*content;
	t_token_type	type;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

t_token	*lexer(char *line);
t_token	*char_to_token(char *s);
t_token	*token_lst_last(t_token *lst);
t_token	*copy_tokens(t_token **lst, t_token_type type, t_token *prev, int n);
void	manage_redir(t_token **lst, t_token **prev, t_token **head);
void	manage_quotes(t_token **lst, t_token **prev, t_token **head);
int		first_check(char *s);
int		count_letters(t_token *lst);
void	free_token_lst(t_token **lst);
void	token_lst_addback(t_token **head, t_token *new);
void	print_token_lst(t_token **lst);

#endif
