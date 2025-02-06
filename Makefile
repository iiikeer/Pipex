# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 16:57:01 by iullibar          #+#    #+#              #
#    Updated: 2025/02/06 10:43:55 by iullibar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Comandos
# -g para debugear con lldb
CFLAGS = -Wall -Wextra -Werror -g

# Nombre ejecutable
NAME = pipex
NAME_BONUS = pipex_bonus

# Ficheros
SRCS = srcs/main.c \
		$(wildcard srcs/check_pipex/*.c) \
		$(wildcard srcs/pipe/*.c) \
		$(wildcard srcs/utils/*.c) \
		$(wildcard srcs/stack_utils/*.c) \

SRCSB = $(wildcard srcs/check_pipex/*.c) \
		$(wildcard srcs/pipe/*.c) \
		$(wildcard srcs/utils/*.c) \
		$(wildcard srcs/stack_utils/*.c) \
		$(wildcard srcs/bonus/*.c) \

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

LIBS = libft/libft.a

all: libs $(NAME)

libs:
	@make -s -C libft

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<
	
bonus: $(OBJSB)
	@rm -rf srcs/main.o
	@make -s -C libft
	gcc $(CFLAGS) $(OBJSB) $(LIBS) -o $(NAME_BONUS)
	
clean:
	@make clean -s -C libft
	rm -f $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS) $(LIBS)

re: fclean all
.PHONY: all clean fclean re