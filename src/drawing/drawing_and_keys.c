/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_and_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:49:18 by heltayb           #+#    #+#             */
/*   Updated: 2024/08/04 21:11:00 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		display(t_data *data);
void	draw_floor_ceiling(t_data *data);
int		key_hook(int keycode, t_data *data);
void	key_left_right(t_data *data, int keycode);

void	draw_floor_ceiling(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
			my_mlx_pixel_put(data, &data->main, (int []){x, y},
				data->ceiling_color);
		y++;
	}
	while (y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			my_mlx_pixel_put(data, &data->main, (int []){x, y},
				data->floor_color);
		y++;
	}
}

int	display(t_data *data)
{
	mlx_destroy_image(data->mlx, data->main.img);
	create_image(data);
	draw_floor_ceiling(data);
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->main.img, 0, 0);
	return (0);
}

void	key_left_right(t_data *data, int keycode)
{
	if (keycode == KEY_LEFT)
	{
		data->player.angle += 3;
		data->player.angle = (int)(data->player.angle) % 360;
		data->player.dx = cos(deg_to_rad(data->player.angle));
		data->player.dy = -sin(deg_to_rad(data->player.angle));
		display(data);
	}
	if (keycode == KEY_RIGHT)
	{
		data->player.angle -= 3;
		data->player.angle = (int)(data->player.angle) % 360;
		data->player.dx = cos(deg_to_rad(data->player.angle));
		data->player.dy = -sin(deg_to_rad(data->player.angle));
		display(data);
	}
}

int	key_hook(int keycode, t_data *data)
{
	float	new_x;
	float	new_y;

	data->player_speed = 3;
	if (keycode == ESC)
		(ft_putstr_fd("exited\n", 2), free_data(data), exit(0));
	new_x = data->player.x;
	new_y = data->player.y;
	if (keycode == KEY_W)
		handle_key_w(data, new_x, new_y);
	if (keycode == KEY_S)
		handle_key_s(data, new_x, new_y);
	if (keycode == KEY_D)
		handle_key_d(data, new_x, new_y);
	if (keycode == KEY_A)
		handle_key_a(data, new_x, new_y);
	key_left_right(data, keycode);
	return (0);
}
