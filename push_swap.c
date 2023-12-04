/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:18:54 by lferro            #+#    #+#             */
/*   Updated: 2023/12/04 13:40:28 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char const *argv[])
{
	// printf("%d\n", ft_atoi(argv[1]));

	int	nbr;
	int	i;
	
	if (argc < 3)
	{
		printf("Error\nNot enough arguments.\n");
		exit(0);
	}
	i = 0;
	while (argv[++i])
		if (ft_atoi(argv[i]) < 0)
		{
			printf("Error\nInvalid numbers\n");
			exit(0);
		}



		
	return (0);
}
