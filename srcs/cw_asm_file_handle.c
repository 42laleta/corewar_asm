/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_file_handle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 00:17:29 by laleta            #+#    #+#             */
/*   Updated: 2020/02/04 05:36:19 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

static char	*min_ptr(char *p1, char *p2)
{
	if (p1 <= p2)
		return (p1);
	else
		return (p2);
}

static char	*max_ptr(char *p1, char *p2)
{
	if (p1 >= p2)
		return (p1);
	else
		return (p2);
}

static char	*del_comment(char **str)
{
	char	*com_ptr;
	char	*com_ptr_alt;
	char	*res;

	com_ptr = ft_strchr(*str, COMMENT_CHAR);
	com_ptr_alt = ft_strchr(*str, COMMENT_CHAR_ALT);
	if (com_ptr && com_ptr_alt)
		com_ptr = min_ptr(com_ptr, com_ptr_alt);
	else
		com_ptr = max_ptr(com_ptr, com_ptr_alt);
	if (com_ptr)
		res = ft_strsub(*str, 0, com_ptr - *str);
	else
		res = ft_strdup(*str);
	ft_strdel(str);
	return (res);
}

static char	*file_parse(t_asm *assm, t_inline *iline, t_token *token,
															int8_t header_flag)
{
	char	*str_in;
	char	*label_str;

	str_in = NULL;
	label_str = NULL;
	while (get_next_line(assm->fd_in, &str_in) > 0)
	{
		iline->str = del_comment(&str_in);
		iline->len = ft_strlen(iline->str);
		token = get_token(assm, iline);
		if (header_flag != 3)
			header_processing(assm, token, iline, &header_flag);
		else
			operation_processing(assm, &token, iline, &label_str);
		token_free(&token);
		token = get_token(assm, iline);
		if (token->type != ASM_EMPTY)
			error_handle_adv(assm, iline, ERR_EXTRA_TOKEN, token->raw);
		token_free(&token);
		ft_strdel(&iline->str);
		iline->row++;
		iline->col = 0;
	}
	return (label_str);
}

void		file_handle(t_asm *assm)
{
	char		*label_str;
	t_inline	iline;
	t_token		*token;

	token = NULL;
	iline.col = 0;
	iline.row = 1;
	label_str = NULL;
	label_str = file_parse(assm, &iline, token, 0);
	if (label_str)
		labelist_push_back(assm, &assm->labels, &label_str,
												assm->oper_queue->byte_total);
	if (assm->oper_queue->byte_total == 0)
		error_handle(assm->file_name, ERR_NO_OPERATION, assm, NULL);
	assm->header->prog_size = assm->oper_queue->byte_total;
}
