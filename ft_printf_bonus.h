/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:35:34 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/17 13:50:54 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"

# define PTR_NULL "0x0"

typedef struct s_flag_format
{
	int	sign;
	int	left;
	int	space;
	int	zero;
	int	hash;
	int	width;
	int	width_star;
	int	precision;
	int	precision_width;
	int	specifier;
}	t_flag_format;

typedef struct s_output_format
{
	int			sign;
	int			left;
	int			hash;
	int			left_zeros;
	int			right_zeros;
	int			left_spaces;
	int			right_spaces;
	int			specifier;
}	t_output_format;

/*-------------------------------------------------------------------------*/
/*	FT_PRINT_PTR.C	*/
/*-------------------------------------------------------------------------*/

int				ft_print_ptr_flags_bonus(unsigned long p, t_flag_format flags);

/*-------------------------------------------------------------------------*/
/*	ft_num_len_flag.C	*/
/*-------------------------------------------------------------------------*/

int				ft_num_len_flag(long long n, t_flag_format f);
int				ft_num_len_base(long long n, int base);

/*-------------------------------------------------------------------------*/
/*	FT_PRINT_NUM_BASE.C	*/
/*-------------------------------------------------------------------------*/

int				ft_print_num_base_bonus(long long n, t_flag_format *f);

/*-------------------------------------------------------------------------*/
/*	FT_PRINT_CHAR.C	*/
/*-------------------------------------------------------------------------*/

int				ft_print_char(int c);
int				ft_print_char_flags_bonus(int c, t_flag_format flags);

/*-------------------------------------------------------------------------*/
/*	FT_PRINT_STR.C	*/
/*-------------------------------------------------------------------------*/

int				ft_print_str(char *str);
int				ft_print_str_flags_bonus(char *str, t_flag_format flags);

/*-------------------------------------------------------------------------*/
/*	FT_PRINTF.C	*/
/*-------------------------------------------------------------------------*/

int				ft_print_format_bonus(t_flag_format flags, va_list ap);
int				ft_check_write_return_count(int c);
int				ft_printf(const char *format, ...);

/*-------------------------------------------------------------------------*/
/*	FLAG FORMATS	*/
/*-------------------------------------------------------------------------*/
/*	%[flags][width][.precision]type */
/*-------------------------------------------------------------------------*/
t_flag_format	ft_flag_init_bonus(void);
t_flag_format	ft_flag_justify_left_bonus(t_flag_format format);
t_flag_format	ft_flag_width_star_bonus(va_list args, t_flag_format flags);
t_flag_format	ft_flag_digit_bonus(char c, t_flag_format flags);
t_flag_format	ft_flag_width_digit_bonus(int c, t_flag_format flags);

/*-------------------------------------------------------------------------*/
/*	PADDING	*/
/*-------------------------------------------------------------------------*/
int				ft_pad_bonus(int max_width, int len, int has_zero_pad);
/*-------------------------------------------------------------------------*/
/*	FLAG TYPES	*/
/*-------------------------------------------------------------------------*/
int				ft_isdigit(int c);
int				ft_isflag_bonus(int c);
int				ft_isspecifier_bonus(int c);
int				ft_isprintformat_bonus(int c);
int				ft_flag_precision_bonus(const char *str, int index,
					va_list args, t_flag_format *flags);

/*-------------------------------------------------------------------------*/
/*								OUTPUT FORMATS								*/
/*-------------------------------------------------------------------------*/

t_output_format	output_format_init(t_flag_format *f);
int				ft_print_output_num(
					long long n,
					t_output_format *o,
					t_flag_format *f,
					char *base);

#endif