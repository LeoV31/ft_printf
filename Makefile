# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lviguier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 16:10:30 by lviguier          #+#    #+#              #
#    Updated: 2024/06/19 18:39:28 by lviguier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c ft_ptr.c ft_hex.c ft_unsigned.c
SRC_DIR = src/
INC_DIR = inc/
SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -I$(INC_DIR) $< -o $@

$(NAME): $(OBJS)
	@make -C libft
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@ar -r $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) test_printf.o
	@cd ./libft && make clean

fclean: clean
	rm -f $(NAME) test_printf
	@cd ./libft && make fclean

re: fclean $(NAME)

test: $(NAME) test_printf.o
	$(CC) $(CFLAGS) -o test_printf test_printf.o -L. -lftprintf
	./test_printf

test_printf.o: test_printf.c
	$(CC) $(CFLAGS) -c test_printf.c -o test_printf.o

.PHONY: all clean fclean re
