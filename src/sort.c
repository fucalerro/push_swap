/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:23:31 by lferro            #+#    #+#             */
/*   Updated: 2023/12/22 19:40:15 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *a, t_stack *b)
{
	t_cost *cost;
	int	cheapest_index;
	int i;

	i = 0;
	cost = malloc(sizeof(t_cost) * a->size);

	while (a->size > 0)
	{
		// // bring_max_top(b);
		// if (a->array[0] > get_max(b))
		// {
		// 	push(a, b, "pb");
		// 	PRINTSTACK;
		// }
		// else if (a->array[0] < get_min(b))
		// {
		// 	push(a, b, "pb");
		// 	rotate(b, "rb");
		// 	PRINTSTACK;
		// }
		// else
		// {
			get_cost(a, b, &cost);
			cheapest_index = get_cheapest_index(a, &cost);
			make_move(a, b, cost, cheapest_index);
			// bring_max_top(b);
			// printf("cheapest = %d\n", cheapest);

			for (int i = 0; i < a->size; i++)
			{
				printf("cost index: %d	ra cost: %d\n", i, cost[i].ra);
				printf("cost index: %d	rb cost: %d\n", i, cost[i].rb);
				printf("cost index: %d	rra cost: %d\n", i, cost[i].rra);
				printf("cost index: %d	rrb cost: %d\n\n", i, cost[i].rrb);
			// 	printf("cost index: %d	rr cost: %d\n", i, cost[i].rr);
			// 	printf("cost index: %d	rrr cost: %d\n", i, cost[i].rrr);
			// 	printf("cost index: %d	total cost: %d\n\n", i, cost[i].total_cost);
			}
			reset_cost(&cost, a);
		// }
		i++;
		PRINTSTACK;
	}
	bring_max_top(b);

		while (b->size > 0)
			push(b, a, "pa");
		PRINTSTACK;


}

int	get_cheapest_index(t_stack *a, t_cost **cost)
{
	int	cheapest;
	int	cheapest_index;
	int	i;

	i = -1;
	cheapest = INT_MAX;
	while (++i < a->size)
		if ((*cost)[i].total_cost < cheapest)
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
	// temp_cost.ra = cost[cheapest].rr;
	// temp_cost.ra = cost[cheapest].rrr;


	// if (temp_cost.ra < 0)
	// 	temp_cost.ra = 0;
	// if (temp_cost.rb < 0)
	// 	temp_cost.rb = 0;
	// if (temp_cost.rra < 0)
	// 	temp_cost.rra = 0;
	// if (temp_cost.rrb < 0)
	// 	temp_cost.rrb = 0;


	// int bite = temp_cost.rb;

	while (temp_cost.ra > 0)
	{
		rotate(a, "ra");
		temp_cost.ra--;
	}
	while (temp_cost.rb > 0)
	{
		// printf("bite %d\n", bite);
		// printf("bite 2 %d\n", temp_cost.rb);
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
	// while (cost[cheapest].rr != 0)
	// {
	// 	rr(a, b, "rr");
	// 	cost[cheapest].rr--;
	// }
	// while (cost[cheapest].rrr != 0)
	// {
	// 	rr(a, b, "rrr");
	// 	cost[cheapest].rrr--;
	// }
	// PRINTSTACK;
	push(a, b, "pb");
	// PRINTSTACK;
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



// {
// 	push(a, b, "pb");
// 	push(a, b, "pb");
// 	// bring_max_top(b);
// 	// PRINTSTACK;
// 	int	min_sum;
// 	min_sum = INT_MAX;
// 	int sum;
// 	int	ia;
// 	int	ib;
// 	ia = 0;
// 	ib = 0;
// 	int mia;
// 	int mib;
// 	int i = 0;
// 	int ib_2;
// 	while (a->size > 0)
// 	{
// 		while (ia < a->size)
// 		{
// 			while (ib < b->size)
// 			{
// 				ib_2 = ib - 1;
// 				if (ib == 0)
// 					ib_2 = b->size - 1;
// 				if (a->array[ia] > b->array[ib] && a->array[ia] < b->array[ib_2])
// 				{
// 					sum = ia + ib;
// 					if (sum < min_sum)
// 					{
// 						min_sum = sum;
// 						mia = ia;
// 						mib = ib;
// 						printf("mia: %d\nmib: %d\n", mia, mib);
// 					}
// 				}
// 				ib++;
// 			}
// 			ib = 0;
// 			ia++;
// 		}
// 		while (mia > 0 || mib > 0)
// 		{
// 			if (mia > 0 && mib > 0)
// 			{
// 				rr(a, b, "rr");
// 				// PRINTSTACK;
// 				mia--;
// 				mib--;
// 			}
// 			else if (mia > 0)
// 			{
// 				rotate(a, "ra");
// 				// PRINTSTACK;
// 				mia--;
// 			}
// 			else if (mib > 0)
// 			{
// 				rotate(b, "rb");
// 				// PRINTSTACK;
// 				mib--;
// 			}
// 		}
// 		push(a, b, "pb");
// 		// PRINTSTACK;
// 		// bring_max_top(b);
// 		// PRINTSTACK;
// 		ia = 0;
// 		ib = 0;
// 		mia = 0;
// 		mib = 0;
// 		min_sum = INT_MAX;
// 	}
// 	while (b->size != 0)
// 	{
// 		push(b, a, "pa");
// 	}
// 	print_stacks(a, b);
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

// void	sort_small(t_s`tack *a)
// {
// 	if (a->array[0] > a->array[1]);
// 		// sa(a);
// 	if (a->array[1] > a->array[2]);
// 		// rra(a);
// 	if (a->array[0] > a->array[1]);
// 		// sa(a);
// }

// int	which_rotate(t_stack *a, int index)
// {
// 	int	pos;
// 	pos = 0;
// 	while (a->array[pos] != index)
// 		pos++;
// 	if (pos < (a->size / 2))
// 		rotate(a, "ra");
// 	else
// 		rotate(a, "rra");
// 	return (0);
// }

// void	init_cost(t_cost **cost, int i)
// {
// 	(*cost)[i].ra = 0;
// 	(*cost)[i].rb = 0;
// 	(*cost)[i].rra = 0;
// 	(*cost)[i].rrb = 0;
// }

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

// void	turk_sort(t_stack *a, t_stack *b)
