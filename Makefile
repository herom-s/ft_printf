# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 09:35:18 by hermarti          #+#    #+#              #
#    Updated: 2025/08/04 16:09:22 by hermarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
LIBFT := libft/libft.a

LIBFTINC := libft/inc/
IDIR := inc/
SDIR := src/
SRCS := $(SDIR)ft_printf.c \
		$(SDIR)ft_printf_char.c \
		$(SDIR)ft_printf_decimal.c \
		$(SDIR)ft_printf_interger.c \
		$(SDIR)ft_printf_pointer.c \
		$(SDIR)ft_printf_string.c \
		$(SDIR)ft_printf_uinterger.c \
		$(SDIR)ft_printf_hex.c
SRCSBONUS := $(SDIR)ft_printf.c

OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(SRCSBONUS:.c=.o)

CC := cc
CFLAGS := -I$(LIBFTINC) -I$(IDIR) -Wall -Wextra -Werror

RM = rm -f

.PHONY: all bonus clean fclean re

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $@
	ar rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	$(MAKE) $(OBJS)=$(OBJS) $(BONUSOBJS)

clean:
	$(RM) $(OBJS) $(BONUSOBJS)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all
