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

void	when_error(t_deque *a, t_deque *b)
{
	ft_putstr_fd("Error\n", 1);
	dqfreeall(a);
	dqfreeall(b);
	//system("leaks push_swap > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
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
	split = ft_split(av[1], "\t\n\v\f\r ");
	if (!split)
		return (0);
	while (split[i])
		i++;
	i = put_deq(i, split, deq);
	free(split);
	return (i);
}

int	put_deq(int ac, char **av, t_deque *deq)
{
	int	i;

	i = 0;
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

void	insert_arr(int i, int len, int *arr, t_node *temp)
{
	while (i < len)
	{
		arr[i++] = temp->data;
		temp = temp->prev;
	}
}
