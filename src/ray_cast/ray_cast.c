/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:26:17 by heltayb           #+#    #+#             */
/*   Updated: 2024/08/11 21:02:22 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_data *data);
void	texture_cal(t_data *data, t_raycast *ray);
void	draw_texture(t_data *data, t_raycast *ray);

void	draw_texture(t_data *data, t_raycast *ray)
{
	float	y_texture;
	int		arr[2];
	int		pixel_pos;

	y_texture = 0;
	check_coordinate(data, ray);
	fisheye_correction(data, ray);
	wall_height_cal(data, ray);
	texture_cal(data, ray);
	pixel_pos = ray->line_offset;
	while (pixel_pos < ray->line_offset + ray->line_height)
	{
		if (ray->x_texture >= data->texture->width)
			ray->x_texture = data->texture->width - 1;
		if (y_texture >= data->texture->height)
			y_texture = data->texture->height - 1;
		arr[0] = ray->counter;
		arr[1] = pixel_pos;
		my_mlx_pixel_put(data, &data->main,
			arr, get_color(data, ray->x_texture, (int)y_texture));
		y_texture += ray->y_step;
		pixel_pos++;
	}
}

void	texture_cal(t_data *data, t_raycast *ray)
{
	if (ray->dis_v < ray->dis_h)
		ray->x_texture = ((double)((int)ray->ry % data->pixel_y)
				/ (double)(data->pixel_y)) * data->texture->width;
	if (ray->dis_h < ray->dis_v)
		ray->x_texture = ((double)((int)ray->rx % data->pixel_x)
				/ (double)(data->pixel_x)) * data->texture->width;
	ray->y_step = (float)data->texture->height / ray->line_height;
}

void	raycasting(t_data *data)
{
	t_raycast	ray;

	init_ray(&ray);
	ray.angle = data->player.angle - 30;
	reset_ray_angle(&ray.angle);
	ray.counter = WIDTH;
	while (ray.counter > 0)
	{
		init_raycast(&ray, data);
		nearest_vertical_line(data, &ray);
		nearest_horizontal_line(data, &ray);
		set_nearest_line(&ray);
		set_start_end_line(data, &ray);
		draw_texture(data, &ray);
		ray.counter -= 1;
		ray.angle += (double)60 / WIDTH;
		reset_ray_angle(&ray.angle);
	}
}
