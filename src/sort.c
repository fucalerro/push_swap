/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:23:31 by lferro            #+#    #+#             */
/*   Updated: 2023/12/20 20:55:57 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sort 3 numbers
 *
 * @param a Stack with 3 numbers to sort numbers from
 */
// void	sort_small(t_s`tack *a)
// {
// 	if (a->array[0] > a->array[1]);
// 		// sa(a);
// 	if (a->array[1] > a->array[2]);
// 		// rra(a);
// 	if (a->array[0] > a->array[1]);
// 		// sa(a);
// }

int	which_rotate(t_stack *a, int index)
{
	int	pos;

	pos = 0;
	while (a->array[pos] != index)
		pos++;
	if (pos < (a->size / 2))
		rotate(a, "ra");
	else
		rotate(a, "rra");
	return (0);
}

// void	init_cost(t_cost **cost, int i)
// {
// 	(*cost)[i].ra = 0;
// 	(*cost)[i].rb = 0;
// 	(*cost)[i].rra = 0;
// 	(*cost)[i].rrb = 0;
// }

void	get_cost(t_stack *a, t_stack *b, t_cost **cost)
{
	int	i;
	int	bi;

	i = 0;
	bi = b->size - 1;

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
		(*cost)[i].final_ra = (*cost)[i].rra - (*cost)[i].rrb;
	else
		(*cost)[i].final_rrb = (*cost)[i].rrb - (*cost)[i].rra;

	(*cost)[i].total_cost = (*cost)[i].final_rr + (*cost)[i].final_rrr + (*cost)[i].final_ra + (*cost)[i].final_rb + (*cost)[i].final_rrb + (*cost)[i].final_rra;

	// printf("ra: %d rb: %d rra: %d rrb: %d rr: %d rrr: %d\n", ra, rb, rra, rrb, rr, rrr);
}


void	reset_cost(t_cost **cost, t_stack *a)
{
	int i = 0;
	while (i < a->size)
	{
		(*cost)[i].ra = 0;
		(*cost)[i].rb = 0;
		(*cost)[i].rra = 0;
		(*cost)[i].rrb = 0;

		i++;
	}
}

void	sort(t_stack *a, t_stack *b)
{
	t_cost *cost;


	cost = malloc(sizeof(t_cost) * a->size);

	// push(a, b, "pbbb");
	// push(a, b, "pbbb");
	// push(a, b, "pbbb");
	// push(a, b, "pbbb");
	// push(a, b, "pbbb");
	// push(a, b, "pbbb");
	// push(a, b, "pbbb");
	// push(a, b, "pbbb");
	// push(a, b, "pbbb");
	// push(a, b, "pbbb");

	PRINTSTACK;

	int	cheapest;

	int i = 0;
	while (a->size > 0)
	{
		bring_max_top(b);
		if (a->array[0] > get_max(b))
		{
			push(a, b, "pb");
			PRINTSTACK;
		}
		else if (a->array[0] < get_min(b))
		{
			push(a, b, "pb");
			rotate(b, "rb");
			PRINTSTACK;
		}
		else
		{
			get_cost(a, b, &cost);

			cheapest = get_index_min_value(&cost, a);

			make_move(a, b, cost);

			reset_cost(&cost, a);


			// for (int i = 0; i < a->size; i++)
			// {
			// 	printf("cost index: %d	ra cost: %d\n", i, cost[i].ra);
			// 	printf("cost index: %d	rb cost: %d\n", i, cost[i].rb);
			// 	printf("cost index: %d	rra cost: %d\n", i, cost[i].rra);
			// 	printf("cost index: %d	rrb cost: %d\n", i, cost[i].rrb);
			// 	printf("cost index: %d	total cost: %d\n\n", i, cost[i].total_cost);
			// }
		}
		i++;
		// PRINTSTACK;
	}
		bring_max_top(b);

		while (b->size > 0)
			push(b, a, "pa");
		PRINTSTACK;

}

void	make_move(t_stack *a, t_stack *b, t_cost *cost)
{
	while (cost->final_ra != 0)
	{
		rotate(a, "ra");
		cost->final_ra--;
	}
	while (cost->final_rb != 0)
	{
		rotate(b, "rb");
		cost->final_rb--;
	}
	while (cost->final_rra != 0)
	{
		rotate(a, "rra");
		cost->final_rra--;
	}
	while (cost->final_rrb != 0)
	{
		rotate(b, "rrb");
		cost->final_rrb--;
	}
	while (cost->final_rr != 0)
	{
		rr(a, b, "rr");
		cost->final_rr--;
	}
	while (cost->final_rrr != 0)
	{
		rr(a, b, "rrr");
		cost->final_rrr--;
	}
	PRINTSTACK;
	push(a, b, "PB");
	PRINTSTACK;
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



void	turk_sort(t_stack *a, t_stack *b)
{
	push(a, b, "pb");
	push(a, b, "pb");

	// bring_max_top(b);
	// PRINTSTACK;
	int	min_sum;

	min_sum = INT_MAX;
	int sum;
	int	ia;
	int	ib;
	ia = 0;
	ib = 0;
	int mia;
	int mib;
	int i = 0;
	int ib_2;

	while (a->size > 0)
	{
		while (ia < a->size)
		{
			while (ib < b->size)
			{
				ib_2 = ib - 1;
				if (ib == 0)
					ib_2 = b->size - 1;
				if (a->array[ia] > b->array[ib] && a->array[ia] < b->array[ib_2])
				{
					sum = ia + ib;
					if (sum < min_sum)
					{
						min_sum = sum;
						mia = ia;
						mib = ib;
						printf("mia: %d\nmib: %d\n", mia, mib);
					}
				}
				ib++;
			}
			ib = 0;
			ia++;
		}
		while (mia > 0 || mib > 0)
		{
			if (mia > 0 && mib > 0)
			{
				rr(a, b, "rr");
				// PRINTSTACK;
				mia--;
				mib--;
			}
			else if (mia > 0)
			{
				rotate(a, "ra");
				// PRINTSTACK;
				mia--;
			}
			else if (mib > 0)
			{
				rotate(b, "rb");
				// PRINTSTACK;
				mib--;
			}
		}
		push(a, b, "pb");
		// PRINTSTACK;
		// bring_max_top(b);
		// PRINTSTACK;
		ia = 0;
		ib = 0;
		mia = 0;
		mib = 0;
		min_sum = INT_MAX;
	}
	while (b->size != 0)
	{
		push(b, a, "pa");
	}
	print_stacks(a, b);
}




// int	get_cost(t_stack *a, t_stack *b, int index)
// {
// 	int	ra_cost;
// 	int	rb_cost;
// 	int	b_i;
// 	int	b_j;
// 	ra_cost = 0;
// 	rb_cost = 0;
// 	b_i = 0;
// 	b_j = 0;
// 	while (index < a->size)
// 	{
// 		while (!(a->array[index] <= b->array[b_i] && a->array[index] <= b->array[b_i + 1]))
// 		{
// 			b_i++;
// 			rb_cost++;
// 		}
// 		ra_cost++;
// 	}
// 	return (rb_cost + ra_cost);
// }

// void	turk_sort(t_stack *a, t_stack *b)
// {
// 	int	i;
// 	int *costs;
// 	i = 0;
// 	costs = malloc(sizeof(int) *a->size);
// 	while (i < a->size)
// 	{
// 		costs[i] = get_cost(a, b, i);
// 		i++;
// 	}
// }

// void	turk_sort(t_stack *a, t_stack *b)
// {
// 	push(a, b, "pb");
// 	push(a, b, "pb");
// 	// // PRINTSTACK;
// 	if (b->array[0] < b->array[1])
// 		swap(b, "sb");
// 	// // PRINTSTACK;
// 	int	a_i;
// 	int	b_i;
// 	int	b_cost;
// 	int	a_cost;
// 	int	b_max;
// 	b_cost = 0;
// 	a_cost = 0;
// 	b_i = 0;
// 	a_i = 0;
// 	while (a->size > 0)
// 	{
// 		while (b_i < b->size)
// 		{
// 			if (a->array[0] > b->array[b_i])
// 			{
// 				break ;
// 			}
// 			else
// 			{
// 				b_cost++;
// 			}
// 			b_i++;
// 		}
// 		while (a_i <= a->size)
// 		{
// 			if (a->array[a_i] > b->array[0] && a->array[a_i] < b->array[b->size - 1])
// 			{
// 				break ;
// 			}
// 			else
// 			{
// 				a_cost++;
// 			}
// 			a_i++;
// 		}
// 		printf("acost: %d	bcost: %d\n", a_cost, b_cost);
// 		int pivot = 0;
// 		if (a_cost <= b_cost)
// 		{
// 			while (1 && pivot == 0)
// 			{
// 				if (get_max(a) < get_max(b))
// 				{
// 					b_cheaper(a, b, b_cost);
// 					int pivot = 1;
// 				}
// 				if (pivot == 0 && a->array[a_i] > b->array[0] && a->array[a_i] < b->array[b->size - 1])
// 				{
// 					push(a, b, "pb");
// 					break ;
// 				}
// 				else if (pivot == 0)
// 					rotate(a, "ra");
// 			}
// 			bring_max_top(b);
// 			// PRINTSTACK;
// 		}
// 		else if (a_cost > b_cost)
// 		{
// 			b_cheaper(a, b, b_cost);
// 		}
// 		a_cost = 0;
// 		b_cost = 0;
// 		a_i = 0;
// 		b_i = 0;
// 	}
// 	// PRINTSTACK;
// }

void	b_cheaper(t_stack *a, t_stack *b, int cost)
{
	while (cost > 0)
	{
		rotate(b, "rb");
		// PRINTSTACK;
		cost--;
	}
	// PRINTSTACK;
	// printf("push B when b_cost\n");
	push(a, b, "pb");
	bring_max_top(b);
	// // PRINTSTACK;
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
			rotate(stack, "RB");
		}
	}
	else
	{
		while (stack->array[0] != max)
		{
			rotate(stack, "RRB");
		}
	}
}


// void	sort(t_stack *a, t_stack *b)
// {
// 	int	i;
// 	// int	j;
// 	int	size;
// 	size = a->size;
// 	i = 0;
// 	while (is_sorted(a) == false)
// 	{
// 		// printf("\nasize: %d\n", a->size);
// 		// print_stacks(a, b);
// 		if (a->array[0] == i)
// 		{
// 			push(a, b, "pb");
// 			i++;
// 		}
// 		else if (a->array[1] == i && a->array[0] == i + 1)
// 		{
// 			swap(a, "sa");
// 			push(a, b, "pb");
// 			i++;
// 		}
// 		else
// 		{
// 			which_rotate(a, i);
// 			// rotate(a, "ra");
// 		}
// 	}
// 	while (b->size != 0)
// 	{
// 		push(b, a, "pa");
// 		// printf("yoAIPFUNWOEIFUBWEOUIF\n");
// 	}
// 	// print_stacks(a, b);
// }

// void	radix_sort(t_stack *a, t_stack *b)
// {
// 	int	i;
// 	int	test;

// 	i = 0;
// 	while (i <= a->size)
// 	{
// 		// if ((a->array[0] & 1) == 0)
// 		printf("i: %d	bit: %d\n", a->array[i], a->array[i] & 1);
// 			// pb(a, b);
// 		// ra(a);
// 		i++;

// 	}
// 	printf("asize: %d\n", a->size);
// 	// if (a->array[i] >> 1 == 0)

// }
