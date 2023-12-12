/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:40:08 by lferro            #+#    #+#             */
/*   Updated: 2023/12/12 14:36:22 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/**
 * @brief Initialize the stack with the given arguments
 *
 * @param a The stack to initialize
 * @param argv The arguments to initialize the stack with
 * @param size The size of the stack
 */
void	stack_init(t_stack *a, char **argv, int size)
{
	int	i;

	i = -1;
	a->array = malloc(sizeof(int) * size + 1);
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
	else if (argc > 2)
		argv++;
	stacksize = 0;
	while (argv[stacksize])
		stacksize++;
	stack_init(&a, argv, stacksize);
	b.array = malloc(sizeof(int) * stacksize + 1);
	b.size = 0;

	get_index(&a);
	sort(&a, &b);

	// print_stacks(&a, &b);
	// push(&a, &b, "pb");
	// push(&a, &b, "pb");
	// push(&a, &b, "pb");
	// // pb(&a, &b);
	// print_stacks(&a, &b);
	// pb(&a, &b);
	// print_stacks(&a, &b);
	// pb(&a, &b);
	// print_stacks(&a, &b);
	// sb(&b);
	// print_stacks(&a, &b);
	// sb(&b);
	// print_stacks(&a, &b);
	// sb(&b);
	// print_stacks(&a, &b);

	return (0);


}








