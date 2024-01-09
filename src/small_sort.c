/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:32:05 by lferro            #+#    #+#             */
/*   Updated: 2024/01/09 09:36:19 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack *a)
{
	if (a->array[0] > a->array[1])
		swap(a, "sa");
	if (a->array[1] > a->array[2])
		rotate(a, "rra");
	if (a->array[0] > a->array[1])
		swap(a, "sa");
}

void	five_sort_low(t_stack *a, t_stack *b, int small_index)
{
	while (small_index > 0)
	{
		rotate(a, "ra");
		small_index--;
	}
	push(a, b, "pb");
}

void	five_sort_high(t_stack *a, t_stack *b, int small_index)
{
	while (small_index < a->size)
	{
		rotate(a, "rra");
		small_index++;
	}
	push(a, b, "pb");
}

void	five_sort(t_stack *a, t_stack *b)
{
	int small_index;
	int	two;

	two = 2;
	while (two > 0)
	{
		small_index = get_index(a, get_min(a));
		if (small_index <= a->size / 2)
			five_sort_low(a, b, small_index);
		else if (small_index > a->size / 2)
			five_sort_high(a, b, small_index);
		two--;
	}
	three_sort(a);
	push(b, a, "pa");
	push(b, a, "pa");
}
