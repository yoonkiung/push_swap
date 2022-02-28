/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:56:36 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/26 21:56:37 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	travel_bintree(t_deque *deq, int *map, int empty)
{
	int		index;
	t_node	*temp;

	temp = deq->head;
	while (temp)
	{
		index = 1;
		while (map[index] != empty)
		{
			if (map[index] > temp->data)
				index = index * 2;
			else if (map[index] < temp->data)
				index = index * 2 + 1;
			else
				return (0);
		}
		map[index] = temp->data;
		temp = temp->next;
	}
	return (1);
}

void	when_error(t_deque *a, t_deque *b)
{
	ft_putstr_fd("Error\n", 1);
	dqfreeall(a);
	dqfreeall(b);
	exit(1);
}
