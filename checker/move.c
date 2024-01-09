/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:51:44 by lferro            #+#    #+#             */
/*   Updated: 2024/01/09 14:57:04 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_stack *stack, char *str)
{
	int	temp;

	if (stack->size >= 2)
	{
		temp = stack->array[0];
		stack->array[0] = stack->array[1];
		stack->array[1] = temp;
	}
	str = NULL;
}

void	push(t_stack *from, t_stack *to, char *str)
{
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
	str = NULL;
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
	if (str[0] != 'x')
	{
		str = NULL;
	}
}

void	rr(t_stack *a, t_stack *b)
{
	int	i;
	int	temp;

	temp = a->array[a->size];
	a->array[a->size] = a->array[0];
	i = -1;
	while (++i < a->size)
		a->array[i] = a->array[i + 1];
	a->array[i] = temp;
	temp = b->array[b->size];
	b->array[b->size] = b->array[0];
	i = -1;
	while (++i < b->size)
		b->array[i] = b->array[i + 1];
	b->array[i] = temp;
}

void	rrr(t_stack *a, t_stack *b)
{
	int	i;
	int	temp;

	temp = a->array[0];
	a->array[0] = a->array[a->size - 1];
	i = a->size;
	while (--i > 1)
		a->array[i] = a->array[i - 1];
	a->array[1] = temp;
	temp = b->array[0];
	b->array[0] = b->array[b->size - 1];
	i = b->size;
	while (--i > 1)
		b->array[i] = b->array[i - 1];
	b->array[1] = temp;
}
