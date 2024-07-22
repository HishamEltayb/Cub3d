/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_elements_create_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:36:26 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/21 20:08:27 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_mini_atoi(char *str);
void	skip_zeros(int *i, char *str);
int		count_numbers(char *line, int *j);
int		is_element(char **split, t_data *data);
int		check_numbers(char **split, int *i, int *check);

void	skip_zeros(int *i, char *str)
{
	while (str[*i] == '0')
		(*i)++;
}

int	ft_mini_atoi(char *str)
{
	int				i;
	int				digits;
	unsigned long	num;

	if (str == NULL)
		return (-1);
	i = 0;
	num = 0;
	digits = 0;
	skip_zeros(&i, str);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			digits++;
		else
			return (-1);
		num = (num * 10) + (str[i] - '0');
		if (num > 255)
			return (-1);
		if (digits > 3)
			return (-1);
		i++;
	}
	return (num);
}

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

int	is_element(char **split, t_data *data)
{
	int	i;
	int	check;

	(void)data;
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
