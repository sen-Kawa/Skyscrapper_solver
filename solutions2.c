/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solutions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:59:08 by coder             #+#    #+#             */
/*   Updated: 2021/10/10 20:27:09 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	increment_views(char *lastel, char arr, int *nviews)
{
	if (arr > *lastel)
	{
		*lastel = arr;
		*nviews = *nviews + 1;
	}
}

int	check_row_rev(char *arr[4], char clues[4][4], int i, int e)
{
	int		k;
	int		nviews;
	char	lastel;

	lastel = '0';
	nviews = 0;
	k = 0;
	while (k < 4)
	{
		if (i == 1)
		{
			increment_views(&lastel, arr[3 - k][e], &nviews);
		}
		else
		{	
			increment_views(&lastel, arr[e][3 - k], &nviews);
		}
		k++;
	}
	return (nviews == (clues[i][e] - '0'));
}

int	check_columns(char *arr[4])
{
	int		i;
	int		k;
	char	arr1[4];
	int		j;

	i = 0;
	while (i < 4)
	{	
		k = 0;
		while (k < 4)
		{
			j = k - 1;
			arr1[k] = arr[k][i];
			while (j >= 0)
			{
				if (arr1[j] == arr[k][i])
					return (0);
				j--;
			}
			k++;
		}
		i++;
	}
	return (1);
}

int	check_row(char *arr[4], char clues[4][4], int i, int e)
{
	int		k;
	int		nviews;
	char	lastel;

	lastel = '0';
	nviews = 0;
	k = 0;
	while (k < 4)
	{
		if (i < 2)
		{
			increment_views(&lastel, arr[k][e], &nviews);
		}
		else
		{	
			increment_views(&lastel, arr[e][k], &nviews);
		}
		k++;
	}
	return (nviews == (clues[i][e] - '0'));
}

int	check_if_correct(char *arr[4], char clues[4][4])
{
	int		i;
	int		e;

	i = 0;
	if (!check_columns(arr))
		return (0);
	while (i < 4)
	{
		e = 0;
		while (e < 4)
		{
			if (!check_row(arr, clues, i, e)
				|| !check_row_rev(arr, clues, i + 1, e))
				return (0);
			e++;
		}
		i = i + 2;
	}
	return (1);
}
