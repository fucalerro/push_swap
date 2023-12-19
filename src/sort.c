/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:23:31 by lferro            #+#    #+#             */
/*   Updated: 2023/12/19 16:35:52 by lferro           ###   ########.fr       */
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


int	get_cost(int a_value, t_stack *b, int a_index)
{
	t_cost	cost;

	int	bi;
	int	bi2;
	bi = 0;

	while (bi < b->size)
	{
		bi2 = bi2 - 1;
		if (bi == 0)
			bi2 == b->size - 1;
		if (a_value > b->array[bi] && a_value < b->array[bi2])


	}



	cost = a_index + b_index;
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

// }
