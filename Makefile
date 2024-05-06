#----------------------------------------------------------------------------
#								VAR
#----------------------------------------------------------------------------

NAME		= libftprintf.a
AR			= ar rcs #create library, (replace, create, sort)
RM			= rm -f
LIB			= ranlib
CC			= cc
CFLAGS 		= -Wall -Wextra -Werror

#----------------------------------------------------------------------------
#								DIRECTORY
#----------------------------------------------------------------------------

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
					./ft_padding_bonus.c \
					./ft_print_char_flags_bonus.c \
					./ft_print_format_bonus.c \
					./ft_printf_bonus.c \
					./ft_print_char.c \
					./ft_print_str.c \
					./ft_print_str_flags_bonus.c \
					./ft_print_ptr.c \
					./ft_print_num_base.c \
					./ft_check_write_return_count.c

OBJ_FILES		= $(SRC_FILES:.c=.o)
OBJ_BONUS_FILES	= $(SRC_BONUS_FILES:.c=.o)

#----------------------------------------------------------------------------
#								LIBFT
#----------------------------------------------------------------------------
LIBFT_DIR = ./libft/
LIBFT = libft.a
LIBFT_AR = $(addprefix $(LIBFT_DIR), $(LIBFT))
#----------------------------------------------------------------------------
#								TARGETS $(AR) $(NAME) $(OBJ_FILES) #$(LIB) $(NAME)
#----------------------------------------------------------------------------


all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(AR) $(NAME) $(OBJ_FILES)
	$(LIB) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@

bonus: .bonus

.bonus: $(OBJ_BONUS_FILES)
	$(AR) $(NAME) $(OBJ_BONUS_FILES)
	$(LIB) $(NAME)
	@touch .bonus

clean:
	$(RM) $(OBJ_FILES) $(OBJ_BONUS_FILES)
	@rm -f .bonus

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
