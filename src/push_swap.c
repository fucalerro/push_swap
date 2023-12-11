/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:40:08 by lferro            #+#    #+#             */
/*   Updated: 2023/12/11 17:21:03 by lferro           ###   ########.fr       */
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


void	sort_small(t_stack *a)
{
	if (a->array[0] > a->array[1])
		sa(a);
	if (a->array[1] > a->array[2])
		rra(a);
	if (a->array[0] > a->array[1])
		sa(a);
}

void	sort_medium(t_stack *a)
{

}




void	get_index(t_stack *a)
{

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

	if (is_sorted(&a) == true)
		return (0);


	if (a.size == 2)
		sa(&a);
	else if (a.size == 3)
		sort_small(&a);

	return (0);

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
