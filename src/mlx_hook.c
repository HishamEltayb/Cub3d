/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:49:18 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/21 10:59:11 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int draw_player(t_data *data)
{
    int x = (int)data->player.x;
    int y = (int)data->player.y;
    int size = 8;

    for (int i = -size; i < size; i++)
        for (int j = -size; j < size; j++)
            mlx_pixel_put(data->mlx, data->win, x + i, y + j, Red);
	
	for (int k = 0; k < 20; k++)
		mlx_pixel_put(data->mlx, data->win, x + data->player.dx * k, y + data->player.dy * k, Red);
	
	return (0);
}

int	display(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);

	drawMap2D(data);
	draw_player(data);

	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		free_data(data);
		printf("exited\n");
		exit(0);
	}
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
	if (keycode == KEY_LEFT)
	{
        data->player.angle += 5;
        data->player.angle = (int)(data->player.angle) % 360;
        data->player.dx = cos(RAD(data->player.angle));
        data->player.dy = -sin(RAD(data->player.angle));
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
	if (keycode == KEY_RIGHT)
	{
        data->player.angle -= 5;
        data->player.angle = (int)(data->player.angle) % 360;
        data->player.dx = cos(RAD(data->player.angle));
        data->player.dy = -sin(RAD(data->player.angle));
	}
	return (0);
}

int	exit_mouse(t_data *data)
{
	free_data(data);
	exit(0);
	return (0);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    if (x < 0 || x >= data->width_x * data->pixel || y < 0 || y >= data->height_y * data->pixel) // Ensure coordinates are within bounds
        return;

    dst = data->img->addr + (y * data->img->line_length + x * (data->img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void draw_square(t_data *data, int x, int y, int color)
{
    int i, j;

    for (i = 0; i < data->pixel - 1; i++)
    {
        for (j = 0; j < data->pixel - 1; j++)
        {
            my_mlx_pixel_put(data, x + j, y + i, color);
        }
    }
}

void drawMap2D(t_data *data)
{
    int x, y;

    for (y = 0; y < data->height_y; y++)
    {
        for (x = 0; x < data->width_x; x++)
        {
            if (data->map2d[y][x] == '1')
                draw_square(data, x * data->pixel, y * data->pixel, White); // White color
            else if (data->map2d[y][x] == ' ')
				draw_square(data, x * data->pixel, y * data->pixel, Black); // Blue color
			else
                draw_square(data, x * data->pixel, y * data->pixel, Gray); // Black color
        }
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}