# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laleta <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 19:28:58 by laleta            #+#    #+#              #
#    Updated: 2020/02/14 20:50:51 by laleta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
FLAGS = -g -Wall -Wextra -Werror
SOURCE = cw_asm_main.c cw_asm_file_handle.c cw_asm_init_free.c cw_asm_header.c\
		cw_asm_token.c cw_asm_token_type.c cw_asm_token_type2.c\
		cw_asm_label_list.c cw_asm_operation.c cw_asm_oper_queue.c\
		cw_asm_bytecode.c cw_asm_error.c cw_asm_util.c
HEADER = cw_asm_op.h cw_asm.h cw_asm_error.h cw_asm_hash.h cw_asm_operation.h

INCLUDES = -Iincludes -I$(LIBFT_DIR)includes

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = libft/

LIB = -lft

LIB_DIR = -L$(LIBFT_DIR)

VPATH = srcs includes

OBJECT = $(SOURCE:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJECT)
	@echo "\033[1;3;34m"
	gcc $(FLAGS) $(OBJECT) -o $@ $(INCLUDES) $(LIB_DIR) $(LIB)
	@echo "\033[23;32m--[ "$(NAME) ]-- successfully compiled"\033[0m"

$(LIBFT) :
	@echo "\033[33;3m"
	@make -C $(LIBFT_DIR)
	@echo "\033[0m"

%.o : %.c $(HEADER)
	@echo "\033[36;3m"
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "\033[0m"

clean :
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJECT)

fclean : clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re : fclean all
