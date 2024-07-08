/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_map_check_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:49:22 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/08 20:59:34 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	checking(t_data *data, int x, int y, char c);
bool	check_up(t_data *data, int x, int y, char c);
bool	check_left(t_data *data, int x, int y, char c);
bool	check_down(t_data *data, int x, int y, char c);
bool	check_right(t_data *data, int x, int y, char c);

bool	checking(t_data *data, int x, int y, char c)
{
	if (data->map2d[y][x] != c)
		return (false);
	if (!check_up(data, x, y, c) && !check_down(data, x, y, c)
		&& !check_left(data, x, y, c) && !check_right(data, x, y, c))
		return (TRUE);
	return (FALSE);
}

bool	check_up(t_data *data, int x, int y, char c)
{
	char	**map;
	char	delimeter;

	map = data->map2d;
	if (y == 0 || x >= (int)ft_strlen(map[y - 1]))
	{
		if (c == '0')
			return (FALSE);
		return (TRUE);
	}
	if (c == ' ')
		delimeter = '1';
	else if (c == '0')
	{
		delimeter = '1';
		if (ft_strchr(PLAYER, map[y - 1][x]))
			return (TRUE);
	}
	else
		delimeter = '0';
	if (map[y - 1][x] == c || map[y - 1][x] == delimeter
		|| map[y - 1][x] == '1')
		return (TRUE);
	return (FALSE);
}

bool	check_down(t_data *data, int x, int y, char c)
{
	char	**map;
	char	delimeter;

	map = data->map2d;
	if ((y == ft_strlen2d(map) - 1) || (x >= (int)ft_strlen(map[y + 1])))
	{
		if (c == '0')
			return (FALSE);
		return (TRUE);
	}
	if (c == ' ')
		delimeter = '1';
	else if (c == '0')
	{
		delimeter = '1';
		if (ft_strchr(PLAYER, map[y + 1][x]))
			return (TRUE);
	}
	else
		delimeter = '0';
	if (map[y + 1][x] == c || map[y + 1][x] == delimeter
		|| map[y + 1][x] == '1')
		return (TRUE);
	return (FALSE);
}

bool	check_left(t_data *data, int x, int y, char c)
{
	char	**map;
	char	delimeter;

	map = data->map2d;
	if (x == 0)
	{
		if (c == '0')
			return (FALSE);
		return (TRUE);
	}
	if (c == ' ')
		delimeter = '1';
	else if (c == '0')
	{
		delimeter = '1';
		if (ft_strchr(PLAYER, map[y][x - 1]))
			return (TRUE);
	}
	else
		delimeter = '0';
	if (map[y][x - 1] == c || map[y][x - 1] == delimeter
		|| map[y][x - 1] == '1')
		return (TRUE);
	return (FALSE);
}

bool	check_right(t_data *data, int x, int y, char c)
{
	char	**map;
	char	delimeter;

	map = data->map2d;
	if (x == (int)(ft_strlen(map[y]) - 1))
	{
		if (c == '0')
			return (FALSE);
		return (TRUE);
	}
	if (c == ' ')
		delimeter = '1';
	else if (c == '0')
	{
		delimeter = '1';
		if (ft_strchr(PLAYER, map[y][x + 1]))
			return (TRUE);
	}
	else
		delimeter = '0';
	if (map[y][x + 1] == c || map[y][x + 1] == delimeter
		|| map[y][x + 1] == '1')
		return (TRUE);
	return (FALSE);
}
