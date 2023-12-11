/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:19:01 by lferro            #+#    #+#             */
/*   Updated: 2023/12/06 16:17:34 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------- includes ---------------------------
*/

#ifndef PUSH_SWAP
# define PUSH_SWAP

#  include "libft/libft.h"
#  include <fcntl.h>
#  include <math.h>
#  include <stdbool.h>
#  include <stdio.h>
#  include <stdlib.h>
#  include <string.h>
#  include <unistd.h>

#  define REVERSE 1
#  define NORMAL 0

/*
--------------------------- structures ---------------------------
*/

typedef struct s_stack
{
	int				size;
	int				*array;
}					t_stack;

typedef struct s_num
{
	int				value;
	int				index;
}					t_num;

typedef struct s_content
{
	int				value;
	int				index;
}				t_content;

typedef struct s_node
{
	t_content		content;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

/*
-------------------------- prototypes --------------------------
*/

void	print_stack(t_stack *a, t_stack *b);

void	rotate(t_stack *stack, char *str);
void	rr(t_stack *a, t_stack *b, char *str);
void	push(t_stack *from, t_stack *to, char *str);
void	swap(t_stack *stack, char *str);

#endif