##
## EPITECH PROJECT, 2023
## template_project_c
## File description:
## Makefile
##


TMP_FILES	=	*.gcno					\
				*.gcda					\
				vgcore.*				\
				coding-style-reports.log\
				-r $(BUILD_DIR)

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

all:
	@ $(MAKE) -j -sC ./my
	@ $(MAKE) -j -sC ./my_printf

fclean:
	@ $(MAKE) fclean -sC ./my
	@ $(MAKE) fclean -sC ./my_printf

.PHONY: all fclean
