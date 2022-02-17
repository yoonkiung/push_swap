/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:00:52 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/08 12:41:33 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "./libft/libft.h"

# define TRUE 1

# define FALSE 0

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	t_node	*head;
	t_node	*tail;
}	t_deque;

int		is_all_digit(char *str);

int		isin_dec(char *str);

int		check_error(char *str);

int		input(int ac, char **av, t_deque *deq);

void	dequeinit(t_deque *pdeq);

int		dequeisempty(t_deque *pdeq);

int		dqaddfirst(t_deque *pdeq, int data);

int		dqaddlast(t_deque *pdeq, int data);

int		dqremovefirst(t_deque *pdeq);

int		dqremovelast(t_deque *pdeq);

int		dqgetfirst(t_deque *pdeq);

int		dqgetlast(t_deque *pdeq);

void	dqfreeall(t_deque *pdeq);

void	swap(t_deque *pdeq, char *str);

void	push(t_deque *a, t_deque *b, char *str);

int		rotate(t_deque *deq, char *str);

int		reverse_rotate(t_deque *deq, char *str);

int		size(t_deque *pdeq);

void	back_to_origin(t_deque *deq, int ra, char *str);

void	q_sort_a(t_deque *a, t_deque *b, int len);

void	q_sort_b(t_deque *a, t_deque *b, int len);

#endif
