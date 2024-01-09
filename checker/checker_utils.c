/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:35:35 by lferro            #+#    #+#             */
/*   Updated: 2024/01/09 13:33:02 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	is_sorted(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->size - 1)
		if (stack->array[i] > stack->array[i + 1])
			return (false);
	return (true);
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
