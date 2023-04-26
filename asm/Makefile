##
## EPITECH PROJECT, 2023
## template_project_c
## File description:
## Makefile
##

CC 			= 	gcc

NAME		=	asm

VPATH := src

vpath %.c $(VPATH)

SRC := main.c
SRC += op.c

BUILD_DIR	=	../.trash/asm

OBJ			=	$(SRC:%.c=$(BUILD_DIR)/%.o)

LIB_FLAGS	=	-L./../lib/ -lmy
CFLAGS		=	-Wall -Wextra -I./include/ -I./../include/ -I./../lib/include/

TMP_FILES	=	*.gcno					\
				*.gcda					\
				vgcore.*				\
				*.log					\
				$(OBJ)

DIE = exit 1

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

all:		$(NAME)

%:
	@ $(ECHO) "$(C_RED)|==========> RULE NOT FOUND. <==========|$(C_RESET)"

%.c:
	@ $(ECHO) "$(C_RED)[ASM] -> $@$(C_RESET)"
	@ $(DIE)

$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ $(ECHO) "$(C_BLUE)[ASM]$(C_RESET) -> $<"

$(NAME):	$(OBJ)
	@ $(CC) -o $@ $? $(LIB_FLAGS)
	@ $(ECHO) "$(C_BLUE)|==========> $(NAME) compiled. <==========|$(C_RESET)"

fclean:
	@ $(RM) $(NAME)

debug: CFLAGS += -g
debug: CFLAGS += -Werror
debug: all

.PHONY: all re fclean debug
