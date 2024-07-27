/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:26:17 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/27 16:53:48 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rays(t_data *data);
void	draw_line(t_data *data, t_raycast *oray);
int		draw_line_loop(t_data *data, t_raycast *ray, t_raycast *oray);

int	draw_line_loop(t_data *data, t_raycast *ray, t_raycast *oray)
{
	my_mlx_pixel_put(data, &data->main, oray->arr, oray->color);
	if (oray->arr[0] == oray->arr[2] && oray->arr[1] == oray->arr[3])
		return (1);
	ray->e2 = 2 * ray->err;
	if (ray->e2 >= ray->dy)
	{
		ray->err += ray->dy;
		oray->arr[0] += ray->sx;
	}
	if (ray->e2 <= ray->dx)
	{
		ray->err += ray->dx;
		oray->arr[1] += ray->sy;
	}
	return (0);
}

void	draw_line(t_data *data, t_raycast *oray)
{
	t_raycast	ray;

	ray.dx = abs(oray->arr[2] - oray->arr[0]);
	ray.dy = -abs(oray->arr[3] - oray->arr[1]);
	if (oray->arr[0] < oray->arr[2])
		ray.sx = 1;
	else
		ray.sx = -1;
	if (oray->arr[1] < oray->arr[3])
		ray.sy = 1;
	else
		ray.sy = -1;
	ray.err = ray.dx + ray.dy;
	while (1)
		if (draw_line_loop(data, &ray, oray))
			break ;
}

void draw_3d_line(t_data *data, t_raycast *ray) {
    int ca;
    int line_height;
    int line_offset;
	int	y;
	//int x;
    int arr[2];
    
    ca = data->player.angle - ray->angle;
    if (ca < 0)
        ca += 360;
    if (ca > 360)
        ca -= 360;
    ray->final_dist = ray->final_dist * cos(deg_to_rad(ca));
    line_height = (data->pixel/2 * HEIGHT) / ray->final_dist;
    if (line_height > HEIGHT)
        line_height = HEIGHT;
    line_offset = HEIGHT/2 - (line_height / 2);
	y = line_offset;
	while (y < line_offset + line_height)
	{
		arr[0] = (ray->counter);
		arr[1] = y; 
		my_mlx_pixel_put(data, &data->main, arr, ray->color); 
		y++;
	}
}

void	draw_rays(t_data *data)
{
	t_raycast	ray;

	ray.angle = data->player.angle - 30;
	reset_ray_angle(&ray.angle);
	ray.counter = 0;
	while (ray.counter < WIDTH)
	{
		init_raycast(&ray);
		nearest_vertical_line(data, &ray);
		nearest_horizontal_line(data, &ray);
		set_nearest_line(&ray);
		set_start_end_line(data, &ray);
		draw_line(data, &ray);
		draw_3d_line(data, &ray);
		ray.counter += 1;
		ray.angle += (double)60 / WIDTH;
		reset_ray_angle(&ray.angle);
	}
}

