/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:18:59 by lferro            #+#    #+#             */
/*   Updated: 2023/12/05 15:46:49 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_isspace(const char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\r'
		|| c == '\f')
		return (1);
	return (0);
}

static long	checknbr(const char *strnbr)
{
	size_t	i;

	i = 0;
	while(strnbr[i])
	{
		if (strnbr[i] < '0' || strnbr[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *strnbr)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 1;
	j = 0;
	k = 0;
	while (ft_isspace(strnbr[j]) == 1)
		j++;
	if (strnbr[j] == '+')
		j++;
	else if (strnbr[j] == '-')
	{
		i = -1;
		j++;
	}
	if (checknbr(strnbr) == -1)
		return (-1);
	while (strnbr[j] >= '0' && strnbr[j] <= '9')
		k = k * 10 + strnbr[j++] - 48;
	return (k * i);
}

long	ft_atol(const char *strnbr)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 1;
	j = 0;
	k = 0;
	while (ft_isspace(strnbr[j]) == 1)
		j++;
	if (strnbr[j] == '+')
		j++;
	else if (strnbr[j] == '-')
	{
		i = -1;
		j++;
	}
	if (checknbr(strnbr) == -1)
		return (-1);
	while (strnbr[j] >= '0' && strnbr[j] <= '9')
		k = k * 10 + strnbr[j++] - 48;
	return (k * i);
}

// int main(void)
// {
// 	char *s = "\010 7";
// 	printf("ft: %d", ft_atoi(s));
// 	printf("\nlb: %d", atoi(s));

// 	return (0);
// }
