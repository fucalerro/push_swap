/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:19:01 by lferro            #+#    #+#             */
/*   Updated: 2024/01/09 15:03:33 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------- includes ---------------------------
*/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

# define REVERSE	1
# define NORMAL	0

/*
--------------------------- structures ---------------------------
*/

typedef struct s_num
{
	int				num;
	int				index;
}					t_num;

typedef struct s_cost
{
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				rr;
	int				rrr;
	int				total_cost;
}					t_cost;

typedef struct s_stack
{
	int				size;
	int				*array;
}					t_stack;

/*
-------------------------- prototypes --------------------------
*/

void	print_stacks(t_stack *a, t_stack *b);
int		is_sorted(t_stack *stack);

void	three_sort(t_stack *a);
void	five_sort_low(t_stack *a, t_stack *b, int small_index);
void	five_sort_high(t_stack *a, t_stack *b, int small_index);
void	five_sort(t_stack *a, t_stack *b);
void	optimize_rotate(t_cost **cost, int i, t_stack *a, t_stack *b);
void	get_middle_cost(t_cost **cost, t_stack *a, t_stack *b, int i);
int		bring_max_top_cost(t_stack *stack);

int		check_duplicate(char ***argv, int stacksize);
int		check_int(char ***argv);
int		check_maxint(const char ***argv, int stacksize);
void	check_errors(char ***argv, int argc, t_stack *a, t_stack *b);

void	freeyer(char ***argv, int argc, t_stack *a, t_stack *b);
int		stack_init(t_stack *a, char ***argv, int size);
int		get_index(t_stack *stack, int value);
void	rotate(t_stack *stack, char *str);
void	push(t_stack *from, t_stack *to, char *str);
void	swap(t_stack *stack, char *str);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
// void	radix_sort(t_stack *a, t_stack *b);
void	change_to_index(t_stack *a);
void	sort(t_stack *a, t_stack *b);
int		get_max(t_stack *stack);
void	turk_sort(t_stack *a, t_stack *b);
void	bring_max_top(t_stack *stack);
void	b_cheaper(t_stack *a, t_stack *b, int cost);
int		get_min(t_stack *stack);
void	get_total_cost(t_cost **cost, int i);
int		get_cheapest_index(t_stack *a, t_cost **cost);
void	make_move(t_stack *a, t_stack *b, t_cost *cost, int cheapest);
void	get_cost(t_stack *a, t_stack *b, t_cost **cost);
void	reset_cost(t_cost **cost, t_stack *a);

#endif
