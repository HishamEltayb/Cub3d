/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_equations1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:48:03 by heltayb           #+#    #+#             */
/*   Updated: 2024/08/11 21:39:31 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		hit_wall(t_raycast *ray, t_data *data);
void	init_help_nearest_horizontal_line(t_raycast *ray);
void	nearest_vertical_line(t_data *data, t_raycast *ray);
void	nearest_horizontal_line(t_data *data, t_raycast *ray);
double	cal_vert_horz_displacement(t_raycast *ray, t_data *data);

void	nearest_horizontal_line(t_data *data, t_raycast *ray)
{
	init_nearest_horizontal_line(data, ray);
	while (ray->dist_of_field < data->map_pixel_x)
		if (!nearest_horizontal_line_main_loop(data, ray))
			break ;
}

void	nearest_vertical_line(t_data *data, t_raycast *ray)
{
	init_nearest_vertical_line(data, ray);
	while (ray->dist_of_field < data->map_pixel_y)
		if (!nearest_vertical_line_main_loop(data, ray))
			break ;
	ray->vertical_x = ray->rx;
	ray->vertical_y = ray->ry;
}

int	hit_wall(t_raycast *ray, t_data *data)
{
	if (data->map2d[ray->my][ray->mx] == '1')
		return (true);
	return (false);
}

double	cal_vert_horz_displacement(t_raycast *ray, t_data *data)
{
	return (sqrt(pow(ray->rx - data->player.x, 2)
			+ pow(ray->ry - data->player.y, 2)));
}

void	init_help_nearest_horizontal_line(t_raycast *ray)
{
	ray->dist_of_field = 0;
	ray->tan = 1.0 / ray->tan;
}
