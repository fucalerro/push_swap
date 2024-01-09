/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:23:31 by lferro            #+#    #+#             */
/*   Updated: 2024/01/09 09:36:29 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *a, t_stack *b)
{
	t_cost	*cost;
	int		cheapest_index;


	if (a->size == 3)
		three_sort(a);
	else if (a->size == 5)
		five_sort(a, b);
	else
	{
		push(a, b, "pb");
		push(a, b, "pb");
		cost = malloc(sizeof(t_cost) * a->size);
		while (a->size > 0)
		{
			reset_cost(&cost, a);
			get_cost(a, b, &cost);
			cheapest_index = get_cheapest_index(a, &cost);
			make_move(a, b, cost, cheapest_index);
		}
		bring_max_top(b);
		while (b->size > 0)
			push(b, a, "pa");
		free(cost);
	}
}

int	get_cheapest_index(t_stack *a, t_cost **cost)
{
	int	cheapest;
	int	cheapest_index;
	int	i;

	i = -1;
	cheapest = INT_MAX;
	while (++i < a->size)
		if ((*cost)[i].total_cost <= cheapest)
		{
			cheapest = (*cost)[i].total_cost;
			cheapest_index = i;
		}
	return (cheapest_index);
}

void	make_move(t_stack *a, t_stack *b, t_cost *cost, int cheapest)
{
	t_cost temp_cost;



	temp_cost.ra = cost[cheapest].ra;
	temp_cost.rb = cost[cheapest].rb;
	temp_cost.rra = cost[cheapest].rra;
	temp_cost.rrb = cost[cheapest].rrb;
	temp_cost.rr = cost[cheapest].rr;
	temp_cost.rrr = cost[cheapest].rrr;

	while (temp_cost.ra > 0)
	{
		rotate(a, "ra");
		temp_cost.ra--;
	}
	while (temp_cost.rb > 0)
	{
		rotate(b, "rb");
		temp_cost.rb--;
	}
	while (temp_cost.rra > 0)
	{
		rotate(a, "rra");
		temp_cost.rra--;
	}
	while (temp_cost.rrb > 0)
	{
		rotate(b, "rrb");
		temp_cost.rrb--;
	}
	while (cost[cheapest].rr > 0)
	{
		rr(a, b);
		cost[cheapest].rr--;
	}
	while (cost[cheapest].rrr > 0)
	{
		rrr(a, b);
		cost[cheapest].rrr--;
	}
	push(a, b, "pb");
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

void	b_cheaper(t_stack *a, t_stack *b, int cost)
{
	while (cost > 0)
	{
		rotate(b, "rb");
		cost--;
	}
	push(a, b, "pb");
	bring_max_top(b);
}

int	get_index(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i] == value)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

void	bring_max_top(t_stack *stack)
{
	int	max;
	int	max_index;

	max = get_max(stack);

	max_index = get_index(stack, max);
	if (max_index < stack->size / 2)
	{
		while (stack->array[0] != max)
		{
			rotate(stack, "rb");
		}
	}
	else
	{
		while (stack->array[0] != max)
		{
			rotate(stack, "rrb");
		}
	}
}
