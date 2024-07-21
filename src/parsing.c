/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:53:03 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/21 10:25:21 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing(t_data *data, int ac, char **av);
void install_background_image(t_data *data);

void	parsing(t_data *data, int ac, char **av)
{
	int width_x;
	int height_y;
	
	init_data(data);
	data->mlx = mlx_init();
	file_pre_check(ac, av);
	file_store_data(av[1], data);
	map_check(data);
	data->pixel = data->map_size / 2;
	width_x = data->pixel * data->width_x ;
	height_y = data->pixel * data->height_y;
	data->win = mlx_new_window(data->mlx, width_x, height_y, "CUB3D");
}

void install_background_image(t_data *data)
{
	data->img->img = mlx_new_image(data->mlx, data->map_size * data->width_x, data->map_size * data->height_y);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
}