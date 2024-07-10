/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_elements_create_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:36:26 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/10 10:33:26 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_element(char **split);
int	count_numbers(char *line, int *j);
int	check_numbers(char **split, int *i, int *check);

int	count_numbers(char *line, int *j)
{
	int	numbers;
	int	check;

	numbers = 0;
	check = *j;
	while (line && line[(*j)] && ft_isdigit(line[(*j)]))
		(*j)++;
	if (*j > check)
		numbers = 1;
	return (numbers);
}

int	check_numbers(char **split, int *i, int *check)
{
	int	j;

	while (split && split[(*i)])
	{
		j = 0;
		while (split[*i][j])
		{
			if (count_numbers(split[*i], &j))
				(*check)++;
			if (split[*i][j] != '\0')
				j++;
			else
				break ;
		}
		(*i)++;
	}
	return (1);
}

int	is_element(char **split)
{
	int	i;
	int	check;

	if (!ft_strcmp(split[0], "NO") || !ft_strcmp(split[0], "SO")
		|| !ft_strcmp(split[0], "WE") || !ft_strcmp(split[0], "EA"))
		return (1);
	else if (!ft_strcmp(split[0], "F") || !ft_strcmp(split[0], "C"))
	{
		i = 1;
		check = 0;
		check_numbers(split, &i, &check);
		if (check != 3)
			return (0);
		return (1);
	}
	else
		return (0);
}
