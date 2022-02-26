/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:20:53 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/08 12:29:11 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_all_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '-')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	isin_dec(char *str)
{
	if (ft_strncmp(str, "1", 20) == 0 || ft_strncmp(str, "-1", 20) == 0)
		return (1);
	if (ft_atoi(str) == 0 || ft_atoi(str) == -1)
		return (0);
	return (1);
}

int	check_error(char *str)
{
	if (!is_all_digit(str))
		return (0);
	if (!isin_dec(str))
		return (0);
	return (1);
}

int	input(int ac, char **av, t_deque *deq)
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

int	is_all_diff(t_deque *deq)
{
	int	*map;
	int	index;
	int	min;
	int	len;

	len = deq_len(deq);
	map = (int *)malloc(sizeof(int) * (len + 1));
	if (!map)
		return (0);
	index = 1;
	min = find_min_max(deq, 0, len);
	while (index < len + 1)
		map[index] = min - 1;
	if (!travel_bintree(deq, map, min - 1))
		return (0);
	return (1);
}
