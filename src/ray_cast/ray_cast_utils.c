/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:46:57 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/28 17:28:31 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_help_nearest_horizontal_line(t_raycast *ray);
void	init_nearest_vertical_line(t_data *data, t_raycast *ray);
void	init_nearest_horizontal_line(t_data *data, t_raycast *ray);
int		nearest_horizontal_line_main_loop(t_data *data, t_raycast *ray);
int		nearest_vertical_line_main_loop(t_data *data, t_raycast *ray);

void	init_nearest_horizontal_line(t_data *data, t_raycast *ray)
{
	init_help_nearest_horizontal_line(ray);
	if (sin(deg_to_rad(ray->angle)) > 0.001)
	{
		ray->ry = grid_sinpping(data->player.y, data->pixel_y) - 0.0001;
		ray->rx = intersection_point_y(data->player.x, ray->tan, data->player.y,
				ray->ry);
		ray->yo = -data->pixel_y;
		ray->xo = -ray->yo * ray->tan;
	}
	else if (sin(deg_to_rad(ray->angle)) < -0.001)
	{
		ray->ry = grid_sinpping(data->player.y, data->pixel_y) + data->pixel_y;
		ray->rx = intersection_point_y(data->player.x, ray->tan, data->player.y,
				ray->ry);
		ray->yo = data->pixel_y;
		ray->xo = -ray->yo * ray->tan;
	}
	else
	{
		ray->rx = data->player.x;
		ray->ry = data->player.y;
		ray->dist_of_field = data->minimap_x;
	}
}

//Checks if the cosine is greater than 0.001. This ensures that the
//ray is not pointing exactly vertically up or down,
//which would cause issues with infinite slopes or undefined behavior.
void	init_nearest_vertical_line(t_data *data, t_raycast *ray)
{
	if (cos(deg_to_rad(ray->angle)) > 0.001)
	{
		ray->rx = (grid_sinpping(data->player.x, data->pixel_x) + data->pixel_x);
		ray->ry = intersection_point_x(data->player.x, ray->tan, data->player.y,
				ray->rx);
		ray->xo = data->pixel_x;
		ray->yo = -ray->xo * ray->tan;
	}
	else if (cos(deg_to_rad(ray->angle)) < -0.001)
	{
		ray->rx = (grid_sinpping(data->player.x, data->pixel_x) - 0.0001);
		ray->ry = intersection_point_x(data->player.x, ray->tan, data->player.y,
				ray->rx);
		ray->xo = -data->pixel_x;
		ray->yo = -ray->xo * ray->tan;
	}
	else
	{
		ray->rx = data->player.x;
		ray->ry = data->player.y;
		ray->dist_of_field = data->minimap_y;
	}
}

int	nearest_horizontal_line_main_loop(t_data *data, t_raycast *ray)
{
	map_to_grid(ray, data);
	if (is_valid_bounds(ray, data))
	{
		ray->mp = ray->my * data->map_x + ray->mx;
		if (hit_wall(ray, data))
		{
			ray->dist_of_field = data->minimap_x;
			ray->dis_h = cal_vert_horz_displacement(ray, data);
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dist_of_field += 1;
		}
	}
	else
		ray->dist_of_field = data->minimap_x;
	if (ray->dist_of_field < data->minimap_x)
		return (1);
	return (0);
}

int	nearest_vertical_line_main_loop(t_data *data, t_raycast *ray)
{
	map_to_grid(ray, data);
	if (is_valid_bounds(ray, data))
	{
		ray->mp = ray->my * data->map_x + ray->mx;
		if (hit_wall(ray, data))
		{
			ray->dist_of_field = data->minimap_y;
			ray->dis_v = cal_vert_horz_displacement(ray, data);
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dist_of_field += 1;
		}
	}
	else
		ray->dist_of_field = data->minimap_y;
	if (ray->dist_of_field < data->minimap_y)
		return (true);
	return (false);
}
