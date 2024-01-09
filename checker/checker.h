/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:14:28 by lferro            #+#    #+#             */
/*   Updated: 2024/01/09 15:00:32 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define MOVE_END	0
# define MOVE_ERROR	-1

# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				*array;
	int				size;
}					t_stack;

void	checkator(t_stack *a, t_stack *b);
void	check_errors(char ***argv, int argc, t_stack *a, t_stack *b);
int		stack_init(t_stack *a, char ***argv, int size);
int		is_sorted(t_stack *stack);
void	freeyer(char ***argv, int argc, t_stack *a, t_stack *b);
void	check_printer(bool prog_exist, t_stack *a, t_stack *b);
void	rotate(t_stack *stack, char *str);
void	push(t_stack *from, t_stack *to, char *str);
void	swap(t_stack *stack, char *str);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
int		is_empty(t_stack *stack);

#endif
