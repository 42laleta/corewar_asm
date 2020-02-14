/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_asm_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 04:43:03 by laleta            #+#    #+#             */
/*   Updated: 2020/02/14 23:25:16 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_asm.h"

static int32_t	valid_file(const char *file_name)
{
	int32_t	fd;
	char	*file_type;
	int32_t	len;

	if ((len = ft_strlen(file_name)) > MAX_FILE_PATH - 3)
		error_handle2(file_name, ERR_FILE_NAME, NULL);
	if ((file_type = ft_strrchr(file_name, '.')) && ft_strequ(file_type, ".s"))
		return (fd = open(file_name, O_RDONLY));
	else
		error_handle2(file_name, ERR_FILE_TYPE, NULL);
	return (-1);
}

void			assembler(int32_t fd, char *file_name)
{
	t_asm	*assm;

	assm = NULL;
	asm_init(&assm, file_name, fd);
	file_handle(assm);
	close(fd);
	ft_printf(B_GREEN);
	ft_printf(F_WHITE);
	ft_printf(BOLD " %ss " NONE, assm->file_name);
	ft_printf(F_GREEN "\tWraiting output program to %scor\n\n" NONE,
														assm->path_file_name);
	translate_to_bytecode(assm);
	asm_free(assm);
}

static int32_t	usage(void)
{
	ft_printf("usage: ./asm file.s\n");
	return (1);
}

int32_t			main(int32_t argc, char **argv)
{
	int32_t	i;
	int32_t	fd;

	i = 0;
	if (argc < 2)
		return (usage());
	while (++i < argc)
	{
		if ((fd = valid_file(argv[i])) != -1)
			assembler(fd, argv[i]);
		else
		{
			if (errno)
			{
				ft_printf(B_RED);
				ft_printf(F_WHITE);
				ft_printf(BOLD " %s " NONE, argv[i]);
				ft_printf(F_RED "\tERROR: %s\n" NONE, strerror(errno));
			}
			continue ;
		}
	}
	return (0);
}
