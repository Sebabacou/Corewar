##
## EPITECH PROJECT, 2023
## template_project_c
## File description:
## Makefile
##

CC 			= 	gcc

NAME		=	corewar

VPATH := src
VPATH += src/tools
VPATH += src/display
VPATH += src/free
VPATH += src/initialization/
VPATH += src/initialization/vm
VPATH += src/initialization/champion
VPATH += src/vm_cpu
VPATH += src/vm_cpu/manage_action
VPATH += src/fct_champ

vpath %.c $(VPATH)

#========> OTHER <=======#
SRC := main.c
SRC += help_checker.c

#========> FREE <=======#
SRC += free_all.c
SRC += my_free.c
SRC += free_champ.c

#==========> INITIALIZATION <=========#
SRC += init_virtual_machine.c
SRC += check_argv.c
SRC += settings_dump.c
SRC += check_settings_flag.c
SRC += init_champion.c
SRC += settings_id.c
SRC += settings_load_address.c
SRC += read_champion.c
SRC += init_startchamp.c
SRC += load_champion_in_vm.c
SRC += init_process.c
SRC += define_name_champ.c

#=========> VM <========#
SRC += loop_vm.c
SRC += check_action.c
SRC += define_wait_cycle.c
SRC += get_arg_type.c
SRC += get_arg_value.c
SRC += move_process.c
SRC += define_pc.c
SRC += check_win.c

#=========> FCT <========#
SRC += fct_live.c
SRC += fct_ld.c
SRC += fct_st.c
SRC += fct_add.c
SRC += fct_sti.c
SRC += fct_sub.c
SRC += fct_and.c
SRC += fct_or.c
SRC += fct_xor.c
SRC += fct_zjmp.c
SRC += fct_ldi.c
SRC += fct_sti.c
SRC += fct_fork.c
SRC += fct_lld.c
SRC += fct_lldi.c
SRC += fct_lfork.c
SRC += fct_aff.c

#========> DISPLAY <=======#
SRC += display_help.c
SRC += display_buffer.c

#=========> TOOLS <========#
SRC += del_char.c
SRC += convert_endian.c
SRC += take_number.c
SRC += create_pos_from_value.c
SRC += create_value_from_pos.c

BUILD_DIR	=	../.trash/corewar

OBJ			=	$(SRC:%.c=$(BUILD_DIR)/%.o)

LIB_FLAGS	=	-L./../lib/ -lmy -lprint
IFLAGS		=	-I./include/ -I./../include/ -I./../lib/include/
CFLAGS		=	-Wall -Wextra -Werror $(IFLAGS) -g

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

all:	$(NAME)

%:
	@ $(ECHO) "$(C_RED)|==========> RULE NOT FOUND. <==========|$(C_RESET)"

%.c:
	@ $(ECHO) "$(C_PINK)[corewar] $(C_RESET)-> $(C_RED)$@$(C_RESET)"
	@ $(DIE)

$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ $(ECHO) "$(C_PINK)[corewar]$(C_RESET) -> $<"

$(NAME):	$(OBJ)
	@ $(CC) -o $@ $^ $(LIB_FLAGS)
	@ $(ECHO) "$(C_PINK)|==========> $(NAME) compiled. <==========|$(C_RESET)"

fclean:
	@ $(RM) $(NAME)

debug: CFLAGS += -g
debug: all

.PHONY: all fclean debug
