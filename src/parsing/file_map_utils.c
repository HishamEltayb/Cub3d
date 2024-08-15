/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:12:06 by heltayb           #+#    #+#             */
/*   Updated: 2024/08/11 21:33:29 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_space(t_data *data);
int		map_player_check(t_data *data);
bool	is_sourrounded_by_walls(t_data *data);

int	map_player_check(t_data *data)
{
	if (data->player.is_exist == NOT_EXIST)
		return (FALSE);
	return (TRUE);
}

bool	check_space(t_data *data)
{
	int	x;
	int	y;

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
				data->player.x = (x * data->pixel_x) + data->pixel_x / 2;
				data->player.y = (y * data->pixel_y) + data->pixel_y / 2;
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
