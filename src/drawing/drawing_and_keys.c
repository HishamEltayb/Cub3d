/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_and_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:49:18 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/28 20:12:26 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		display(t_data *data);
void	draw_map2d(t_data *data);
int		key_hook(int keycode, t_data *data);
void	key_left_right(t_data *data, int keycode);
void	draw_floor_ceiling(t_data *data);

void	draw_floor_ceiling(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT/2)
	{
		x = 0;
		while (x < WIDTH)
		{
	
			my_mlx_pixel_put(data, &data->main, (int[]){x, y}, data->ceiling_color);
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
	
			my_mlx_pixel_put(data, &data->main, (int[]){x, y}, data->floor_color);
			x++;
		}
		y++;
	}
}

int	display(t_data *data)
{
	create_image(data);
	mlx_clear_window(data->mlx, data->win);
	draw_floor_ceiling(data);
	draw_3drays(data);
	draw_map2d(data);
	draw_2drays(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->main.img, 0, 0);
	mlx_destroy_image(data->mlx, data->main.img);
	return (0);
}

void	key_left_right(t_data *data, int keycode)
{
	if (keycode == KEY_RIGHT)
	{
		data->player.angle += 5;
		data->player.angle = (int)(data->player.angle) % 360;
		data->player.dx = cos(deg_to_rad(data->player.angle));
		data->player.dy = -sin(deg_to_rad(data->player.angle));
	}
	if (keycode == KEY_LEFT)
	{
		data->player.angle -= 5;
		data->player.angle = (int)(data->player.angle) % 360;
		data->player.dx = cos(deg_to_rad(data->player.angle));
		data->player.dy = -sin(deg_to_rad(data->player.angle));
	}
}

int	check_collision(t_data *data, float new_x, float new_y)
{
	int map_x1 = (int)(new_x - data->player_size / 2) / data->pixel_x;
	int map_y1 = (int)(new_y - data->player_size / 2) / data->pixel_y;
	int map_x2 = (int)(new_x + data->player_size / 2) / data->pixel_x;
	int map_y2 = (int)(new_y + data->player_size / 2) / data->pixel_y;

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
	
	data->player_speed = 1;
	if (keycode == ESC)
		(free_data(data), printf("exited\n"), exit(0));
	new_x = data->player.x;
	new_y = data->player.y;
	if (keycode == KEY_W)
	{
		new_x += data->player.dx * data->player_speed;
		new_y += data->player.dy * data->player_speed;
	}
	if (keycode == KEY_S)
	{
		new_x -= data->player.dx * data->player_speed;
		new_y -= data->player.dy * data->player_speed;
	}
	if (keycode == KEY_A)
	{
		new_x -= data->player.dy * data->player_speed;
		new_y += data->player.dx * data->player_speed;
	}
	if (keycode == KEY_D)
	{
		new_x += data->player.dy * data->player_speed;
		new_y -= data->player.dx * data->player_speed;
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
				draw_square(data, x * data->pixel_x, y * data->pixel_y, WHITE);
			else if (data->map2d[y][x] == ' ')
				draw_square(data, x * data->pixel_x, y * data->pixel_y, BLUE);
			else
				draw_square(data, x * data->pixel_x, y * data->pixel_y, GRAY);
			x++;
		}
		y++;
	}
}
