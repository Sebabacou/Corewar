##
## EPITECH PROJECT, 2023
## template_project_c
## File description:
## Makefile
##

CC = gcc

A_NAME		= asm
C_NAME		= corewar

A_PATH		= ./asm/
C_PATH		= ./corewar/

BUILD_DIR	= ./.trash

TMP_FILES	=	*.gcno					\
				*.gcda					\
				vgcore.*				\
				coding-style-reports.log\
				-rf $(BUILD_DIR)

# ------ DISPLAY -------- #

ECHO 		= echo
C_RESET 	= \033[00m
C_RED		= \e[31m
C_GREEN 	= \e[32m
C_YELLOW 	= \e[33m
C_BLUE		= \e[34m
C_PINK		= \e[35m
C_CYAN		= \e[36m
C_GREY		= \e[37m
C_FULL_RED	= \e[41m
# ----------------------- #

%:
	@ $(ECHO) "$(C_RED)|==========> RULE NOT FOUND. <==========|$(C_RESET)"

all: $(A_NAME) $(C_NAME)
	@ $(CC) -o for_clion lib/my/main.c
	@ rm for_clion

$(A_NAME): lib
	@ $(MAKE) -sC $(A_PATH)

$(C_NAME): lib
	@ $(MAKE) -sC $(C_PATH)

clean:
	@ $(RM) $(TMP_FILES)

fclean:		clean
	@ $(RM) $(NAME)
	@ $(MAKE) fclean -sC ./lib/my
	@ $(MAKE) fclean -sC ./lib/my_printf
	@ $(MAKE) fclean -sC $(A_PATH)
	@ $(MAKE) fclean -sC $(C_PATH)
	@ $(ECHO) "$(C_GREY)|==========> TEMPORARY FILE DEL. <==========|$(C_RESET)"

re:		fclean all

debug: fclean a_debug c_debug

a_debug: lib
	@ $(MAKE) debug -sC $(A_PATH)

c_debug: lib
	@ $(MAKE) debug -sC $(C_PATH)

lib:
	@ $(MAKE) -sC ./lib/my
	@ $(MAKE) -sC ./lib/my_printf

.PHONY: all re clean fclean debug a_debug c_debug asm corewar lib
