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
					./ft_check_write_return_count.c

SRC_BONUS_FILES	=	./ft_flag_digit_bonus.c \
					./ft_flag_init_bonus.c \
					./ft_flag_justify_left_bonus.c \
					./ft_flag_precision_bonus.c \
					./ft_flag_width_digit_bonus.c \
					./ft_flag_width_star_bonus.c \
					./ft_isprintformat_bonus.c \
					./ft_pad_bonus.c \
					./ft_print_char_flags_bonus.c \
					./ft_print_format_bonus.c \
					./ft_printf_bonus.c \
					./ft_print_char.c \
					./ft_print_str.c \
					./ft_num_len_bonus.c \
					./ft_print_num_base_bonus.c \
					./ft_print_str_flags_bonus.c \
					./ft_print_ptr_flags_bonus.c \
					./ft_check_write_return_count.c \
					./ft_output_format_bonus.c 
OBJ_FILES		= $(SRC_FILES:.c=.o)
OBJ_BONUS_FILES	= $(SRC_BONUS_FILES:.c=.o)

#----------------------------------------------------------------------------
#								LIBFT
#----------------------------------------------------------------------------

LIBFT_DIR	= ./libft/
LIBFT		= libft.a
LIBFT_PATH	= $(addprefix $(LIBFT_DIR), $(LIBFT))

#----------------------------------------------------------------------------
#								TARGETS
#----------------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	cp	$(LIBFT_PATH) $(NAME)
	$(AR) $(NAME) $(OBJ_FILES)
	$(LIB) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@

bonus: .bonus

.bonus: $(LIBFT) $(OBJ_BONUS_FILES) 
	cp	$(LIBFT_PATH) $(NAME)
	$(AR) $(NAME) $(OBJ_BONUS_FILES)
	$(LIB) $(NAME)
	@touch .bonus

clean: 
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_FILES)  $(OBJ_BONUS_FILES)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
