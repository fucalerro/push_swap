/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:40:08 by lferro            #+#    #+#             */
/*   Updated: 2024/01/08 16:36:36 by lferro           ###   ########.fr       */
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
void	stack_init(t_stack *a, char ***argv, int size)
{
	int	i;

	i = -1;
	a->array = malloc(sizeof(int) * size + 1);
	while ((*argv)[++i])
		a->array[i] = ft_atol((*argv)[i]);
	a->size = i;
}

int	check_duplicate(char ***argv, int stacksize)
{
	int	i;
	int	j;

	i = 0;
	while (i < stacksize)
	{
		j = i + 1;
		while (j < stacksize)
		{
			if (ft_strcmp((*argv)[i], (*argv)[j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_int(char ***argv, int stacksize)
{
	int	i;
	int	j;

	i = 0;
	while (i < stacksize)
	{
		j = 0;
		if ((*argv)[i][0] == '-')
		{
			if (!(*argv)[i][1])
				return (-1);
			j++;
		}
		while ((*argv)[i][j])
		{
			if ((*argv)[i][j] < '0' || (*argv)[i][j] > '9')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}


void	check_errors(char ***argv, int stacksize, int argc)
{

	if (check_int(argv, stacksize) == -1)
	{
		if (argc == 2)
			freeyer(argv);
		ft_printf("Error\nA number is not valid.\n  ");
		exit(1);
	}
	if (check_duplicate(argv, stacksize) == -1)
	{
		if (argc == 2)
			freeyer(argv);
		ft_printf("Error\nA number is duplicated.\n");
		exit(1);
	}
}

void	freeyer(char ***argv)
{
	int	i;

	i = -1;
	while ((*argv)[++i])
		free((*argv)[i]);
	free((*argv));
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
	check_errors(&argv, stacksize, argc);
	stack_init(&a, &argv, stacksize);
	b.array = malloc(sizeof(int) * stacksize + 1);
	b.size = 0;
	change_to_index(&a);
	sort(&a, &b);
	free(a.array);
	free(b.array);
	if (argc == 2)
		freeyer(&argv);
	return (0);
}








