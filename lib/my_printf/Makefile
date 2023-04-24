##
## EPITECH PROJECT, 2022
## makefile printf
## File description:
## makefile printf
##

SRC =	src_printf/conversion/flag_b.c	\
		src_printf/conversion/flag_o.c	\
		src_printf/conversion/flag_x.c	\
		src_printf/conversion/flag_upx.c	\
		src_printf/param/param_minus_plus.c		\
		src_printf/numbers/flag_f.c	\
		src_printf/numbers/flag_i_d.c	\
		src_printf/numbers/flags_e.c	\
		src_printf/numbers/flag_upe.c	\
		src_printf/numbers/flags_u.c	\
		src_printf/str/flag_c.c		\
		src_printf/str/flag_mod.c		\
		src_printf/str/flag_s.c		\
		src_printf/str/flag_ups.c		\
		src_printf/others/flag_n.c		\
		src_printf/others/flag_p.c		\
		src_printf/base/my_compute_power_rec.c	\
		src_printf/base/my_printf.c	\
		src_printf/base/my_put_nbr_base.c	\
		src_printf/base/my_put_nbr.c	\
		src_printf/base/my_put_unsigned_base.c	\
		src_printf/base/my_put_unsigned_nbr.c	\
		src_printf/base/my_count_nbr_base.c	\
		src_printf/base/my_putchar.c	\
		src_printf/base/my_putfloat.c	\
		src_printf/base/my_putstr_non_print.c	\
		src_printf/base/my_putstr.c	\
		src_printf/base/my_revstr.c	\
		src_printf/base/my_scinbr.c	\
		src_printf/base/my_strlen.c	\
		src_printf/base/cut_string.c	\
		src_printf/base/scan_params.c	\
		src_printf/base/my_getnbr.c	\
		src_printf/base/my_get_nbr_aft_point.c \
		src_printf/base/my_put_nbr_pres.c	\
		src_printf/base/my_puttab.c	\
		src_printf/str/flag_t.c	\
		src_printf/str/my_error_flag.c


BUILD_DIR = ../../.trash/

OBJ = $(SRC:%.c=$(BUILD_DIR)%.o)

CFLAGS = -I include/ -Wextra -Wall

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

NAME = libprint.a

TMP_FILES	=	*.gcno					\
				*.gcda					\
				vgcore.*				\
				*.log					\
				-r $(BUILD_DIR)			\
				$(LIB_OBJ)

DIE = exit 1

# ------ DISPLAY -------- #
ECHO 		= echo
C_RESET 	= \033[00m
C_RED		= \e[31m
C_GREEN 	= \e[32m
C_YELLOW 	= \e[33m
C_PINK		= \e[35m
C_BLUE		= \e[36m
C_FULL_RED	= \e[41m
# ----------------------- #

all: $(NAME)

%.c:
	@ $(ECHO) "$(C_RED)[MY_PRINTF] -> $@$(C_RESET)"
	@ $(DIE)

$(BUILD_DIR)%.o: %.c
	@mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ $(ECHO) "$(C_GREEN)[MY_PRINTF]$(C_RESET) -> $<"

$(NAME): $(OBJ)
	@ ar rc $(NAME) $(OBJ)
	@ mv $(NAME) ../
	@ mkdir -p ../include
	@ cp include/myprintf.h ../include
	@ $(ECHO) "$(C_GREEN)|==========> $(NAME) compiled. <==========|$(C_RESET)"

clean:
	rm -f $(TMP_FILE)

fclean: clean
	rm -f ../$(NAME)

re: 	fclean all

test_run:	$(OBJ)
	gcc -o test_units $(SRC) tests/test.c -I include/ --coverage -lcriterion
	-./test_units
	gcovr --exclude tests/
	rm *.gcno
	rm *.gcda
	rm test_units

run:
	gcc main.c -L. -lmy -I include/ -o run
	-./run

debug:	$(OBJ)
	gcc main.c $(OBJ) -I include/ -g -o debug
	valgrind ./debug

.PHONY: .SILENT lib re all test_run clean fclean test_run run
