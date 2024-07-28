/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_map_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:06:37 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/28 16:40:56 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_check(t_data *data);
void	resize_map(t_data *data);
int		is_valid_map_char(char c, t_data *data);

void	resize_map(t_data *data)
{
	int		x;
	int		y;
	char	**map;
	char	**new_map;

	y = 0;
	map = data->map2d;
	new_map = ft_calloc((data->map_y + 1), sizeof(char *));
	while (map[y])
	{
		new_map[y] = ft_calloc((data->map_x + 1), sizeof(char));
		x = -1;
		while (map[y][++x])
			new_map[y][x] = map[y][x];
		while (x < data->map_x)
			new_map[y][x++] = ' ';
		new_map[y][x] = '\0';
		y++;
	}
	new_map[y] = NULL;
	free2d((void **)data->map2d);
	data->map2d = new_map;
}

void	map_check(t_data *data)
{
	data->map_size = (data->map_y * data->map_x);
	// data->pixel = (data->map_y * data->map_x) / 3;
	data->pixel_x = MINIMAP_X / data->map_x;
	data->pixel_y =	MINIMAP_Y / data->map_y;
	
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
