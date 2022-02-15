# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 11:12:01 by kiyoon            #+#    #+#              #
#    Updated: 2022/02/09 15:06:09 by kiyoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

LIBFT       = libft

LIBFT_LIB   = libft.a

SRCS        = ./main.c ./deque1.c ./deque2.c ./input.c ./instruction.c

OBJS        = $(SRCS:.c=.o)

INCS        = .

RM          = rm -f

LIBC        = ar rc

CC          = gcc

CFLAGS      = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	mv $(LIBFT)/$(LIBFT_LIB) .
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)

all : $(NAME)

fclean : clean
	$(RM) $(NAME) $(LIBFT_LIB)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re : fclean all

.PHONY : all clean clean re
