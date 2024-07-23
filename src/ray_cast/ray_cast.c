/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:26:17 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/23 16:41:33 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rays(t_data *data);
void	draw_line(t_data *data, int arr[4]);
int		draw_line_loop(t_data *data, t_raycast *ray, int arr[4]);

int	draw_line_loop(t_data *data, t_raycast *ray, int arr[4])
{
	mlx_pixel_put(data->mlx, data->win, arr[0], arr[1], RED);
	if (arr[0] == arr[2] && arr[1] == arr[3])
		return (1);
	ray->e2 = 2 * ray->err;
	if (ray->e2 >= ray->dy)
	{
		ray->err += ray->dy;
		arr[0] += ray->sx;
	}
	if (ray->e2 <= ray->dx)
	{
		ray->err += ray->dx;
		arr[1] += ray->sy;
	}
	return (0);
}

void	draw_line(t_data *data, int arr[4])
{
	t_raycast	ray;

	ray.dx = abs(arr[2] - arr[0]);
	ray.dy = -abs(arr[3] - arr[1]);
	if (arr[0] < arr[2])
		ray.sx = 1;
	else
		ray.sx = -1;
	if (arr[1] < arr[3])
		ray.sy = 1;
	else
		ray.sy = -1;
	ray.err = ray.dx + ray.dy;
	while (1)
		if (draw_line_loop(data, &ray, arr))
			break ;
}

void	draw_rays(t_data *data)
{
	t_raycast	ray;

	ray.angle = data->player.angle - 30;
	reset_ray_angle(&ray);
	ray.counter = 0;
	while (ray.counter < 60)
	{
		init_raycast(&ray);
		nearest_vertical_line(data, &ray);
		nearest_horizontal_line(data, &ray);
		set_nearest_line(&ray);
		set_start_end_line(data, &ray);
		draw_line(data, ray.arr);
		ray.counter++;
		ray.angle += 1;
		reset_ray_angle(&ray);
	}
}
