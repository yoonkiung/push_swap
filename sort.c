/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:23:01 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/17 11:23:02 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	back_to_origin(t_deque *deq, int ra, char *str)
{
	int	i;

	i = 0;
	while (i < ra)
	{
		reverse_rotate(deq, str);
		i++;
	}
}

void	q_sort_a(t_deque *a, t_deque *b, int len)
{
	int	pivot;
	int	i;
	int	ra;
	int	pb;

	pb = 0;
	ra = 0;
	i = 0;
	pivot = a->tail->data;
	if (len == 1)
		return ;
	while (i++ < len)
	{
		if (a->tail->data > pivot)
		{
			rotate(a, "ra\n");
			ra++;
		}
		else
		{
			push(a, b, "pb\n");
			pb++;
		}
	}
	back_to_origin(a, ra, "rra\n");
	q_sort_a(a, b, ra);
	q_sort_b(a, b, pb);
}

void	q_sort_b(t_deque *a, t_deque *b, int len)
{
	int	pivot;
	int	i;
	int	rb;
	int	pa;

	pa = 0;
	rb = 0;
	i = 0;
	pivot = b->tail->data;
	if (len == 1)
		return ;
	while (i++ < len)
	{
		if (b->tail->data > pivot)
		{
			rotate(b, "rb\n");
			rb++;
		}
		else
		{
			push(b, a, "pa\n");
			pa++;
		}
	}
	back_to_origin(a, rb, "rrb\n");
	q_sort_a(a, b, pa);
	q_sort_b(a, b, rb);
}
