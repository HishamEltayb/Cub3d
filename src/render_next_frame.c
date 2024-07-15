/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:58:24 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/15 13:28:51 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	red_murabaa(int x, int y, t_data *data);
void	blue_murabaa(int x, int y, t_data *data);
void	white_murabaa(int x, int y, t_data *data);
void	render_pixel(void *img, int x, int y, int color);

void	render_pixel(void *img, int x, int y, int color)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		index;

	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	index = (((int)y) * size_line) + (((int)x) * (bpp / 8));
	data[index] = color & 0xFF;
	data[index + 1] = (color >> 8) & 0xFF;
	data[index + 2] = (color >> 16) & 0xFF;
}

void	blue_murabaa(int x, int y, t_data *data)
{
	// while (x < 720)
	// {
	// 	y = 0;
	// 	while (y < 1080)
	// 	{
	// 		if (!(x % 80 == 0) && !(y % 90 == 0))
	// 			render_pixel(data->image.background, y, x, 0xFFFFFFF);
	// 		y++;
	// 	}
	// 	x++;
	// }
	int	x_size;
	int	y_size;

	x_size = (x + 1) * 80;
	y_size = (y + 1) * 90;
	x = x * 80;
	y = y * 90;
	while (x < x_size && x < 720)
	{
		y = 0;
		while (y < y_size && y < 1080)
		{
			if (!(x % 80 == 0) && !(y % 90 == 0))
				// mlx_pixel_put(data->mlx, data->win, y, x, 0x0000FF);
				render_pixel(data->image.background, y, x, 0x0000FF);
			y++;
		}
		x++;
	}
}
void	white_murabaa(int x, int y, t_data *data)
{
	// while (x < 720)
	// {
	// 	y = 0;
	// 	while (y < 1080)
	// 	{
	// 		if (!(x % 80 == 0) && !(y % 90 == 0))
	// 			render_pixel(data->image.background, y, x, 0xFFFFFFF);
	// 		y++;
	// 	}
	// 	x++;
	// }
	int	x_size;
	int	y_size;

	x_size = (x + 1) * 80;
	y_size = (y + 1) * 90;
	x = x * 80;
	y = y * 90;
	while (x < x_size && x < 720)
	{
		y = 0;
		while (y < y_size && y < 1080)
		{
			if (!(x % 80 == 0) && !(y % 90 == 0))
				// mlx_pixel_put(data->mlx, data->win, y, x, 0xFFFFFFF);
				render_pixel(data->image.background, y, x, 0xFFFFFFF);
			y++;
		}
		x++;
	}
}

void	red_murabaa(int x, int y, t_data *data)
{
	// while (x < 720)
	// {
	// 	y = 0;
	// 	while (y < 1080)
	// 	{
	// 		if (!(x % 80 == 0) && !(y % 90 == 0))
	// 			render_pixel(data->image.background, y, x, 0xFFFFFFF);
	// 		y++;
	// 	}
	// 	x++;
	// }
	int	x_size;
	int	y_size;

	x_size = (x + 1) * 80;
	y_size = (y + 1) * 90;
	x = x * 80;
	y = y * 90;
	while (x < x_size && x <= 720)
	{
		y = 0;
		while (y < y_size && y <= 1080)
		{
			if (!(x % 80 == 0) && !(y % 90 == 0))
				// mlx_pixel_put(data->mlx, data->win, y, x, 0xFF0000);
				render_pixel(data->image.background, y, x, 0xFF0000);
			y++;
		}
		x++;
	}
}