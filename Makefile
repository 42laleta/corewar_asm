EXE1_DIR = assembler
EXE2_DIR = virtual_machine

.PHONY : all clean fclean re

all :
	make -C $(EXE1_DIR)
	make -C $(EXE2_DIR)
	@printf "$$(cat cw_make)"

clean :
	@make -C $(EXE1_DIR) clean
	@make -C $(EXE2_DIR) clean

fclean : clean
	@make -C $(EXE1_DIR) fclean
	@make -C $(EXE2_DIR) fclean

re : fclean all
