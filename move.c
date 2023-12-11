/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:51:44 by lferro            #+#    #+#             */
/*   Updated: 2023/12/06 16:20:54 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char *str)
{
	int	temp;

	if (stack->size >= 2)
	{
		temp = stack->array[0];
		stack->array[0] = stack->array[1];
		stack->array[1] = temp;
	}
	ft_printf("%s", str);
}

void	push(t_stack *from, t_stack *to, char *str)
{
	int	temp;
	int	i;

	i = to->size;
	while (--i >= 0)
		to->array[i + 1] = to->array[i];
	to->array[0] = from->array[0];
	i = -1;
	while (++i < from->size)
		from->array[i] = from->array[i + 1];
	from->size--;
	to->size++;
	ft_printf("%s", str);
}

void	rotate(t_stack *stack, char *str)
{
	int	i;
	int	temp;

	if (ft_strlen(str) == 2)
	{
		temp = stack->array[stack->size];
		stack->array[stack->size] = stack->array[0];
		i = -1;
		while (++i < stack->size)
			stack->array[i] = stack->array[i + 1];
		stack->array[i] = temp;
	}
	else if (ft_strlen(str) == 3)
	{
		temp = stack->array[0];
		stack->array[0] = stack->array[stack->size - 1];
		i = stack->size;
		while (--i > 1)
			stack->array[i] = stack->array[i - 1];
		stack->array[1] = temp;
	}
	if (ft_strcmp(str, "rr") != 0 && ft_strcmp(str, "rrr") != 0)
		ft_printf(str);
}

void	rr(t_stack *a, t_stack *b, char *str)
{
	if (ft_strcmp(str, "rr") == 0)
	{
		rotate(a, "rr");
		rotate(b, "rr");
		printf("rr\n");
	}
	else if (ft_strcmp(str, "rrr") == 0)
	{
		rotate(a, "rrr");
		rotate(b, "rrr");
		ft_printf("rrr\n");
	}
}
