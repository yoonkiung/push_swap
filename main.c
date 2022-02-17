/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:21:02 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/08 12:40:58 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_deque	deq_a, deq_b;

	if (!input(ac, av, &deq_a))
		return (0);
	q_sort_a(&deq_a, &deq_b, size(&deq_a));
	while (!dequeisempty(&deq_a))
		dqremovelast(&deq_a);
	printf("\n");
	while (!dequeisempty(&deq_b))
		dqremovelast(&deq_b);
	return (0);
}
