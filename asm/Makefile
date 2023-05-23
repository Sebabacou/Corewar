##
## EPITECH PROJECT, 2023
## template_project_c
## File description:
## Makefile
##

CC 			= 	gcc

NAME		=	asm

VPATH := src
VPATH += src/error_handle
VPATH += src/error_handle/tiret_h
VPATH += src/manage_file
VPATH += src/init
VPATH += src/destroy_bomber
VPATH += src/error_handle/handle_pointer
VPATH += src/error_handle/link_list
VPATH += src/tools

vpath %.c $(VPATH)

SRC := main.c
SRC += error_handle.c
SRC += print_h.c
SRC += open_read_file.c
SRC += init_all.c
SRC += free_all.c
SRC += take_name.c
SRC += clean_str.c
SRC += verif_args.c
SRC += error_label.c
SRC += verif_com.c
SRC += take_add.c
SRC += take_aff.c
SRC += take_fork.c
SRC += take_ld.c
SRC += take_ldi.c
SRC += take_live.c
SRC += take_st.c
SRC += take_sti.c
SRC += take_and.c
SRC += check_all_args.c
SRC += reg_in_dir.c
SRC += free_link.c
SRC += add_command.c
SRC += check_labels.c
SRC += get_arg_size.c
SRC += prog_size_calculator.c
SRC += size_coding_bite.c

BUILD_DIR	=	../.trash/asm

OBJ			=	$(SRC:%.c=$(BUILD_DIR)/%.o)

LIB_FLAGS	=	-L./../lib/ -lmy -lprint
IFLAGS		=	-I./include/ -I./../include/ -I./../lib/include/
CFLAGS		=	-Wall -Wextra -Werror $(IFLAGS)

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
	@ $(ECHO) "$(C_BLUE)[ASM] $(C_RESET)-> $(C_RED)$@$(C_RESET)"
	@ $(DIE)

$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ $(ECHO) "$(C_BLUE)[ASM]$(C_RESET) -> $<"

$(NAME):	$(OBJ)
	@ $(CC) -o $@ $(OBJ) $(LIB_FLAGS)
	@ $(ECHO) "$(C_BLUE)|==========> $(NAME) compiled. <==========|$(C_RESET)"

fclean:
	@ $(RM) $(NAME)

debug: CFLAGS += -g
debug: all

.PHONY: all fclean debug
