/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:07:55 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/20 17:07:56 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_five_last(t_deque *a, t_deque *b)
{
	int	i;
	int	empty;

	empty = 0;
	i = 0;
	while (i++ < 3)
		rotate(a, "ra\n", &empty);
	push(b, a, "pa\n", &empty);
	i = 0;
	while (i++ < 3)
		reverse_rotate(a, "rra\n");
	push(b, a, "pa\n", &empty);
}

void	do_reverse(t_deque *a, t_deque *b, int ra, int rb)
{
	int	len_a;
	int	len_b;

	len_a = deq_len(a);
	len_b = deq_len(b);
	if (len_a == ra || len_b == rb)
	{
		if (len_a == ra && len_b == rb)
			return ;
		else if (len_a == ra)
			while (rb-- > 0)
				reverse_rotate(b, "rrb\n");
		else
			while (ra-- > 0)
				reverse_rotate(a, "rra\n");
		return ;
	}
	rotate_if_diff(a, b, ra, rb);
}

void	init_variable(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

void	do_instruct_a(t_deque *a, t_deque *b, int len)
{
	int	ra;
	int	pb;
	int	rb;
	int	big_pivot;
	int	small_pivot;

	init_variable(&ra, &pb, &rb);
	if (!choose_pivot(a, len, &big_pivot, &small_pivot))
		when_error(a, b);
	while (len-- > 0)
	{
		if (dqgetlast(a) >= big_pivot)
			rotate(a, "ra\n", &ra);
		else
		{
			push(a, b, "pb\n", &pb);
			if (dqgetlast(b) >= small_pivot)
				rotate(b, "rb\n", &rb);
		}
	}
	do_reverse(a, b, ra, rb);
	q_sort_a(a, b, ra);
	q_sort_b(a, b, rb);
	q_sort_b(a, b, pb - rb);
}

void	do_instruct_b(t_deque *a, t_deque *b, int len)
{
	int	ra;
	int	pa;
	int	rb;
	int	big_pivot;
	int	small_pivot;

	init_variable(&ra, &pa, &rb);
	if (!choose_pivot(b, len, &big_pivot, &small_pivot))
		when_error(a, b);
	while (len-- > 0)
	{
		if (dqgetlast(b) < small_pivot)
			rotate(b, "rb\n", &rb);
		else
		{
			push(b, a, "pa\n", &pa);
			if (dqgetlast(a) < big_pivot)
				rotate(a, "ra\n", &ra);
		}
	}
	q_sort_a(a, b, pa - ra);
	do_reverse(a, b, ra, rb);
	q_sort_a(a, b, ra);
	q_sort_b(a, b, rb);
}
