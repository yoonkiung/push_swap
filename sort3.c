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
		push(a, b, "pa\n", &empty);
	reverse_rotate(b, "rrb\n");
	i = 0;
	while (i++ < 5)
		push(b, a, "pb\n", &empty);
}
