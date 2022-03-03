/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:34:15 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/15 14:34:17 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(t_deque *pdeq, char *str)
{
	int	temp;

	if (pdeq->head == pdeq->tail || dequeisempty(pdeq))
		return ;
	temp = dqgetlast(pdeq);
	pdeq->tail->data = pdeq->tail->prev->data;
	pdeq->tail->prev->data = temp;
	ft_putstr_fd(str, 1);
}

void	push(t_deque *a, t_deque *b, char *str, int *count)
{
	int	temp;

	(*count)++;
	if (dequeisempty(a))
		return ;
	temp = dqgetlast(a);
	dqremovelast(a);
	dqaddlast(b, temp);
	ft_putstr_fd(str, 1);
}

int	rotate(t_deque *deq, char *str, int	*count)
{
	int	temp;

	(*count)++;
	if (dequeisempty(deq) || deq_len(deq) == 1)
		return (1);
	temp = dqgetlast(deq);
	if (!dqaddfirst(deq, temp))
		return (0);
	dqremovelast(deq);
	ft_putstr_fd(str, 1);
	return (1);
}

int	reverse_rotate(t_deque *deq, char *str)
{
	int	temp;

	if (dequeisempty(deq) || deq->head == deq->tail)
		return (1);
	temp = dqgetfirst(deq);
	if (!dqaddlast(deq, temp))
		return (0);
	dqremovefirst(deq);
	ft_putstr_fd(str, 1);
	return (1);
}

int	size(t_deque *pdeq)
{
	int		count;
	t_node	*temp;

	count = 1;
	temp = pdeq->head;
	if (dequeisempty(pdeq))
		return (0);
	while (pdeq->head != pdeq->tail)
	{
		count++;
		pdeq->head = pdeq->head->next;
	}
	pdeq->head = temp;
	return (count);
}
