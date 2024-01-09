/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:14:14 by lferro            #+#    #+#             */
/*   Updated: 2024/01/09 15:25:39 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../libft/libft.h"

int	do_move(t_stack *a, t_stack *b, char *stuff)
{
	if (ft_strncmp(stuff, "sa", 2) == 0)
		swap(a, "sa");
	else if (ft_strncmp(stuff, "sb", 2) == 0)
		swap(b, "sb");
	else if (ft_strncmp(stuff, "pa", 2) == 0)
		push(b, a, "pa");
	else if (ft_strncmp(stuff, "pb", 2) == 0)
		push(a, b, "pb");
	else if (ft_strncmp(stuff, "ra", 2) == 0)
		rotate(a, "ra");
	else if (ft_strncmp(stuff, "rb", 2) == 0)
		rotate(b, "rb");
	else if (ft_strncmp(stuff, "rra", 3) == 0)
		rotate(a, "rra");
	else if (ft_strncmp(stuff, "rrb", 3) == 0)
		rotate(b, "rrb");
	else if (ft_strncmp(stuff, "rr", 2) == 0)
		rr(a, b);
	else if (ft_strncmp(stuff, "rrr", 3) == 0)
		rrr(a, b);
	else if (ft_strncmp(stuff, "\n", 1) == 0)
		return (MOVE_END);
	else
		return (MOVE_ERROR);
	return (1);
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
	checkator(&a, &b);
	freeyer(&argv, argc, &a, &b);
	return (0);
}

void	checkator(t_stack *a, t_stack *b)
{
	char	*stuff;
	int		move_state;
	bool	prog_exist;

	prog_exist = 0;
	stuff = "";
	while (stuff)
	{
		stuff = get_next_line(STDIN_FILENO);
		if (stuff)
		{
			prog_exist = 1;
			move_state = do_move(a, b, stuff);
		}
		free(stuff);
		if (move_state == MOVE_ERROR)
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		else if (move_state == MOVE_END)
			break ;
	}
	check_printer(prog_exist, a, b);
}

void	check_printer(bool prog_exist, t_stack *a, t_stack *b)
{
	if (prog_exist == 0)
		ft_putstr_fd("Error\n", 2);
	else if (is_sorted(a) == 1 && is_empty(b) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	is_empty(t_stack *stack)
{
	if (stack->size == 0)
		return (true);
	return (false);
}
