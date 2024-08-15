/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:47:38 by heltayb           #+#    #+#             */
/*   Updated: 2024/08/04 21:21:32 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_key_d(t_data *data, float new_x, float new_y);
void	handle_key_s(t_data *data, float new_x, float new_y);
void	handle_key_w(t_data *data, float new_x, float new_y);
void	handle_key_a(t_data *data, float new_x, float new_y);
int		check_collision(t_data *data, float new_x, float new_y);

int	check_collision(t_data *data, float new_x, float new_y)
{
	int	map_x1;
	int	map_y1;
	int	map_x2;
	int	map_y2;

	map_x1 = (int)(new_x - PLAYER_SIZE) / data->pixel_x;
	map_y1 = (int)(new_y - PLAYER_SIZE) / data->pixel_y;
	map_x2 = (int)(new_x + PLAYER_SIZE) / data->pixel_x;
	map_y2 = (int)(new_y + PLAYER_SIZE) / data->pixel_y;
	if (map_x1 < 0 || map_x1 >= data->map_x || map_y1 < 0
		|| map_y1 >= data->map_y || map_x2 < 0 || map_x2 >= data->map_x
		|| map_y2 < 0 || map_y2 >= data->map_y)
		return (1);
	return (data->map2d[map_y1][map_x1] == '1'
		|| data->map2d[map_y1][map_x2] == '1'
		|| data->map2d[map_y2][map_x1] == '1'
		|| data->map2d[map_y2][map_x2] == '1');
}

void	handle_key_w(t_data *data, float new_x, float new_y)
{
	new_x += (data->player.dx * data->player_speed);
	new_y += (data->player.dy * data->player_speed);
	if (!check_collision(data, new_x, new_y))
	{
		data->player.x = new_x;
		data->player.y = new_y;
		display(data);
	}
}

void	handle_key_s(t_data *data, float new_x, float new_y)
{
	new_x -= data->player.dx * data->player_speed;
	new_y -= data->player.dy * data->player_speed;
	if (!check_collision(data, new_x, new_y))
	{
		data->player.x = new_x;
		data->player.y = new_y;
		display(data);
	}
}

void	handle_key_d(t_data *data, float new_x, float new_y)
{
	new_x -= data->player.dy * data->player_speed;
	new_y += data->player.dx * data->player_speed;
	if (!check_collision(data, new_x, new_y))
	{
		data->player.x = new_x;
		data->player.y = new_y;
		display(data);
	}
}

void	handle_key_a(t_data *data, float new_x, float new_y)
{
	new_x += data->player.dy * data->player_speed;
	new_y -= data->player.dx * data->player_speed;
	if (!check_collision(data, new_x, new_y))
	{
		data->player.x = new_x;
		data->player.y = new_y;
		display(data);
	}
}
