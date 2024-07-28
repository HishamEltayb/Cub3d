/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:17:36 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/27 10:32:17 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		exit_mouse(t_data *data);
int		draw_player(t_data *data);
void	draw_square(t_data *data, int x, int y, int color);
void	my_mlx_pixel_put(t_data *data, t_img *image, int arr[2], int color);

int	exit_mouse(t_data *data)
{
	free_data(data);
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, t_img *image, int arr[2], int color)
{
	char	*dst;

	// if (arr[0] < 0 || arr[0] >= data->map_x * data->pixel || arr[1] < 0 || arr[1] >= data->map_y
	// 	* data->pixel)
	// 	return ;
	(void)data;
	dst = image->addr + (arr[1] * image->line_length + arr[0]
			* (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


void	draw_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;
	int arr[2];

	i = 0;
	while (i < data->pixel - 1)
	{
		j = 0;
		while (j < data->pixel - 1)
		{
			arr[0] = x + j;
			arr[1] = y + i;
			my_mlx_pixel_put(data, &data->main, arr, color);
			j++;
		}
		i++;
	}
}

int	draw_player(t_data *data)
{
	int	k;
	int	i;
	int	j;

	i = -8;
	k = 0;
	while (i < 8)
	{
		j = -8;
		while (j < 8)
		{
			my_mlx_pixel_put(data, &data->main, (int[2]){(data->player.x) + i,
				(data->player.y) + j}, BLUE);
			// mlx_pixel_put(data->mlx, data->win, (data->player.x) + i,
				// (data->player.y) + j, RED);
			j++;
		}
		i++;
	}
	while (k < 20)
	{
		my_mlx_pixel_put(data, &data->main, (int[2]){data->player.x + data->player.dx
			* k, data->player.y + data->player.dy * k}, BLUE);
		// mlx_pixel_put(data->mlx, data->win, data->player.x + data->player.dx
			// * k, data->player.y + data->player.dy * k, RED);
		k++;
	}
	return (0);
}
