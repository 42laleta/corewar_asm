/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:47:56 by laleta            #+#    #+#             */
/*   Updated: 2020/02/03 20:10:49 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

static int8_t	go_forward_str(t_inline *iline)
{
	if (!iline->len || iline->col > iline->len - 1)
		return (1);
	else
		iline->col++;
	return (0);
}

static void		skip_insignificant_char(t_inline *iline)
{
	int8_t stop;

	stop = 0;
	while (!stop && iline->str[iline->col] &&
				(is_whitespace(iline->str[iline->col]) ||
								iline->str[iline->col] == SEPARATOR_CHAR ||
								iline->str[iline->col] == '\n'))
		stop = go_forward_str(iline);
}

static char		*get_token_raw(t_inline *iline)
{
	uint64_t	start;
	int8_t		stop;

	stop = 0;
	skip_insignificant_char(iline);
	if (!iline->str[iline->col] || !ft_isprint(iline->str[iline->col]))
		return (NULL);
	else
	{
		start = iline->col;
		while (!stop && iline->str[iline->col] &&
				iline->str[iline->col] != SEPARATOR_CHAR &&
				iline->str[iline->col] != '\n' &&
				(!is_whitespace(iline->str[iline->col])))
			stop = go_forward_str(iline);
		return (ft_strsub(iline->str, start, iline->col - start));
	}
}

static void		get_token_type(t_asm *assm, t_token *token, t_inline *iline)
{
	token->subtype = 0;
	if (!token->raw)
	{
		token->type = ASM_EMPTY;
		token->subtype = ASM_EMPTY;
		return ;
	}
	if (is_header(token))
		token->type = ASM_HEADER;
	else if (is_label(token))
	{
		token->raw[ft_strlen(token->raw) - 1] = '\0';
		token->type = ASM_LABEL;
	}
	else if (is_operation(token))
		token->type = ASM_OPERATION;
	else if (is_argument(assm, token, iline))
		token->type = ASM_ARGUMENT;
	else
		token->type = ASM_UNDEF;
}

t_token			*get_token(t_asm *assm, t_inline *iline)
{
	t_token *token;

	if (!(token = (t_token *)malloc(sizeof(t_token))))
		error_handle(assm->file_name, ERR_MALLOC, assm, NULL);
	token->raw = NULL;
	token->raw = get_token_raw(iline);
	get_token_type(assm, token, iline);
	return (token);
}
