/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:26:17 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/27 10:30:27 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rays(t_data *data);
void	draw_line(t_data *data, int arr[4]);
int		draw_line_loop(t_data *data, t_raycast *ray, int arr[4]);

int	draw_line_loop(t_data *data, t_raycast *ray, int arr[4])
{
	my_mlx_pixel_put(data, &data->main, arr, RED);
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

void draw_3d_line(t_data *data, t_raycast *ray) {
    int ca;
    int line_height;
    int line_offset;
    
    // Calculate the corrected angle to adjust for the player's view angle.
    ca = data->player.angle - ray->angle;
    if (ca < 0)
        ca += 360;
    if (ca > 360)
        ca -= 360;
    
    // Adjust the distance to correct for the fisheye effect.
    ray->final_dist = ray->final_dist * cos(deg_to_rad(ca));
    
    // Calculate the height of the line to be drawn based on the distance to the wall.
    line_height = (data->map_size * 320) / ray->final_dist;
    
    // Limit the line height to a maximum value to avoid rendering issues.
    if (line_height > 320)
        line_height = 320;
    
    // Calculate the vertical offset of the line to center it in the viewport.
    line_offset = 160 - (line_height >> 1);
    
    int arr[2];
    
    // Draw the vertical line representing the wall slice at the correct position.
		for (int y = line_offset; y < line_offset + line_height; y++) 
		{
			for (int x = ray->counter * 8 + 900; x < ray->counter * 8 + 908; x++)
			{
				arr[0] = x; // Horizontal position of the line
				arr[1] = y; // Vertical position of the pixel
				my_mlx_pixel_put(data, &data->main, arr, BROWN); // Draw the pixel in the image
			}
		}
	
}

void	draw_rays(t_data *data)
{
	t_raycast	ray;

	
	ray.angle = data->player.angle - 30;
	reset_ray_angle(&ray.angle);
	ray.counter = 0;
	while (ray.counter < 60)
	{
		init_raycast(&ray);
		nearest_vertical_line(data, &ray);
		nearest_horizontal_line(data, &ray);
		set_nearest_line(&ray);
		set_start_end_line(data, &ray);
		draw_line(data, ray.arr);
		draw_3d_line(data, &ray);
		ray.counter++;
		ray.angle += 1;
		reset_ray_angle(&ray.angle);
	}
}

