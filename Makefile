# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 16:57:01 by iullibar          #+#    #+#              #
#    Updated: 2024/12/12 11:30:43 by iullibar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Comandos
# -g para debugear con lldb
CFLAGS = -Wall -Wextra -Werror -g

# Nombre ejecutable
NAME = pipex
NAME_BONUS = pipex_bonus

# Ficheros
SRCS1 = main.c
SRCS2 = $(wildcard check_pipex/*.c) \
			$(wildcard pipe/*.c) \
			$(wildcard utils/*.c) \
			$(wildcard stack_utils/*.c) \

SRCS3 = bonus/main_bonus.c \
			bonus/fill_here_doc_bonus.c \

OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
OBJS3 = $(SRCS3:.c=.o)

LIBS = libft/libft.a

all: libs $(NAME)

libs:
	@make -C libft

$(NAME): $(OBJS1) $(OBJS2)
	gcc $(CFLAGS) $(OBJS1) $(OBJS2) $(LIBS) -o $(NAME)

bonus: $(OBJS2) $(OBJS3)
	@make -C libft
	gcc $(CFLAGS) $(OBJS2) $(OBJS3) $(LIBS) -o $(NAME_BONUS)
	
%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<
	
clean:
	@make clean -C libft
	rm -f $(OBJS1) $(OBJS2) $(OBJS3)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS) $(LIBS)

re: fclean all
.PHONY: all clean fclean re