/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_coordinate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:17:07 by heltayb           #+#    #+#             */
/*   Updated: 2024/08/04 09:41:19 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*first_coordinate(t_data *data, t_raycast *ray);
t_img	*third_coordinate(t_data *data, t_raycast *ray);
void	check_coordinate(t_data *data, t_raycast *ray);
t_img	*second_coordinate(t_data *data, t_raycast *ray);
t_img	*fourth_coordinate(t_data *data, t_raycast *ray);

void	check_coordinate(t_data *data, t_raycast *ray)
{
	float	angle_rad;

	angle_rad = deg_to_rad(ray->angle);
	if (angle_rad >= 0 && angle_rad < M_PI / 2)
		data->texture = first_coordinate(data, ray);
	if (angle_rad >= M_PI / 2 && angle_rad < M_PI)
		data->texture = second_coordinate(data, ray);
	if (angle_rad >= M_PI && angle_rad < 3 * M_PI / 2)
		data->texture = third_coordinate(data, ray);
	if (angle_rad >= 3 * M_PI / 2 && angle_rad <= 2 * M_PI)
		data->texture = fourth_coordinate(data, ray);
}

t_img	*first_coordinate(t_data *data, t_raycast *ray)
{
	if (ray->final_dist == ray->dis_h)
		return (&data->image_no);
	else
		return (&data->image_ea);
}

t_img	*second_coordinate(t_data *data, t_raycast *ray)
{
	if (ray->final_dist == ray->dis_h)
		return (&data->image_no);
	else
		return (&data->image_we);
}

t_img	*third_coordinate(t_data *data, t_raycast *ray)
{
	if (ray->final_dist == ray->dis_h)
		return (&data->image_so);
	else
		return (&data->image_we);
}

t_img	*fourth_coordinate(t_data *data, t_raycast *ray)
{
	if (ray->final_dist == ray->dis_h)
		return (&data->image_so);
	else
		return (&data->image_ea);
}
