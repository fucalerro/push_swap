/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:19:01 by lferro            #+#    #+#             */
/*   Updated: 2023/12/11 17:21:26 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------- includes ---------------------------
*/

#ifndef PUSH_SWAP
# define PUSH_SWAP

#  include "../libft/libft.h"
#  include <fcntl.h>
#  include <math.h>
#  include <stdbool.h>
#  include <stdio.h>
#  include <stdlib.h>
#  include <string.h>
#  include <unistd.h>

#  define REVERSE	1
#  define NORMAL	0

#  define PS		(print_stacks(&a, &b))

/*
--------------------------- structures ---------------------------
*/

typedef struct s_stack
{
	int				size;
	int				*array;
}					t_stack;



/*
-------------------------- prototypes --------------------------
*/

void	print_stacks(t_stack *a, t_stack *b);
void	print_stack(t_stack *a);
int		is_sorted(t_stack *stack);

/*
old prototypes
 */

// void	rotate(t_stack *stack, char *str);
// void	rr(t_stack *a, t_stack *b, char *str);
// void	push(t_stack *from, t_stack *to, char *str);
// void	swap(t_stack *stack, char *str);

void	stack_init(t_stack *a, char **argv, int size);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *b, t_stack *a);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif
