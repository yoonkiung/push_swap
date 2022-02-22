/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:04:25 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/20 16:04:27 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	lenistwo(t_deque *a, char *str, int dep)
{
	if (dep == 1)
	{
		if (a->tail->data > a->tail->prev->data)
			swap(a, str);
		return ;
	}
	if (a->tail->data < a->tail->prev->data)
		swap(a, str);
	return ;
}

void	pushonlyleast(t_deque *a, t_deque *b)
{
	int	first;
	int	second;
	int	third;
	int	empty;

	empty = 0;
	first = a->tail->data;
	second = a->tail->prev->data;
	third = a->tail->prev->prev->data;
	if (first < second && first < third)
		push(a, b, "pb\n", &empty);
	else if (second < first && second < third)
	{
		rotate(a, "ra\n", &empty);
		push(a, b, "pb\n", &empty);
		reverse_rotate(a, "rra\n");
	}
	else
	{
		rotate(a, "ra\n", &empty);
		rotate(a, "ra\n", &empty);
		push(a, b, "pb\n", &empty);
		reverse_rotate(a, "rra\n");
		reverse_rotate(a, "rra\n");
	}
}

void	lenisthree(t_deque *a, t_deque *b)
{
	int	empty;

	empty = 0;
	pushonlyleast(a, b);
	lenistwo(a, "sa\n", 1);
	push(b, a, "pa\n", &empty);
}

int	find_min_max(t_deque *a, int dep)
{
	int		ans;
	int		i;
	t_node	*temp;

	temp = a->tail;
	i = 0;
	if (dep == 1)
	{
		ans = INT_MIN;
		while (i++ < 5)
		{
			if (ans < temp->data)
				ans = temp->data;
			temp = temp->prev;
		}
		return (ans);
	}
	ans = INT_MAX;
	while (i++ < 5)
	{
		if (ans > temp->data)
			ans = temp->data;
		temp = temp->prev;
	}
	return (ans);
}

void	lenisfive(t_deque *a, t_deque *b)
{
	int	max;
	int	min;
	int	i;
	int	empty;

	empty = 0;
	i = 0;
	max = find_min_max(a, 1);
	min = find_min_max(a, 0);
	while (i++ < 5)
	{
		if (a->tail->data == min || a->tail->data == max)
			push(a, b, "pb\n", &empty);
		else
			rotate(a, "ra\n", &empty);
	}
	i = 0;
	while (i++ < 3)
		reverse_rotate(a, "rra\n");
	lenistwo(b, "sb\n", 0);
	lenisthree(a, b);
	rotate(b, "rb\n", &empty);
	sort_five_last(a, b);
}
