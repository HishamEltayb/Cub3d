/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:37:31 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/21 21:15:48 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_image(t_img *image);
void	init_flags(t_data *data);
void	init_player(t_data *data);
void	init_raycast(t_data *data);
void	init_parsing(t_data *data);

void	init_flags(t_data *data)
{
	data->flags.C = NOT_EXIST;
	data->flags.F = NOT_EXIST;
	data->flags.EA = NOT_EXIST;
	data->flags.WE = NOT_EXIST;
	data->flags.SO = NOT_EXIST;
	data->flags.NO = NOT_EXIST;
	data->flags.PlayerN = NOT_EXIST;
	data->flags.PlayerS = NOT_EXIST;
	data->flags.PlayerW = NOT_EXIST;
	data->flags.PlayerE = NOT_EXIST;
}

void	init_player(t_data *data)
{
	data->player.is_exist = NOT_EXIST;
	data->player.x = 0;
	data->player.y = 0;
	data->player.dir = 0;
	data->player.dx = cos(RAD(data->player.angle));
	data->player.dy = -sin(RAD(data->player.angle));
}

void	init_raycast(t_data *data)
{
	data->raycast.r = 0;
	data->raycast.mx = 0;
	data->raycast.my = 0;
	data->raycast.mp = 0;
	data->raycast.dof = 0;
	data->raycast.ra = 0;
	data->raycast.rx = 0;
	data->raycast.ry = 0;
	data->raycast.xo = 0;
	data->raycast.yo = 0;
	data->raycast.disV = 0;
	data->raycast.disH = 0;
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
	data->pixel = 64;
	data->win = NULL;
	data->mlx = mlx_init();
}
