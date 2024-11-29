# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 12:10:10 by iullibar          #+#    #+#              #
#    Updated: 2024/10/11 11:17:33 by iullibar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -I. -Wextra -Wall -Werror
SRCS = $(wildcard ft_libft/*.c) \
		$(wildcard ft_lst/*.c) \
		$(wildcard ft_printf/*.c) \
		$(wildcard ft_gnl/*.c) \

OBJS = $(SRCS:.c=.o)
NAME = libft.a
HEADER = libft.h
LIB = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)
	
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all
.PHONY: all clean fclean re