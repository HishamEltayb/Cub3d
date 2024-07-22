/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_and_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:49:18 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/22 14:32:06 by heltayb          ###   ########.fr       */
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

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		(free_data(data), printf("exited\n"), exit(0));
	if (keycode == KEY_W)
	{
		data->player.x += data->player.dx * 5;
		data->player.y += data->player.dy * 5;
	}
	if (keycode == KEY_S)
	{
		data->player.x -= data->player.dx * 5;
		data->player.y -= data->player.dy * 5;
	}
	if (keycode == KEY_D)
	{
		data->player.x -= data->player.dy * 5;
		data->player.y += data->player.dx * 5;
	}
	if (keycode == KEY_A)
	{
		data->player.x += data->player.dy * 5;
		data->player.y -= data->player.dx * 5;
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
				draw_square(data, x * data->pixel, y * data->pixel, White);
			else if (data->map2d[y][x] == ' ')
				draw_square(data, x * data->pixel, y * data->pixel, Blue);
			else
				draw_square(data, x * data->pixel, y * data->pixel, Gray);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->main.img, 0, 0);
}
