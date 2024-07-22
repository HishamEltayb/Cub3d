/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:26:17 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/22 11:07:24 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rays(t_data *data);
void	draw_line(t_data *data, int arr[4]);
void	draw_rays_vertical(t_data *data, t_raycast *ray);
void	draw_rays_horizontal(t_data *data, t_raycast *ray);
int		draw_line_loop(t_data *data, t_raycast *ray, int arr[4]);

int	draw_line_loop(t_data *data, t_raycast *ray, int arr[4])
{
	mlx_pixel_put(data->mlx, data->win, arr[0], arr[1], Red);
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

void	draw_rays_horizontal(t_data *data, t_raycast *ray)
{
	init_draw_rays_horizontal(data, ray);
	while (ray->dof < 8)
		if (!draw_rays_horizontal_main_loop(data, ray))
			break ;
	if (ray->disV < ray->disH)
	{
		ray->rx = ray->vx;
		ray->ry = ray->vy;
	}
}

void	draw_rays_vertical(t_data *data, t_raycast *ray)
{
	init_draw_rays_vertical(data, ray);
	while (ray->dof < 8)
	{
		if (!draw_rays_vertical_main_loop(data, ray))
			break ;
	}
}

void	draw_rays(t_data *data)
{
	t_raycast	ray;

	ray.ra = data->player.angle - 30;
	if (ray.ra < 0)
		ray.ra += 360;
	if (ray.ra > 360)
		ray.ra -= 360;
	ray.r = 0;
	while (ray.r < 60)
	{
		draw_rays_vertical(data, &ray);
		draw_rays_horizontal(data, &ray);
		mlx_pixel_put(data->mlx, data->win, ray.rx, ray.ry, 0xFF0000);
		ray.arr[0] = data->player.x;
		ray.arr[1] = data->player.y;
		ray.arr[2] = ray.rx;
		ray.arr[3] = ray.ry;
		draw_line(data, ray.arr);
		ray.r++;
		ray.ra += 1;
		if (ray.ra < 0)
			ray.ra += 360;
		if (ray.ra > 360)
			ray.ra -= 360;
	}
}
