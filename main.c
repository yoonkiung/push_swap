/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:10:58 by kiyoon            #+#    #+#             */
/*   Updated: 2022/03/02 12:24:27 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_deque	deq_a;
	t_deque	deq_b;

	if (!input(ac, av, &deq_a))
	{
	//system("leaks push_swap > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
		return (0);
	}
	dequeinit(&deq_b);
	if (!is_all_diff(&deq_a))
		when_error(&deq_a, &deq_b);
	q_sort_a(&deq_a, &deq_b, size(&deq_a));
	
	//system("leaks push_swap > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	/*printf("a : ");
	while (!dequeisempty(&deq_a))
		printf("%d ", dqremovelast(&deq_a));
	printf("\nb : ");
	while (!dequeisempty(&deq_b))
		printf("%d ", dqremovelast(&deq_b));*/
	dqfreeall(&deq_a);
	dqfreeall(&deq_b);
	return (0);
}
