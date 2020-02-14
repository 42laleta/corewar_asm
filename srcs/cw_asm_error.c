/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 20:25:40 by laleta            #+#    #+#             */
/*   Updated: 2020/02/14 23:24:13 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

void	error_handle(const char *name, const char *err_str, t_asm *assm)
{
	ft_printf(B_RED);
	ft_printf(F_WHITE);
	ft_printf(BOLD " %ss " NONE F_RED "\tERROR: %s\n" NONE, name, err_str);
	if (errno)
		ft_printf(F_RED "%s\n" NONE, strerror(errno));
	if (assm)
		asm_free(assm);
	exit(1);
}

void	error_handle2(const char *name, const char *err_str, t_asm *assm)
{
	ft_printf(B_RED);
	ft_printf(F_WHITE);
	ft_printf(BOLD " %s " NONE F_RED "\tERROR: %s\n" NONE, name, err_str);
	if (errno)
		ft_printf(F_RED "%s\n" NONE, strerror(errno));
	if (assm)
		asm_free(assm);
	exit(1);
}

void	error_handle_adv(t_asm *assm, t_inline *iline, const char *err_str,
														const char *token_str)
{
	if (!token_str)
	{
		ft_printf(B_RED);
		ft_printf(F_WHITE);
		ft_printf(BOLD " %ss " NONE, assm->file_name);
		ft_printf(F_BLUE);
		ft_printf(BOLD "\t=>[%u:%u]<=" NONE F_RED " ERROR: %s\n", iline->row,
													iline->col + 1, err_str);
	}
	else
	{
		ft_printf(B_RED);
		ft_printf(F_WHITE);
		ft_printf(BOLD " %ss " NONE, assm->file_name);
		ft_printf(F_BLUE);
		ft_printf(BOLD "\t=>[%u:%u]<=" NONE F_RED " ERROR: %s ", iline->row,
								iline->col - ft_strlen(token_str) + 1, err_str);
		ft_printf(F_BLUE);
		ft_printf(BOLD "=>[%s]<=\n" NONE, token_str);
	}
	if (assm)
		asm_free(assm);
	exit(1);
}
