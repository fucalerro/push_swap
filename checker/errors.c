/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:56:33 by lferro            #+#    #+#             */
/*   Updated: 2024/01/09 15:02:21 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (check_int(argv) == -1 || check_duplicate(argv, stacksize) == -1
		|| check_maxint((const char ***)argv, stacksize) == -1)
		error = 1;
	if (error == 1)
	{
		ft_putstr_fd("Error\n", 2);
		if (argc == 2)
			freeyer(argv, argc, a, b);
		exit(1);
	}
}
