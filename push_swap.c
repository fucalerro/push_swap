/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:40:08 by lferro            #+#    #+#             */
/*   Updated: 2023/12/06 16:23:15 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *a, char **argv, int size)
{
	int		i;

	i = -1;
	a->array = malloc(sizeof(t_num) * size + 1);
	while (argv[++i])
		a->array[i] = ft_atol(argv[i]);
	a->size = i;
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		stacksize;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stacksize = 0;
	while (argv[stacksize])
		stacksize++;
	stack_init(&a, argv, stacksize);
	b.array = malloc(sizeof(int) * stacksize + 1);
	b.size = 0;
	push(&a, &b, "pb");
	push(&a, &b, "pb");
	push(&a, &b, "pb");
	print_stack(&a, &b);
	rr(&a, &b, "rrr");
	print_stack(&a, &b);
	rr(&a, &b, "rr");
	print_stack(&a, &b);
}
