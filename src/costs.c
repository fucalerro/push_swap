/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:38:15 by lferro            #+#    #+#             */
/*   Updated: 2024/01/09 09:59:44 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_stack *a, t_stack *b, t_cost **cost)
{
	int	i;
	int	bring_max_cost;

	i = 0;
	while (i < a->size)
	{
		(*cost)[i].ra = i;
		if (a->array[i] > get_max(b) || a->array[i] < get_min(b))
		{
			bring_max_cost = bring_max_top_cost(b);
			(*cost)[i].rb = bring_max_cost;
		}
		else
			get_middle_cost(cost, a, b, i);
		optimize_rotate(cost, i, a, b);
		i++;
	}
}

void	get_middle_cost(t_cost **cost, t_stack *a, t_stack *b, int i)
{
	int	bi;
	int	bj;

	bi = b->size - 1;
	bj = 0;
	(*cost)[i].rb = 0;
	while ((*cost)[i].rb < b->size)
	{
		if (a->array[i] < b->array[bi] && a->array[i] > b->array[bj])
			break ;
		(*cost)[i].rb++;
		bi++;
		bj++;
		if (bj == b->size)
			bj = 0;
		if (bi == b->size)
			bi = 0;
	}
	get_total_cost(cost, i);
}

void	optimize_rotate(t_cost **cost, int i, t_stack *a, t_stack *b)
{
	if ((*cost)[i].rb > b->size / 2)
	{
		(*cost)[i].rrb = b->size - (*cost)[i].rb;
		(*cost)[i].rb = 0;
	}
	if ((*cost)[i].ra > a->size / 2)
	{
		(*cost)[i].rra = a->size - (*cost)[i].ra;
		(*cost)[i].ra = 0;
	}
}

void	get_total_cost(t_cost **cost, int i)
{
	(*cost)[i].rr = 0;
	(*cost)[i].rrr = 0;
	while ((*cost)[i].ra > 0 && (*cost)[i].rb > 0)
	{
		(*cost)[i].ra--;
		(*cost)[i].rb--;
		(*cost)[i].rr++;
	}
	while ((*cost)[i].rra > 0 && (*cost)[i].rrb > 0)
	{
		(*cost)[i].rra--;
		(*cost)[i].rrb--;
		(*cost)[i].rrr++;
	}
	(*cost)[i].total_cost = (*cost)[i].rr + (*cost)[i].rrr + (*cost)[i].ra
		+ (*cost)[i].rb + (*cost)[i].rrb + (*cost)[i].rra;
}

void	reset_cost(t_cost **cost, t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		(*cost)[i].ra = 0;
		(*cost)[i].rb = 0;
		(*cost)[i].rra = 0;
		(*cost)[i].rrb = 0;
		(*cost)[i].rr = 0;
		(*cost)[i].rrr = 0;
		(*cost)[i].total_cost = 0;
		i++;
	}
}
