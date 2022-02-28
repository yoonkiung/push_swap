/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:21:02 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/28 23:57:49 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_deque	deq_a;
	t_deque	deq_b;
	int		len;

	if (!input(ac, av, &deq_a))
		return (0);
	/*printf("origin : ");
	while (!dequeisempty(&deq_a))
		printf("%d ",dqremovelast(&deq_a));
	return (0);
	if (!is_all_diff(&deq_a))
		return (0);*/
	dequeinit(&deq_b);
	len = deq_len(&deq_a);
	q_sort_a(&deq_a, &deq_b, size(&deq_a));
	printf("a : ");
	while (!dequeisempty(&deq_a))
		printf("%d ",dqremovelast(&deq_a));
	printf("\nb : ");
	while (!dequeisempty(&deq_b))
		printf("%d ", dqremovelast(&deq_b));
	return (0);
}
