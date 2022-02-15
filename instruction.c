/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:34:15 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/15 14:34:17 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(t_deque *pdeq)
{
	int	temp;

	if (pdeq->head == pdeq->tail || dequeisempty(pdeq))
		return ;
	temp = dqgetlast(pdeq);
	pdeq->tail->data = pdeq->tail->prev->data;
	pdeq->tail->prev->data = temp;
}

void	push(t_deque *a, t_deque *b)
{
	int	temp;

	if (dequeisempty(a))
		return ;
	temp = dqgetlast(a);
	dqremovelast(a);
	dqaddlast(b, temp);
}

int	rotate(t_deque *deq)
{
	int	temp;

	if (dequeisempty(deq) || deq->head == deq->tail)
		return (1);
	temp = dqgetlast(deq);
	if (!dqaddfirst(deq, temp))
		return (0);
	dqremovelast(deq);
	return (1);
}

int	reverse_rotate(t_deque *deq)
{
	int	temp;

	if (dequeisempty(deq) || deq->head == deq->tail)
		return (1);
	temp = dqgetfirst(deq);
	if (!dqaddlast(deq, temp))
		return (0);
	dqremovefirst(deq);
	return (1);
}
