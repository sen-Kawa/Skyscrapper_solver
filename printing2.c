/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:03:08 by coder             #+#    #+#             */
/*   Updated: 2021/10/10 17:58:25 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
*Print out the solution which is a two dimensional array.
*
*/
void	print_solution(char *solution[4])
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			write(1, solution[i] + j, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
	return ;
}

void	print_error(void)
{
	write(1, "Error\n", 6);
	return ;
}
