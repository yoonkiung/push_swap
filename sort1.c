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

int	choose_pivot(t_deque *deq, int len, int *big_pivot, int *small_pivot)
{
	t_node	*temp;
	int		i;
	int		*arr;

	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (0);
	i = 0;
	temp = deq->tail;
	while (i < len)
	{
		arr[i++] = temp->data;
		temp = temp->prev;
	}
	quicksort(arr, 0, len - 1);
	*small_pivot = arr[len / 3];
	*big_pivot = arr[(len / 3) * 2];
	free(arr);
	return (1);
}

void	q_sort_a(t_deque *a, t_deque *b, int len)
{
	if (len <= 2 /*|| len == 3 || len == 5*/)
	{
		if (len == 2)
			lenistwo(a, "sa\n", 1);
		if (len == 3)
			lenisthree(a, b);
		if (len == 5)
			lenisfive(a, b);
		return ;
	}
	do_instruct_a(a, b, len);
}

void	q_sort_b(t_deque *a, t_deque *b, int len)
{
	int	empty;

	empty = 0;
	if (len <= 2)
	{
		if (len == 2)
		{
			lenistwo(b, "sb\n", 0);
			push(b, a, "pa\n", &empty);
			push(b, a, "pa\n", &empty);
		}
		else if (len == 1)
			push(b, a, "pa\n", &empty);
		return ;
	}
	/*if (len == 3)
	{
		lenisthree_reverse(a, b);
		push(b, a, "pa\n", &empty);
		push(b, a, "pa\n", &empty);
		push(b, a, "pa\n", &empty);
		return ;
	}*/
	do_instruct_b(a, b, len);
}
