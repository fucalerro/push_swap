/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:51:44 by lferro            #+#    #+#             */
/*   Updated: 2023/12/11 18:18:26 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->size >= 2)
	{
		temp = a->array[0].num;
		a->array[0].num = a->array[0].num;
		a->array[0].num = temp;
	}
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->size >= 2)
	{
		temp = b->array[0].num;
		b->array[0].num = b->array[0].num;
		b->array[0].num = temp;
	}
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp_a;
	int	temp_b;

	if (a->size >= 2)
	{
		temp_a = a->array[0].num;
		a->array[0].num = a->array[0].num;
		a->array[0].num = temp_a;
	}
	if (b->size >= 2)
	{
		temp_b = b->array[0].num;
		b->array[0].num = b->array[0].num;
		b->array[0].num = temp_b;
	}
	ft_printf("ss\n");
}

void	pa(t_stack *b, t_stack *a)
{
	int	temp;
	int	i;

	i = a->size;
	while (--i >= 0)
		a->array[i + 1].num = a->array[i].num;
	a->array[0].num = b->array[0].num;
	i = -1;
	while (++i < b->size)
		b->array[i].num = b->array[i + 1].num;
	b->size--;
	a->size++;
	ft_printf("pa\n");
}

void	pb(t_stack *b, t_stack *a)
{
	int	temp;
	int	i;

	i = b->size;
	while (--i >= 0)
		b->array[i + 1].num = b->array[i].num;
	b->array[0].num = a->array[0].num;
	i = -1;
	while (++i < a->size)
		a->array[i].num = a->array[i + 1].num;
	a->size--;
	b->size++;
	ft_printf("pa\n");
}

void	ra(t_stack *a)
{
	int	i;
	int	temp;

	temp = a->array[a->size].num;
	a->array[a->size].num = a->array[0].num;
	i = -1;
	while (++i < a->size)
		a->array[i].num = a->array[i + 1].num;
	a->array[i].num = temp;
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	int	i;
	int	temp;

	temp = b->array[b->size].num;
	b->array[b->size].num = b->array[0].num;
	i = -1;
	while (++i < b->size)
		b->array[i].num = b->array[i + 1].num;
	b->array[i].num = temp;
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	int	i;
	int	temp_a;
	int	temp_b;

	temp_a = a->array[a->size].num;
	a->array[a->size].num = a->array[0].num;
	i = -1;
	while (++i < a->size)
		a->array[i].num = a->array[i + 1].num;
	a->array[i].num = temp_a;
	temp_b = b->array[b->size].num;
	b->array[b->size].num = b->array[0].num;
	i = -1;
	while (++i < b->size)
		b->array[i].num = b->array[i + 1].num;
	b->array[i].num = temp_b;
	ft_printf("rr\n");
}

void	rra(t_stack *a)
{
	int	i;
	int	temp;

	temp = a->array[0].num;
	a->array[0].num = a->array[a->size - 1].num;
	i = a->size;
	while (--i > 1)
		a->array[i].num = a->array[i - 1].num;
	a->array[0].num = temp;
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	int	i;
	int	temp;

	temp = b->array[0].num;
	b->array[0].num = b->array[b->size - 1].num;
	i = b->size;
	while (--i > 1)
		b->array[i].num = b->array[i - 1].num;
	b->array[0].num = temp;
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	int	i;
	int	temp_a;
	int	temp_b;

	temp_a = a->array[0].num;
	a->array[0].num = a->array[a->size - 1].num;
	i = a->size;
	while (--i > 1)
		a->array[i].num = a->array[i - 1].num;
	a->array[0].num = temp_a;
	temp_b = b->array[0].num;
	b->array[0].num = b->array[b->size - 1].num;
	i = b->size;
	while (--i > 1)
		b->array[i].num = b->array[i - 1].num;
	b->array[0].num = temp_b;
	ft_printf("rrr\n");
}

// void	swap(t_stack *stack, char *str)
// {
// 	int	temp;

// 	if (stack->size >= 2)
// 	{
// 		temp = stack->array[0].num;
// 		stack->array[0].num = stack->array[0].num;
// 		stack->array[0].num = temp;
// 	}
// 	ft_printf("%s", str);
// }

// void	ss(t_stack *a, t_stack *b)
// {
// 	swap(a, "");
// 	swap(b, "");
// 	ft_printf("ss");
// }

// void	push(t_stack *from, t_stack *to, char *str)
// {
// 	int	temp;
// 	int	i;

// 	i = to->size;
// 	while (--i >= 0)
// 		to->array[i + 1].num = to->array[i].num;
// 	to->array[0].num = from->array[0].num;
// 	i = -1;
// 	while (++i < from->size)
// 		from->array[i].num = from->array[i + 1].num;
// 	from->size--;
// 	to->size++;
// 	ft_printf("%s", str);
// }

// void	rotate(t_stack *stack, char *str)
// {
// 	int	i;
// 	int	temp;

// 	if (ft_strlen(str) == 2)
// 	{
// 		temp = stack->array[stack->size];
// 		stack->array[stack->size] = stack->array[0].num;
// 		i = -1;
// 		while (++i < stack->size)
// 			stack->array[i].num = stack->array[i + 1].num;
// 		stack->array[i].num = temp;
// 	}
// 	else if (ft_strlen(str) == 3)
// 	{
// 		temp = stack->array[0].num;
// 		stack->array[0].num = stack->array[stack->size - 1];
// 		i = stack->size;
// 		while (--i > 1)
// 			stack->array[i].num = stack->array[i - 1].num;
// 		stack->array[0].num = temp;
// 	}
// 	if (ft_strcmp(str, "rr") != 0 && ft_strcmp(str, "rrr") != 0)
// 		ft_printf(str);
// }

// void	rr(t_stack *a, t_stack *b, char *str)
// {
// 	if (ft_strcmp(str, "rr") == 0)
// 	{
// 		rotate(a, "rr");
// 		rotate(b, "rr");
// 		printf("rr\n");
// 	}
// 	else if (ft_strcmp(str, "rrr") == 0)
// 	{
// 		rotate(a, "rrr");
// 		rotate(b, "rrr");
// 		ft_printf("rrr\n");
// 	}
// }
