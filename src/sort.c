/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:23:31 by lferro            #+#    #+#             */
/*   Updated: 2023/12/12 11:44:03 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sort 3 numbers
 *
 * @param a Stack with 3 numbers to sort numbers from
 */
void	sort_small(t_stack *a)
{
	if (a->array[0].num > a->array[1].num)
		sa(a);
	if (a->array[1].num > a->array[2].num)
		rra(a);
	if (a->array[0].num > a->array[1].num)
		sa(a);
}


void	sort(t_stack *a, t_stack *b)
{
	int	i;
	int	size;

	size = a->size - 1;
	i = 0;
	while (i <= a->size)
	{
		print_stacks(a, b);
		printf("number: %d	index: %d	size: %d\n", a->array[0].num , a->array[0].index, size);
		if (a->array[0].index == size)
		{
			pb(a, b);
			ra(a);
			size--;
		}
		else
		{
			ra(a);
		}
		i++;
	}
	while (b->size != 0)
	{
		pa(b, a);
	}
}



// void	radix_sort(t_stack *a, t_stack *b)
// {
// 	int	i;
// 	int	test;

// 	i = 0;
// 	while (i <= a->size)
// 	{
// 		// if ((a->array[0].index & 1) == 0)
// 		printf("i: %d	bit: %d\n", a->array[i].index, a->array[i].index & 1);
// 			// pb(a, b);
// 		// ra(a);
// 		i++;

// 	}
// 	printf("asize: %d\n", a->size);
// 	// if (a->array[i].index >> 1 == 0)

// }
