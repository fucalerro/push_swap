/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:54:49 by lferro            #+#    #+#             */
/*   Updated: 2023/12/11 18:20:50 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Print both stacks
 *
 * @param a
 * @param b
 */
void	print_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	printf("\nstart\n");
	while (i < a->size || i < b->size)
	{
		if (i >= a->size)
			printf("%d: stackA: --	stackB: %d\n", i + 1, b->array[i].num);
		else if (i >= b->size)
			printf("%d: stackA: %d	stackB: --\n", i + 1, a->array[i].num);
		else
			printf("%d: stackA: %d	stackB: %d\n", i + 1, a->array[i].num,
				b->array[i].num);
		i++;
	}
	printf("   a_len: %d	b_len: %d\n", a->size, b->size);
}

/**
 * @brief Check if the stack is sorted

 * @param stack The stack to check
 * @return int true if the stack is sorted, false otherwise
 */
int	is_sorted(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->size - 1)
		if (stack->array[i].num > stack->array[i + 1].num)
			return (false);
	return (true);
}

/**
 * @brief Get the index position of each value
 *
 * @param a stack to get indexes from
 */
void	get_index(t_stack *a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < a->size)
		a->array[i].index = 0;
	i = -1;
	j = -1;
	while (++i < a->size)
	{
		while (++j < a->size)
			if (a->array[i].num > a->array[j].num)
				a->array[i].index++;
		j = 0;
	}
}
