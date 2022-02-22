/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:23:01 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/17 11:23:02 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_list_all(t_deque *pdeq)
{
	t_node	*temp;

	if (dequeisempty(pdeq))
		return ;
	temp = pdeq->tail;
	while (temp != pdeq->head)
	{
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("%d ", temp->data);
}

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
	if (len == 0)
		return ;
	if (len == 1 || len == 2)
	{
		if (len == 1)
			return ;
		lenistwo(a, "sa\n", 1);
		return ;
	}
	/*f (len == 5)
	{
		lenisfive(a, b);
		return ;
	}*/
	pivot = a->tail->data;
	while (i++ < len)
	{
		if (a->tail->data > pivot)
			rotate(a, "ra\n", &ra);
		else
			push(a, b, "pb\n", &pb);
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
	if (len == 0)
		return ;
	if (len == 1)
	{
		push(b, a, "pa\n", &pa);
		return ;
	}
	pivot = b->tail->data;
	while (i++ < len)
	{
		if (b->tail->data <= pivot)
			rotate(b, "rb\n", &rb);
		else
			push(b, a, "pa\n", &pa);
	}
	back_to_origin(b, rb, "rrb\n");
	q_sort_a(a, b, pa);
	q_sort_b(a, b, rb);
}
