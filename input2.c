/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:58:45 by coder             #+#    #+#             */
/*   Updated: 2021/10/09 17:00:28 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* Check if c is between char '1' and '4'.
*/
char	check_numbers(char c)
{
	return (c >= '1' && c <= '4');
}

char	check_space(char c)
{
	return (c == ' ');
}

/*
*	For this project we will use 2 4*4 char arrays
*   One will be to store the clues about the views
* 	and one to store our solution.
*/
char	norminette_is_annoying(char c, unsigned int *count_spaces
	, char clues[4][4], unsigned int *count_numbers)
{
	if (check_numbers(c) && *count_spaces == 1)
	{
		clues[*count_numbers / 4][*count_numbers % 4] = c;
		(*count_numbers)++;
		if (*count_numbers < 16)
			*count_spaces = 0;
	}
	else
		return (0);
	return (1);
}
/**
* It's a function that extract the arguments given to main
* and fill the 2 dimensional array clues.
* If everything goes well return 1; otherwise 0;
*/

char	extract_clues(char *arguments, char clues[4][4])
{
	unsigned int	i;
	unsigned int	count_numbers;
	unsigned int	count_spaces;

	i = 0;
	count_numbers = 0;
	count_spaces = 1;
	while (arguments[i] != '\0')
	{
		if (!check_space(arguments[i]))
		{
			if (!norminette_is_annoying(arguments[i], &count_spaces,
					clues, &count_numbers))
				return (0);
		}
		else
		{
			if (count_spaces == 1)
				return (0);
			count_spaces++;
		}
		i++;
	}
	return (count_numbers == 16);
}
