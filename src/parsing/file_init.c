/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:37:31 by heltayb           #+#    #+#             */
/*   Updated: 2024/08/14 07:27:20 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_raycast *ray);
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
}

void	init_player(t_data *data)
{
	data->player.is_exist = NOT_EXIST;
	data->player.x = 0;
	data->player.y = 0;
	data->player.dir = 0;
}

void	init_image(t_img *image)
{
	image->img = NULL;
	image->addr = NULL;
	image->bits_per_pixel = 0;
	image->line_length = 0;
	image->endian = 0;
	image->width = 0;
	image->height = 0;
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
	data->win = NULL;
	data->mlx = NULL;
	data->mlx = mlx_init();
	if (!data->mlx)
		error_free_exit(data, "Error\nMLX ERROR\n");
}

void	init_ray(t_raycast *ray)
{
	ray->vertical_x = 0;
	ray->vertical_y = 0;
	ray->mx = 0;
	ray->my = 0;
	ray->dist_of_field = 0;
	ray->rx = 0;
	ray->ry = 0;
	ray->xo = 0;
	ray->yo = 0;
	ray->dis_v = 0;
	ray->dis_h = 0;
	ray->tan = 0;
	ray->line_height = 1;
	ray->color = 0;
	ray->ca = 0;
	ray->line_offset = 0;
	ray->x_texture = 0;
	ray->y_step = 0;
}
