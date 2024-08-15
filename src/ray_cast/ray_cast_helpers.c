/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:18:25 by heltayb           #+#    #+#             */
/*   Updated: 2024/08/15 09:27:45 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_color(t_data *data, int x, int y);
void	wall_height_cal(t_data *data, t_raycast *ray);
void	fisheye_correction(t_data *data, t_raycast *ray);

void	wall_height_cal(t_data *data, t_raycast *ray)
{
	ray->line_height = (data->pixel_y / 2 * HEIGHT) / ray->final_dist;
	ray->line_offset = HEIGHT / 2 - (ray->line_height / 2);
}

void	fisheye_correction(t_data *data, t_raycast *ray)
{
	ray->ca = data->player.angle - ray->angle;
	if (ray->ca < 0)
		ray->ca += 360;
	if (ray->ca > 359)
		ray->ca -= 360;
	ray->final_dist = ray->final_dist * cos(deg_to_rad(ray->ca));
}

int	get_color(t_data *data, int x, int y)
{
	char	*dst;
	int		color;

	if (x < 0 || x >= data->texture->width)
		x = data->texture->width;
	if (y < 0 || y >= data->texture->height)
		y = data->texture->height;
	dst = data->texture->addr + (y * data->texture->line_length + x
			* (data->texture->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}
