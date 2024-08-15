/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:24:59 by heltayb           #+#    #+#             */
/*   Updated: 2024/08/11 21:18:35 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data);
void	init_draw(t_data *data);

void	init_draw(t_data *data)
{
	data->player.dx = cos(deg_to_rad(data->player.angle));
	data->player.dy = -sin(deg_to_rad(data->player.angle));
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "CUB3D");
	create_image(data);
	draw_floor_ceiling(data);
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->main.img, 0, 0);
}

void	init_data(t_data *data)
{
	init_flags(data);
	init_player(data);
	init_image(&data->main);
	init_image(&data->image_ea);
	init_image(&data->image_we);
	init_image(&data->image_so);
	init_image(&data->image_no);
	init_parsing(data);
}
