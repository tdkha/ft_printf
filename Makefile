#----------------------------------------------------------------------------
#								VARIABLES
#----------------------------------------------------------------------------

NAME		= libftprintf.a
AR			= ar rcs
RM			= rm -f
LIB			= ranlib
CC			= cc
CFLAGS 		= -Wall -Wextra -Werror
HEAD			= ./includes/
SRC_FILES		= 	./ft_print_char.c \
					./ft_print_str.c \
					./ft_print_ptr.c \
					./ft_print_num_base.c \
					./ft_print_format.c \
					./ft_printf.c \
					./ft_print_char.c

SRC_BONUS_FILES	=	./ft_flag_digit_bonus.c \
					./ft_flag_init_bonus.c \
					./ft_flag_justify_left_bonus.c \
					./ft_flag_precision_bonus.c \
					./ft_flag_width_digit_bonus.c \
					./ft_flag_width_star_bonus.c \
					./ft_isprintformat_bonus.c \
					./ft_printf_utils_bonus.c \
					./ft_print_char_bonus.c \
					./ft_print_format_bonus.c \
					./ft_printf_bonus.c \
					./ft_print_char.c \
					./ft_print_str.c \
					./ft_num_len_bonus.c \
					./ft_print_num_base_bonus.c \
					./ft_print_ptr_bonus.c \
					./ft_print_char.c \
					./ft_output_format_bonus.c \
					./ft_output_number_bonus.c \
					./ft_output_str_bonus.c \
					./ft_output_ptr_bonus.c \
					./ft_print_str_bonus.c
OBJ_FILES		= $(SRC_FILES:.c=.o)
OBJ_BONUS_FILES	= $(SRC_BONUS_FILES:.c=.o)

#----------------------------------------------------------------------------
#								TARGETS
#----------------------------------------------------------------------------


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $ $(OBJ_FILES)
	$(AR) $(NAME) $(OBJ_FILES)
	$(LIB) $(NAME)

bonus: .bonus

.bonus:  $(OBJ_BONUS_FILES)
	$(AR) $(NAME) $(OBJ_BONUS_FILES)
	@touch .bonus

clean:
	$(RM) $(OBJ_FILES)  $(OBJ_BONUS_FILES)
	@rm -f .bonus

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
