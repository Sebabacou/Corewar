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
				-fr $(BUILD_DIR)

# ------ DISPLAY -------- #

ECHO 		= echo
C_RESET 	= \033[00m
C_RED		= \e[31m
C_GREEN 	= \e[32m
C_YELLOW 	= \e[33m
C_BLUE		= \e[34m
C_PINK		= \e[35m
C_FULL_RED	= \e[41m
# ----------------------- #


%:
	@ $(ECHO) "$(C_RED)|==========> RULE NOT FOUND. <==========|$(C_RESET)"

all:
	@ $(CC) -o for_clion lib/my/main.c
	@ mkdir -p $(BUILD_DIR)
	@ mv for_clion $(BUILD_DIR)
	@ $(MAKE) -sC ./lib/
	@ $(MAKE) -sC $(A_PATH)
	@ $(MAKE) -sC $(C_PATH)

clean:
	@ $(RM) $(TMP_FILES)

fclean:		clean
	@ $(RM) $(NAME)
	@ $(MAKE) fclean -sC ./lib/
	@ $(MAKE) fclean -sC $(A_PATH)
	@ $(MAKE) fclean -sC $(C_PATH)

re:		fclean all

debug:
	@ $(MAKE) -sC ./lib/
	@ $(MAKE) debug -sC $(A_PATH)
	@ $(MAKE) debug -sC $(C_PATH)

$(A_NAME):
	@ $(MAKE) -sC ./lib/
	@ $(MAKE) -sC $(A_PATH)

$(C_NAME):
	@ $(MAKE) -sC ./lib/
	@ $(MAKE) -sC $(C_PATH)

a_debug:
	@ $(MAKE) -sC ./lib/
	@ $(MAKE) debug -sC $(A_PATH)

c_debug:
	@ $(MAKE) -sC ./lib/
	@ $(MAKE) debug -sC $(C_PATH)

a_re: fclean $(A_NAME)

c_re: fclean $(C_NAME)

.PHONY: all re clean fclean debug a_debug c_debug a_re c_re asm corewar
