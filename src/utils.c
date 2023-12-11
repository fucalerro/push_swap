/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:54:49 by lferro            #+#    #+#             */
/*   Updated: 2023/12/11 17:11:55 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	printf("\nstart\n");
	while (i < a->size || i < b->size)
	{
		if (i >= a->size)
			printf("%d: stackA: --	stackB: %d\n", i + 1, b->array[i]);
		else if (i >= b->size)
			printf("%d: stackA: %d	stackB: --\n", i + 1, a->array[i]);
		else
			printf("%d: stackA: %d	stackB: %d\n", i + 1, a->array[i],
				b->array[i]);
		i++;
	}
	printf("   a_len: %d	b_len: %d\n", a->size, b->size);
}
