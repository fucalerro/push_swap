/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:54:49 by lferro            #+#    #+#             */
/*   Updated: 2024/01/09 10:18:07 by lferro           ###   ########.fr       */
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
	printf("\n--------------- i --------------------- i\n");
	while (i < a->size || i < b->size)
	{
		if (i >= a->size)
			printf("%d: stackA:	-		stackB:	%d\n", i, b->array[i]);
		else if (i >= b->size)
			printf("%d: stackA:	%d		stackB:	-\n", i, a->array[i]);
		else
			printf("%d: stackA:	%d		stackB:	%d\n", i, a->array[i],
				b->array[i]);
		i++;
	}
	printf("   a_len: %d			b_len: %d\n", a->size, b->size);
	printf("END PRINT STACKS\n\n");
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
		if (stack->array[i] > stack->array[i + 1])
			return (false);
	return (true);
}

/**
 * @brief Get the index position of each value
 *
 * @param a stack to get indexes from
 */
void	change_to_index(t_stack *a)
{
	int	i;
	int	j;
	int	k;
	int	*temp;

	temp = malloc(sizeof(int) * a->size + 1);
	k = -1;
	while (++k < a->size)
		temp[k] = 0;
	i = -1;
	j = -1;
	while (++i < a->size)
	{
		while (++j < a->size)
			if (a->array[i] > a->array[j])
				temp[i]++;
		j = -1;
	}
	i = -1;
	while (++i < a->size)
		a->array[i] = temp[i];
	free(temp);
}

/**
 * @brief Get the max item from a stack
 *
 * @param stack
 * @return int
 */
int	get_max(t_stack *stack)
{
	int	max;
	int	i;

	i = 0;
	max = stack->array[i];
	while (i < stack->size - 1)
	{
		if (stack->array[i + 1] > max)
			max = stack->array[i + 1];
		i++;
	}
	return (max);
}

int	get_min(t_stack *stack)
{
	int	min;
	int	i;

	i = 0;
	min = stack->array[i];
	while (i < stack->size - 1)
	{
		if (stack->array[i + 1] < min)
			min = stack->array[i + 1];
		i++;
	}
	return (min);
}
