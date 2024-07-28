/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:37:31 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/27 10:30:57 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_image(t_img *image);
void	init_flags(t_data *data);
void	init_player(t_data *data);
void	init_parsing(t_data *data);

void	init_flags(t_data *data)
{
	data->flags.c = NOT_EXIST;
	data->flags.f = NOT_EXIST;
	data->flags.ea = NOT_EXIST;
	data->flags.we = NOT_EXIST;
	data->flags.so = NOT_EXIST;
	data->flags.no = NOT_EXIST;
	data->flags.player_n = NOT_EXIST;
	data->flags.player_s = NOT_EXIST;
	data->flags.player_w = NOT_EXIST;
	data->flags.player_e = NOT_EXIST;
}

void	init_player(t_data *data)
{
	data->player.is_exist = NOT_EXIST;
	data->player.x = 0;
	data->player.y = 0;
	data->player.dir = 0;
	data->player.dx = cos(deg_to_rad(data->player.angle));
	data->player.dy = -sin(deg_to_rad(data->player.angle));
}

void	init_image(t_img *image)
{
	image->img = NULL;
	image->addr = NULL;
	image->bits_per_pixel = 0;
	image->line_length = 0;
	image->endian = 0;
}

void	init_parsing(t_data *data)
{
	data->map = NULL;
	data->element = NULL;
	data->map2d = NULL;
	data->valid_line_count = 0;
	data->floor_color = 0;
	data->ceiling_color = 0;
	data->map_y = 0;
	data->map_x = 0;
	data->pixel = 0;
	data->win = NULL;
	data->mlx = mlx_init();
}
