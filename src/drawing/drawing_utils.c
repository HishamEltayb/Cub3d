/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:17:36 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/22 10:16:58 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		exit_mouse(t_data *data);
int		draw_player(t_data *data);
void	draw_square(t_data *data, int x, int y, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int	exit_mouse(t_data *data)
{
	free_data(data);
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= data->map_x * data->pixel || y < 0 || y >= data->map_y
		* data->pixel)
		return ;
	dst = data->main.addr + (y * data->main.line_length + x
			* (data->main.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->pixel - 1)
	{
		j = 0;
		while (j < data->pixel - 1)
		{
			my_mlx_pixel_put(data, x + j, y + i, color);
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
			mlx_pixel_put(data->mlx, data->win,
				(data->player.x) + i, (data->player.y) + j, Red);
			j++;
		}
		i++;
	}
	while (k < 20)
	{
		mlx_pixel_put(data->mlx, data->win,
			data->player.x + data->player.dx * k,
			data->player.y + data->player.dy * k, Red);
		k++;
	}
	return (0);
}
