/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_equations3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:48:03 by heltayb           #+#    #+#             */
/*   Updated: 2024/08/11 21:15:12 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	deg_to_rad(float angle);
void	init_raycast(t_raycast *ray, t_data *data);
void	reset_ray_angle(double *angle);
void	set_nearest_line(t_raycast *ray);
void	set_start_end_line(t_data *data, t_raycast *ray);

float	deg_to_rad(float angle)
{
	return (angle * (M_PI / 180));
}

void	reset_ray_angle(double *angle)
{
	if (*angle < 0)
		*angle += 360;
	if (*angle > 360)
		*angle -= 360;
}

void	set_nearest_line(t_raycast *ray)
{
	if (ray->dis_v < ray->dis_h)
	{
		ray->rx = ray->vertical_x;
		ray->ry = ray->vertical_y;
		ray->final_dist = ray->dis_v;
	}
	else if (ray->dis_h < ray->dis_v)
		ray->final_dist = ray->dis_h;
}

void	set_start_end_line(t_data *data, t_raycast *ray)
{
	ray->arr[0] = data->player.x;
	ray->arr[1] = data->player.y;
	ray->arr[2] = ray->rx;
	ray->arr[3] = ray->ry;
}

void	init_raycast(t_raycast *ray, t_data *data)
{
	ray->dis_v = (data->map_pixel_x + 1) * (data->map_x);
	ray->dis_h = (data->map_pixel_y + 1) * (data->map_y);
	ray->tan = tan(deg_to_rad(ray->angle));
	ray->dist_of_field = 0;
}
