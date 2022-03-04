# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 11:12:01 by kiyoon            #+#    #+#              #
#    Updated: 2022/03/04 18:30:14 by kiyoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

LIBFT       = libft

LIBFT_LIB   = libft.a

SRCS        = ./main.c ./deque1.c ./deque2.c ./input1.c ./input2.c ./instruction1.c ./instruction2.c ./sort1.c ./sort2.c ./sort3.c ./sort4.c ./sort5.c ./quicksort.c

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
