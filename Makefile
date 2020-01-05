# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/04 22:58:33 by mel-adna          #+#    #+#              #
#    Updated: 2020/01/04 23:26:50 by mel-adna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
SRCS=main.c iso.c parallel.c stock_input.c checker.c draw.c init_params.c reader.c
OBJS=$(SRCS:.c=.o)
CC=gcc
CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make -C headers/libft
	$(CC) $(CFLAGS) -L. -lmlx -framework OpenGL -framework Appkit $(OBJS) ./headers/libft/libft.a -o $(NAME)

$(OBJS): %.o : %.c headers/fdf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C headers/libft clean
	rm -f $(OBJS)

fclean: clean
	make -C headers/libft fclean
	rm -rf $(NAME)

re : fclean all
