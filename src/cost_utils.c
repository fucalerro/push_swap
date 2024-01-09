/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:36:48 by lferro            #+#    #+#             */
/*   Updated: 2024/01/09 15:04:15 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// return the number of rotation (not reverse) needed to bring the max
// number to the top of the stack
int	bring_max_top_cost(t_stack *stack)
{
	int	max;
	int	cost;
	int	i;

	max = get_max(stack);
	i = 0;
	while (stack->array[i] != max)
		i++;
	cost = stack->size - i;
	if (i < stack->size - i)
		cost = i;
	return (cost);
}

int	get_min_nbr(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	get_cheapest_index(t_stack *a, t_cost **cost)
{
	int	cheapest;
	int	cheapest_index;
	int	i;

	i = -1;
	cheapest = INT_MAX;
	while (++i < a->size)
	{
		if ((*cost)[i].total_cost <= cheapest)
		{
			cheapest = (*cost)[i].total_cost;
			cheapest_index = i;
		}
	}
	return (cheapest_index);
}

int	get_index_min_value(t_cost **cost, t_stack *a)
{
	int	i;
	int	min;

	min = INT_MAX;
	i = -1;
	while (++i < a->size)
	{
		if ((*cost)[i].total_cost < min)
			min = (*cost)[i].total_cost;
	}
	return (i);
}
