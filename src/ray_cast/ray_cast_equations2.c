/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_equations2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:48:03 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/23 16:27:33 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	grid_sinpping(float num, int pixel);
void	map_to_grid(t_raycast *ray, t_data *data);
int		is_valid_bounds(t_raycast *ray, t_data *data);
float	intersection_point_x(float px, float tan, float py, float ray_x);
float	intersection_point_y(float px, float tan, float py, float ray_y);

float	intersection_point_y(float px, float tan, float py, float ray_y)
{
	return ((py - ray_y) * tan + px);
}

//aligns the player's coordinate to the nearest lower grid cell boundary
float	grid_sinpping(float num, int pixel)
{
	return (((int)(num / pixel)) * pixel);
}

float	intersection_point_x(float px, float tan, float py, float ray_x)
{
	return ((px - ray_x) * tan + py);
}

void	map_to_grid(t_raycast *ray, t_data *data)
{
	ray->mx = (int)(ray->rx) / data->pixel;
	ray->my = (int)(ray->ry) / data->pixel;
}

int	is_valid_bounds(t_raycast *ray, t_data *data)
{
	if (ray->mx >= 0 && ray->my >= 0 && ray->mx < data->map_x
		&& ray->my < data->map_y)
		return (true);
	return (false);
}
