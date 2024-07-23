/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_and_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:49:18 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/23 21:32:56 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		display(t_data *data);
void	draw_map2d(t_data *data);
int		key_hook(int keycode, t_data *data);
void	key_left_right(t_data *data, int keycode);

int	display(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_map2d(data);
	draw_rays(data);
	draw_player(data);
	return (0);
}

void	key_left_right(t_data *data, int keycode)
{
	if (keycode == KEY_LEFT)
	{
		data->player.angle += 5;
		data->player.angle = (int)(data->player.angle) % 360;
		data->player.dx = cos(deg_to_rad(data->player.angle));
		data->player.dy = -sin(deg_to_rad(data->player.angle));
	}
	if (keycode == KEY_RIGHT)
	{
		data->player.angle -= 5;
		data->player.angle = (int)(data->player.angle) % 360;
		data->player.dx = cos(deg_to_rad(data->player.angle));
		data->player.dy = -sin(deg_to_rad(data->player.angle));
	}
}

int	check_collision(t_data *data, float new_x, float new_y)
{
	int map_x1 = (int)(new_x - PLAYER_SIZE / 2) / data->pixel;
	int map_y1 = (int)(new_y - PLAYER_SIZE / 2) / data->pixel;
	int map_x2 = (int)(new_x + PLAYER_SIZE / 2) / data->pixel;
	int map_y2 = (int)(new_y + PLAYER_SIZE / 2) / data->pixel;

	if (map_x1 < 0 || map_x1 >= data->map_x
		|| map_y1 < 0 || map_y1 >= data->map_y
		|| map_x2 < 0 || map_x2 >= data->map_x
		|| map_y2 < 0 || map_y2 >= data->map_y)
		return 1;
	return (data->map2d[map_y1][map_x1] == '1'
		|| data->map2d[map_y1][map_x2] == '1'
		|| data->map2d[map_y2][map_x1] == '1'
		|| data->map2d[map_y2][map_x2] == '1');
}

int	key_hook(int keycode, t_data *data)
{
	float	new_x;
	float	new_y;
	
	if (keycode == ESC)
		(free_data(data), printf("exited\n"), exit(0));
	new_x = data->player.x;
	new_y = data->player.y;
	if (keycode == KEY_W)
	{
		new_x += data->player.dx * 5;
		new_y += data->player.dy * 5;
	}
	if (keycode == KEY_S)
	{
		new_x -= data->player.dx * 5;
		new_y -= data->player.dy * 5;
	}
	if (keycode == KEY_D)
	{
		new_x -= data->player.dy * 5;
		new_y += data->player.dx * 5;
	}
	if (keycode == KEY_A)
	{
		new_x += data->player.dy * 5;
		new_y -= data->player.dx * 5;
	}
	if (!check_collision(data, new_x, new_y))
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
	key_left_right(data, keycode);
	return (0);
}

void	draw_map2d(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_y)
	{
		x = 0;
		while (x < data->map_x)
		{
			if (data->map2d[y][x] == '1')
				draw_square(data, x * data->pixel, y * data->pixel, WHITE);
			else if (data->map2d[y][x] == ' ')
				draw_square(data, x * data->pixel, y * data->pixel, BLUE);
			else
				draw_square(data, x * data->pixel, y * data->pixel, GRAY);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->main.img, 0, 0);
}
