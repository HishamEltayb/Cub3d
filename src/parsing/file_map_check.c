/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_map_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:06:37 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/16 11:38:34 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_check(t_data *data);
bool	check_space(t_data *data);
int		map_player_check(t_data *data);
bool	is_sourrounded_by_walls(t_data *data);
int		is_valid_map_char(char c, t_data *data);

void	map_check(t_data *data)
{
	if (map_player_check(data))
	{
		ft_putstr_fd("Error\nInvalid Map Characters1\n", 2);
		free_data(data);
		exit(1);
	}
	if (check_space(data))
	{
		ft_putstr_fd("Error\nInvalid Map\n", 2);
		free_data(data);
		exit(1);
	}
	if (is_sourrounded_by_walls(data))
	{
		ft_putstr_fd("Error\nInvalid Map\n", 2);
		free_data(data);
		exit(1);
	}
	else
		printf("Map is valid\n");
}

int	is_valid_map_char(char c, t_data *data)
{
	if (c == '0' || c == '1' || c == ' ')
		return (TRUE);
	else if (!is_valid_map_char_helper(data, c))
		return (TRUE);
	else if (!is_valid_map_char_helper2(data, c))
		return (TRUE);
	return (FALSE);
}

int	map_player_check(t_data *data)
{
	if (data->flags.PlayerN == NOT_EXIST && data->flags.PlayerS == NOT_EXIST
		&& data->flags.PlayerW == NOT_EXIST && data->flags.PlayerE == NOT_EXIST)
		return (FALSE);
	if (data->flags.PlayerN == EXIST)
		data->player.dir = 'N';
	else if (data->flags.PlayerS == EXIST)
		data->player.dir = 'S';
	else if (data->flags.PlayerW == EXIST)
		data->player.dir = 'W';
	else if (data->flags.PlayerE == EXIST)
		data->player.dir = 'E';
	return (TRUE);
}

bool	check_space(t_data *data)
{
	int		x;
	int		y;

	y = -1;
	while (data->map2d[++y])
	{
		x = -1;
		while (data->map2d[y][++x])
		{
			if (data->map2d[y][x] == ' ' && checking(data, x, y, ' '))
				return (ft_putstr_fd("error_space\n", 2), FALSE);
			else if (data->map2d[y][x] == '0' && checking(data, x, y, '0'))
				return (ft_putstr_fd("error_floor\n", 2), FALSE);
			else if (ft_strchr(PLAYER, data->map2d[y][x]))
			{
				if (checking(data, x, y, 'X'))
					return (ft_putstr_fd("error_player\n", 2), FALSE);
				data->player.x = x * data->pixel;
				data->player.y = y * data->pixel;
			}
		}
	}
	return (TRUE);
}

bool	is_sourrounded_by_walls(t_data *data)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = data->map2d;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (y == 0 && !is_space_or_one(map[y][x]))
				return (FALSE);
			else if (x == 0 && !is_space_or_one(map[y][x]))
				return (FALSE);
			else if (y == ft_strlen2d(map) - 1 && !is_space_or_one(map[y][x]))
				return (FALSE);
			else if (x == (int)(ft_strlen(map[y]) - 1)
					&& !is_space_or_one(map[y][x]))
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}
