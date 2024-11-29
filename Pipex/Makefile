# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 16:57:01 by iullibar          #+#    #+#              #
#    Updated: 2024/11/29 10:51:00 by iullibar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Comandos
# -g para debugear con lldb
CFLAGS = -Wall -Wextra -Werror -g

# Nombre ejecutable
NAME = pipex

# Ficheros
SRCS1 = main.c
SRCS2 = $(wildcard check_pipex/*.c) \
			$(wildcard pipe/*.c) \
			$(wildcard utils/*.c) \
			$(wildcard stack_utils/*.c) \

OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)

LIBS = libft/libft.a

all: libs $(NAME)

libs:
	@make -C libft

$(NAME): $(OBJS1) $(OBJS2)
	gcc $(CFLAGS) $(OBJS1) $(OBJS2) $(LIBS) -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	@make clean -C libft
	rm -f $(OBJS1) $(OBJS2)

fclean: clean
	rm -f $(NAME) $(LIBS)

re: fclean all
.PHONY: all clean fclean re