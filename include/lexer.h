/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:28:26 by arudy             #+#    #+#             */
/*   Updated: 2022/03/23 11:29:41 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum e_token_type
{
	WORD,
	DQUOTE = '"',
	QUOTE = '\'',
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	DGREATER,
	HERE_DOC,
	DOLLAR,
	ESPACE
}	t_token_type;

typedef struct s_token
{
	char			*content;
	t_token_type	type;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

void	lexer(t_token **token, char *line);
int		check_quotes(char *str);

#endif
