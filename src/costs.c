/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:38:15 by lferro            #+#    #+#             */
/*   Updated: 2023/12/22 17:02:24 by lferro           ###   ########.fr       */
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
			(*cost)[i].ra = i;
		}
		else
		{
			bi = b->size - 1;


			while (bi > 0 && a->array[i] > b->array[bi])
			{
				(*cost)[i].rrb++;
				bi--;
			}

			
			(*cost)[i].ra = i;
			if ((*cost)[i].rrb > b->size / 2)
			{
				(*cost)[i].rb = b->size - (*cost)[i].rrb;
				(*cost)[i].rrb = 0;
			}
		}
		if ((*cost)[i].ra > a->size / 2)
		{
			(*cost)[i].rra = a->size - (*cost)[i].ra;
			(*cost)[i].ra = 0;
		}
		get_total_cost(cost, i, bring_max_cost, b->size);
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

void	get_total_cost(t_cost **cost, int i, int bring_max_cost, int bsize)
{
	(*cost)[i].rb += bring_max_cost;

	printf("bring_max_cost::: %d\n", bring_max_cost);
	if ((*cost)[i].rb > bsize / 2)
	{
		(*cost)[i].rrb = bsize - (*cost)[i].rb;
		(*cost)[i].rb = 0;
	}


	(*cost)[i].total_cost = (*cost)[i].ra + (*cost)[i].rb + (*cost)[i].rra + (*cost)[i].rrb;
}

void	get_total_cost2(t_cost **cost, int i)
{
	(*cost)[i].final_rr = 0;
	(*cost)[i].final_rrr = 0;
	(*cost)[i].final_ra = 0;
	(*cost)[i].final_rb = 0;
	(*cost)[i].final_rra = 0;
	(*cost)[i].final_rrb = 0;

	if ((*cost)[i].ra > 0 && (*cost)[i].rb > 0)
	{
		(*cost)[i].final_rr = get_min_nbr((*cost)[i].ra, (*cost)[i].rb);
	}
	else if ((*cost)[i].rra > 0 && (*cost)[i].rrb > 0)
	{
		(*cost)[i].final_rrr = get_min_nbr((*cost)[i].rra, (*cost)[i].rrb);
	}

	if ((*cost)[i].ra > (*cost)[i].rb)
		(*cost)[i].final_ra = (*cost)[i].ra - (*cost)[i].rb;
	else
		(*cost)[i].final_rb = (*cost)[i].rb - (*cost)[i].ra;

	if ((*cost)[i].rra > (*cost)[i].rrb)
		(*cost)[i].final_rra = (*cost)[i].rra - (*cost)[i].rrb;
	else
		(*cost)[i].final_rrb = (*cost)[i].rrb - (*cost)[i].rra;


	(*cost)[i].total_cost = (*cost)[i].final_rr + (*cost)[i].final_rrr + (*cost)[i].final_ra + (*cost)[i].final_rb + (*cost)[i].final_rrb + (*cost)[i].final_rra;

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
		i++;
	}
}
