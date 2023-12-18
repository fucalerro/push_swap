/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:23:31 by lferro            #+#    #+#             */
/*   Updated: 2023/12/18 11:40:01 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sort 3 numbers
 *
 * @param a Stack with 3 numbers to sort numbers from
 */
// void	sort_small(t_stack *a)
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

void	sort(t_stack *a, t_stack *b)
{
	int	i;
	// int	j;

	int	size;
	size = a->size;

	i = 0;
	while (is_sorted(a) == false)
	{
		// printf("\nasize: %d\n", a->size);
		// print_stacks(a, b);
		if (a->array[0] == i)
		{
			push(a, b, "pb");
			i++;
		}
		else if (a->array[1] == i && a->array[0] == i + 1)
		{
			swap(a, "sa");
			push(a, b, "pb");
			i++;
		}

		else
		{
			which_rotate(a, i);
			// rotate(a, "ra");
		}
	}
	while (b->size != 0)
	{
		push(b, a, "pa");
		// printf("yoAIPFUNWOEIFUBWEOUIF\n");
	}
	// print_stacks(a, b);
}



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
