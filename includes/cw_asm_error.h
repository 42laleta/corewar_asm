/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:47:53 by laleta            #+#    #+#             */
/*   Updated: 2020/02/03 19:49:45 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_ASM_ERROR_H
# define CW_ASM_ERROR_H

# define ERR_MALLOC				"memory allocation failure"
# define ERR_FILE_NAME			"file name is too long"
# define ERR_FILE_TYPE			"wrong file type, [file.s] expected"
# define ERR_REG_NBR			"register number out of range"
# define ERR_NAME_REDEFINE		"champions name is redefined"
# define ERR_COMMENT_REDEFINE	"champions comment is redefined"
# define ERR_NAME_MISSING		"champions name is missing"
# define ERR_COMMENT_MISSING	"champions comment is missing"
# define ERR_NAME_UNFINISH		"champions name is unfinished"
# define ERR_COMMENT_UNFINISH	"champions comment is unfinished"
# define ERR_NAME_LENGTH		"champions name is too long"
# define ERR_COMMENT_LENGTH		"champions comment is too long"
# define ERR_TOKEN_INVALID		"invalid or unexpected token"
# define ERR_OPERATION_MISSING	"operation is missing"
# define ERR_ARGTYPE_INVALID	"invalid argument type"
# define ERR_ARGUMENT_INVALID	"invalid argument"
# define ERR_ARGUMENT_MISSING	"argument is missing"
# define ERR_EXTRA_TOKEN		"too many arguments"
# define ERR_NO_OPERATION		"operations not found"

#endif
