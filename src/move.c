/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:51:44 by lferro            #+#    #+#             */
/*   Updated: 2023/12/20 20:49:05 by lferro           ###   ########.fr       */
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
	ft_printf("%s\n", str);
}

void	push(t_stack *from, t_stack *to, char *str)
{
	int	temp;
	int		i;

	i = to->size;
	while (--i >= 0)
		to->array[i + 1] = to->array[i];
	to->array[0] = from->array[0];
	i = -1;
	while (++i < from->size)
		from->array[i] = from->array[i + 1];
	from->size--;
	to->size++;
	ft_printf("%s\n", str);
}

void	rotate(t_stack *stack, char *str)
{
	int		i;
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
		ft_printf("%s\n", str);
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






// void	sa(t_stack *a)
// {
// 	int	temp;

// 	if (a->size >= 2)
// 	{
// 		temp = a->array[0].index;
// 		a->array[0].index = a->array[1].index;
// 		a->array[1].index = temp;
// 	}
// 	ft_printf("sa\n");
// }

// void	sb(t_stack *b)
// {
// 	int	temp;

// 	if (b->size >= 2)
// 	{
// 		temp = b->array[0].index;
// 		b->array[0].index = b->array[1].index;
// 		b->array[1].index = temp;
// 	}
// 	ft_printf("sb\n");
// }

// void	ss(t_stack *a, t_stack *b)
// {
// 	int	temp_a;
// 	int	temp_b;

// 	if (a->size >= 2)
// 	{
// 		temp_a = a->array[0].index;
// 		a->array[0].index = a->array[1].index;
// 		a->array[1].index = temp_a;
// 	}
// 	if (b->size >= 2)
// 	{
// 		temp_b = b->array[0].index;
// 		b->array[0].index = b->array[1].index;
// 		b->array[1].index = temp_b;
// 	}
// 	ft_printf("ss\n");
// }

// void	pa(t_stack *b, t_stack *a)
// {
// 	int	temp;
// 	int	i;

// 	i = a->size;
// 	while (--i >= 0)
// 		a->array[i + 1] = a->array[i];
// 	a->array[0] = b->array[0];
// 	i = -1;
// 	while (++i < b->size)
// 		b->array[i] = b->array[i + 1];
// 	b->size--;
// 	a->size++;
// 	ft_printf("pa\n");
// }

// void	pb(t_stack *a, t_stack *b)
// {
// 	int	temp;
// 	int	i;

// 	i = b->size;
// 	while (--i >= 0)
// 		b->array[i + 1] = b->array[i];
// 	b->array[0] = a->array[0];
// 	i = -1;
// 	while (++i < a->size)
// 		a->array[i] = a->array[i + 1];
// 	a->size--;
// 	b->size++;
// 	ft_printf("pb\n");
// }


// void	ra(t_stack *a)
// {
// 	int	i;
// 	int	temp;

// 	temp = a->array[a->size].index;
// 	a->array[a->size].index = a->array[0].index;
// 	i = -1;
// 	while (++i < a->size)
// 		a->array[i].index = a->array[i + 1].index;
// 	a->array[i].index = temp;
// 	ft_printf("ra\n");
// }

// void	rb(t_stack *b)
// {
// 	int	i;
// 	int	temp;

// 	temp = b->array[b->size].index;
// 	b->array[b->size].index = b->array[0].index;
// 	i = -1;
// 	while (++i < b->size)
// 		b->array[i].index = b->array[i + 1].index;
// 	b->array[i].index = temp;
// 	ft_printf("rb\n");
// }

// void	rr(t_stack *a, t_stack *b)
// {
// 	int	i;
// 	int	temp_a;
// 	int	temp_b;

// 	temp_a = a->array[a->size].index;
// 	a->array[a->size].index = a->array[0].index;
// 	i = -1;
// 	while (++i < a->size)
// 		a->array[i].index = a->array[i + 1].index;
// 	a->array[i].index = temp_a;
// 	temp_b = b->array[b->size].index;
// 	b->array[b->size].index = b->array[0].index;
// 	i = -1;
// 	while (++i < b->size)
// 		b->array[i].index = b->array[i + 1].index;
// 	b->array[i].index = temp_b;
// 	ft_printf("rr\n");
// }

// void	rra(t_stack *a)
// {
// 	int	i;
// 	int	temp;

// 	temp = a->array[0].index;
// 	a->array[0].index = a->array[a->size - 1].index;
// 	i = a->size;
// 	while (--i > 1)
// 		a->array[i].index = a->array[i - 1].index;
// 	a->array[0].index = temp;
// 	ft_printf("rra\n");
// }

// void	rrb(t_stack *b)
// {
// 	int	i;
// 	int	temp;

// 	temp = b->array[0].index;
// 	b->array[0].index = b->array[b->size - 1].index;
// 	i = b->size;
// 	while (--i > 1)
// 		b->array[i].index = b->array[i - 1].index;
// 	b->array[0].index = temp;
// 	ft_printf("rrb\n");
// }

// void	rrr(t_stack *a, t_stack *b)
// {
// 	int	i;
// 	int	temp_a;
// 	int	temp_b;

// 	temp_a = a->array[0].index;
// 	a->array[0].index = a->array[a->size - 1].index;
// 	i = a->size;
// 	while (--i > 1)
// 		a->array[i].index = a->array[i - 1].index;
// 	a->array[0].index = temp_a;
// 	temp_b = b->array[0].index;
// 	b->array[0].index = b->array[b->size - 1].index;
// 	i = b->size;
// 	while (--i > 1)
// 		b->array[i].index = b->array[i - 1].index;
// 	b->array[0].index = temp_b;
// 	ft_printf("rrr\n");
// }

// void	swap(t_stack *stack, char *str)
// {
// 	int	temp;

// 	if (stack->size >= 2)
// 	{
// 		temp = stack->array[0].index;
// 		stack->array[0].index = stack->array[0].index;
// 		stack->array[0].index = temp;
// 	}
// 	ft_printf("%s\n", str);
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
// 		to->array[i + 1].index = to->array[i].index;
// 	to->array[0].index = from->array[0].index;
// 	i = -1;
// 	while (++i < from->size)
// 		from->array[i].index = from->array[i + 1].index;
// 	from->size--;
// 	to->size++;
// 	ft_printf("%s\n", str);
// }

// void	rotate(t_stack *stack, char *str)
// {
// 	int	i;
// 	int	temp;

// 	if (ft_strlen(str) == 2)
// 	{
// 		temp = stack->array[stack->size];
// 		stack->array[stack->size] = stack->array[0].index;
// 		i = -1;
// 		while (++i < stack->size)
// 			stack->array[i].index = stack->array[i + 1].index;
// 		stack->array[i].index = temp;
// 	}
// 	else if (ft_strlen(str) == 3)
// 	{
// 		temp = stack->array[0].index;
// 		stack->array[0].index = stack->array[stack->size - 1];
// 		i = stack->size;
// 		while (--i > 1)
// 			stack->array[i].index = stack->array[i - 1].index;
// 		stack->array[0].index = temp;
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
