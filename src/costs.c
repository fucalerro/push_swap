/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:38:15 by lferro            #+#    #+#             */
/*   Updated: 2023/12/22 19:58:20 by lferro           ###   ########.fr       */
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

	printf("cooooooost %d\n", cost);
	return (cost);
}



void	get_cost(t_stack *a, t_stack *b, t_cost **cost)
{
	int	i;
	int	bi;
	int	bring_max_cost;

	i = 0;
	bi = b->size - 1;
	bring_max_cost = bring_max_top_cost(b);

	while (i < a->size)
	{
		if (a->array[i] > get_max(b) || a->array[i] < get_min(b))
		{
			//this has a bug somehow
			(*cost)[i].rrb = bring_max_cost;
			printf("bring max cost: %d for i = %d\n", bring_max_cost, i);
		}
		else
		{
			bi = 0;
			(*cost)[i].rb = 1;
			while ((a->array[i] > b->array[bi] || a->array[i] < b->array[bi + 1]) && bi < b->size - 1)
			{
				(*cost)[i].rb++;
				bi++;
			}
			if (a->array[i] > b->array[0] && a->array[i] < b->array[b->size - 1])
			{
				(*cost)[i].rb = 0;

			}

			// while (bi > 0)
			// {
			// 	if (bi == 1 && (a->array[i] < b->array[bi] && a->array[i] > b->array[b->size - 1]))
			// 	{
			// 		(*cost)[i].rrb++;
			// 		// bi--;
			// 	}
			// 	else if (a->array[i] < b->array[bi] && a->array[i] > b->array[bi - 1])
			// 	{
			// 		(*cost)[i].rrb++;
			// 	}
			// 	bi--;
			// }

		}
		(*cost)[i].ra = i;
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
		get_total_cost(cost, i);
		i++;
	}
}


int	get_min_nbr(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

void	get_total_cost(t_cost **cost, int i)
{
	(*cost)[i].total_cost = (*cost)[i].ra + (*cost)[i].rb + (*cost)[i].rra + (*cost)[i].rrb;
}

void	get_total_cost2(t_cost **cost, int i)
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

	(*cost)[i].total_cost = (*cost)[i].rr + (*cost)[i].rrr + (*cost)[i].ra + (*cost)[i].rb + (*cost)[i].rrb + (*cost)[i].rra;

	// if ((*cost)[i].ra > 0 && (*cost)[i].rb > 0)
	// {
	// 	(*cost)[i].rr = get_min_nbr((*cost)[i].ra, (*cost)[i].rb);
	// }
	// else if ((*cost)[i].rra > 0 && (*cost)[i].rrb > 0)
	// {
	// 	(*cost)[i].rrr = get_min_nbr((*cost)[i].rra, (*cost)[i].rrb);
	// }
	// if ((*cost)[i].ra > (*cost)[i].rb)
	// 	(*cost)[i].ra = (*cost)[i].ra - (*cost)[i].rb;
	// else
	// 	(*cost)[i].rb = (*cost)[i].rb - (*cost)[i].ra;
	// if ((*cost)[i].rra > (*cost)[i].rrb)
	// 	(*cost)[i].rra = (*cost)[i].rra - (*cost)[i].rrb;
	// else
	// 	(*cost)[i].rrb = (*cost)[i].rrb - (*cost)[i].rra;
	// printf("ra: %d    rb: %d    rra: %d    rrb: %d    rr: %d    rrr: %d\n", (*cost)[i].final_ra, (*cost)[i].final_rb, (*cost)[i].final_rra, (*cost)[i].final_rrb, (*cost)[i].final_rr, (*cost)[i].final_rrr);
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
		i++;
	}
}
