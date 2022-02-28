/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:19:49 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/28 14:19:51 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pushonlymax(t_deque *a, t_deque *b)
{
	int	first;
	int	second;
	int	third;
	int	empty;

	empty = 0;
	first = b->tail->data;
	second = b->tail->prev->data;
	third = b->tail->prev->prev->data;
	if (first > second && first > third)
		push(b, a, "pa\n", &empty);
	else if (second > first && second > third)
	{
		rotate(b, "rb\n", &empty);
		push(b, a, "pa\n", &empty);
		reverse_rotate(b, "rrb\n");
	}
	else
	{
		rotate(b, "rb\n", &empty);
		rotate(b, "rb\n", &empty);
		push(b, a, "pa\n", &empty);
		reverse_rotate(b, "rrb\n");
		reverse_rotate(b, "rrb\n");
	}
}

void	lenisthree_reverse(t_deque *a, t_deque *b)
{
	int	empty;

	empty = 0;
	pushonlymax(a, b);
	lenistwo(b, "sb\n", 0);
	push(a, b, "pb\n", &empty);
}
