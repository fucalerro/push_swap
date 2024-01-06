/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:40:08 by lferro            #+#    #+#             */
/*   Updated: 2024/01/06 12:47:04 by lferro           ###   ########.fr       */
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

	change_to_index(&a);
	sort(&a, &b);

	// print_stacks(&a, &b);

	// free(a.array);
	// free(b.array);
	// free(argv);
	return (0);
}








