/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:40:08 by lferro            #+#    #+#             */
/*   Updated: 2024/01/09 10:14:51 by lferro           ###   ########.fr       */
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
int	stack_init(t_stack *a, char ***argv, int size)
{
	int	i;

	i = -1;
	a->array = malloc(sizeof(int) * size + 1);
	while ((*argv)[++i])
		a->array[i] = ft_atol((*argv)[i]);
	a->size = i;
	return (0);
}

void	freeyer(char ***argv, int argc, t_stack *a, t_stack *b)
{
	int	i;

	i = -1;
	if (argc == 2)
	{
		while ((*argv)[++i])
			free((*argv)[i]);
		free((*argv));
	}
	free(a->array);
	free(b->array);
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
	check_errors(&argv, argc, &a, &b);
	stack_init(&a, &argv, stacksize);
	b.array = malloc(sizeof(int) * stacksize + 1);
	b.size = 0;
	change_to_index(&a);
	if (is_sorted(&a))
		freeyer(&argv, argc, &a, &b);
	if (is_sorted(&a))
		return (0);
	sort(&a, &b);
	freeyer(&argv, argc, &a, &b);
	return (0);
}
