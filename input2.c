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

int	input_normal_case(int ac, char **av, t_deque *deq)
{
	int	i;

	i = 1;
	dequeinit(deq);
	while (i < ac)
	{
		if (check_error(av[i]))
		{	
			if (!dqaddfirst(deq, ft_atoi(av[i])))
			{
				dqfreeall(deq);
				ft_putstr_fd("Error", 1);
				return (0);
			}
		}
		else
		{
			ft_putstr_fd("Error", 1);
			dqfreeall(deq);
			return (0);
		}
		i++;
	}
	return (1);
}

int	input_ac_is_1(char **av, t_deque *deq)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(*av, "\t\n\v\f\r ");
	if (!split)
		return (0);
	while (split[i])
		i++;
	return (input_normal_case(i, split, deq));
}
