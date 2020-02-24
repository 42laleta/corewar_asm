/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:58:56 by laleta            #+#    #+#             */
/*   Updated: 2020/02/20 21:53:19 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

static void	get_header_name(t_asm *assm, t_inline *iline)
{
	uint64_t	len;
	char		*start_ptr;
	char		*end_ptr;
	char		*tmp;

	if (!(start_ptr = ft_strchr(iline->str, '"')))
		error_handle_adv(assm, iline, ERR_NAME_MISSING, NULL);
	if (!(end_ptr = ft_strchr(start_ptr + 1, '"')))
		error_handle_adv(assm, iline, ERR_NAME_UNFINISH, NULL);
	tmp = ft_strsub(iline->str, start_ptr + 1 - iline->str,
													end_ptr - start_ptr - 1);
	len = ft_strlen(tmp);
	if (len > PROG_NAME_LENGTH)
		error_handle_adv(assm, iline, ERR_NAME_LENGTH, NULL);
	ft_strcpy(assm->header->prog_name, tmp);
	iline->col = (end_ptr - iline->str + 1);
	ft_strdel(&tmp);
}

static void	get_header_comment(t_asm *assm, t_inline *iline)
{
	uint64_t	len;
	char		*start_ptr;
	char		*end_ptr;
	char		*tmp;

	if (!(start_ptr = ft_strchr(iline->str, '"')))
		error_handle_adv(assm, iline, ERR_COMMENT_MISSING, NULL);
	if (!(end_ptr = ft_strchr(start_ptr + 1, '"')))
		error_handle_adv(assm, iline, ERR_COMMENT_UNFINISH, NULL);
	tmp = ft_strsub(iline->str, start_ptr + 1 - iline->str,
													end_ptr - start_ptr - 1);
	len = ft_strlen(tmp);
	if (len > COMMENT_LENGTH)
		error_handle_adv(assm, iline, ERR_COMMENT_LENGTH, NULL);
	ft_strcpy(assm->header->comment, tmp);
	iline->col = (end_ptr - iline->str + 1);
	ft_strdel(&tmp);
}

void		header_processing(t_asm *assm, t_token **token, t_inline *iline,
															char **label_str)
{
	static int8_t	header_flag = 0;

	if (iline->row == 1)
		header_flag = 0;
	if (header_flag == 3)
	{
		operation_processing(assm, token, iline, label_str);
		return ;
	}
	if ((*token)->type == ASM_HEADER && (*token)->subtype == NAME_HEAD)
	{
		if (header_flag & NAME_HEAD)
			error_handle_adv(assm, iline, ERR_NAME_REDEFINE, (*token)->raw);
		get_header_name(assm, iline);
		header_flag |= NAME_HEAD;
	}
	else if ((*token)->type == ASM_HEADER && (*token)->subtype == COMMENT_HEAD)
	{
		if (header_flag & COMMENT_HEAD)
			error_handle_adv(assm, iline, ERR_COMMENT_REDEFINE, (*token)->raw);
		get_header_comment(assm, iline);
		header_flag |= COMMENT_HEAD;
	}
	else if ((*token)->type != ASM_EMPTY)
		error_handle_adv(assm, iline, ERR_TOKEN_INVALID, (*token)->raw);
}
