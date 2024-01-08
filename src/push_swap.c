/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:40:08 by lferro            #+#    #+#             */
/*   Updated: 2024/01/08 18:38:16 by lferro           ###   ########.fr       */
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

int	check_int(char ***argv)
{
	int	i;
	int	j;

	i = 0;
	while ((*argv)[i])
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

int	check_maxint(const char ***argv, int stacksize)
{
	int		i;
	long	temp;
	i = 0;
	while (i < stacksize)
	{
		temp = ft_atol((*argv)[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			return (-1);
		i++;
	}
	return (0);
}


void	check_errors(char ***argv, int argc, t_stack *a, t_stack *b)
{
	int	stacksize;
	int	error;

	stacksize = 0;
	error = 0;
	while ((*argv)[stacksize])
		stacksize++;
	if (check_int(argv) == -1
		|| check_duplicate(argv, stacksize) == -1
		|| check_maxint((const char ***)argv, stacksize) == -1)
		error = 1;
	if (error == 1)
	{
		printf("Error\n");
		if (argc == 2)
			freeyer(argv, argc, a, b);
		exit(1);
	}
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
	{
		freeyer(&argv, argc, &a, &b);
		return (0);
	}
	sort(&a, &b);
	freeyer(&argv, argc, &a, &b);
	return (0);
}








