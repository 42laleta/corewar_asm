# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laleta <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 19:28:58 by laleta            #+#    #+#              #
#    Updated: 2020/02/24 18:18:32 by laleta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = asm
NAME2 = corewar

EXE1_DIR = asm
EXE2_DIR = vm

.PHONY : all clean fclean re

all : $(NAME1) $(NAME2)
	@printf "$$(cat cw_make)"

$(NAME1) :
	make -C $(EXE1_DIR)
$(NAME2) :
	make -C $(EXE2_DIR)

clean :
	@make -C $(EXE1_DIR) clean
	@make -C $(EXE2_DIR) clean

fclean : clean
	@make -C $(EXE1_DIR) fclean
	@make -C $(EXE2_DIR) fclean

re : fclean all


