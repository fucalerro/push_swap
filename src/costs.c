/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:38:15 by lferro            #+#    #+#             */
/*   Updated: 2024/01/06 12:57:18 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// return the number of rotation (not reverse) needed to bring the max
// number to the top of the stack
int bring_max_top_cost(t_stack *stack)
{
	int max;
	int cost;
	int i;

	max = get_max(stack);
	i = 0;
	while (stack->array[i] != max)
		i++;
	cost = stack->size - i;
	if (i < stack->size - i)
		cost = i;

	// printf("cooooooost %d\n", cost);
	return (cost);
}

void get_cost(t_stack *a, t_stack *b, t_cost **cost)
{
	int i;
	int bi;
	int bj;
	int bring_max_cost;

	i = 0;

	// reset_cost(cost, a);

	while (i < a->size)
	{
		(*cost)[i].ra = i;
		if (a->array[i] > get_max(b) || a->array[i] < get_min(b))
		{
			bring_max_cost = bring_max_top_cost(b);
			(*cost)[i].rb = bring_max_cost;
			// printf("bring max cost: %d for i = %d\n", bring_max_cost, i);
		}
		else
		{
			bi = b->size - 1;
			bj = 0;
			(*cost)[i].rb = 0;


			// while (a->array[i] > b->array[bi] || a->array[i] < b->array[bj])
			// {


			// 	bj++;
			// 	bi++;
			// 	if (bj == b->size)
			// 		bj = 0;
			// 	if (bi == b->size)
			// 		bi = 0;
			// }

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


		// printf("%d RA cost:	%d\n",i, (*cost)[i].ra);
		// printf("%d RB cost:	%d\n",i, (*cost)[i].rb);
		// printf("%d RRA cost:	%d\n",i, (*cost)[i].rra);
		// printf("%d RRB cost:	%d\n",i, (*cost)[i].rrb);
		// printf("%d RR cost:	%d\n",i, (*cost)[i].rr);
		// printf("%d RRR cost:	%d\n\n",i, (*cost)[i].rrr);
		// printf("%d Tot cost:	%d\n\n",i, (*cost)[i].total_cost);
		i++;
	}
}

int get_min_nbr(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

void get_total_cost(t_cost **cost, int i)
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
}

void reset_cost(t_cost **cost, t_stack *a)
{
	int i;

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
