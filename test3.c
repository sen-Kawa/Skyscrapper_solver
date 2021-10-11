/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:36:33 by coder             #+#    #+#             */
/*   Updated: 2021/10/10 20:28:42 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	extract_clues(char *arguments, char clues[4][4]);

void	print_error(void);

int		whatever(char clues[4][4]);

int	main(int argc, char **argv)
{
	char	clues[4][4];

	if (argc != 2)
	{
		print_error();
	}
	else if (!extract_clues (argv[1], clues))
	{
		print_error();
	}
	else if (!whatever(clues))
	{
		print_error();
	}
	return (0);
}
