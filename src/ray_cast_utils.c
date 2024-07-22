/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:46:57 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/22 11:07:15 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_help_draw_rays_horizontal(t_raycast *ray);
void	init_draw_rays_vertical(t_data *data, t_raycast *ray);
void	init_draw_rays_horizontal(t_data *data, t_raycast *ray);
int		draw_rays_horizontal_main_loop(t_data *data, t_raycast *ray);

void	init_help_draw_rays_horizontal(t_raycast *ray)
{
	ray->vx = ray->rx;
	ray->vy = ray->ry;
	ray->dof = 0;
	ray->disH = 100000;
	ray->Tan = 1.0 / ray->Tan;
}

void	init_draw_rays_horizontal(t_data *data, t_raycast *ray)
{
	init_help_draw_rays_horizontal(ray);
	if (sin(RAD(ray->ra)) > 0.001)
	{
		ray->ry = (((int)data->player.y / data->pixel) * data->pixel) - 0.0001;
		ray->rx = (data->player.y - ray->ry) * ray->Tan + data->player.x;
		ray->yo = -data->pixel;
		ray->xo = -ray->yo * ray->Tan;
	}
	else if (sin(RAD(ray->ra)) < -0.001)
	{
		ray->ry = (((int)data->player.y / data->pixel) * data->pixel)
			+ data->pixel;
		ray->rx = (data->player.y - ray->ry) * ray->Tan + data->player.x;
		ray->yo = data->pixel;
		ray->xo = -ray->yo * ray->Tan;
	}
	else
	{
		ray->rx = data->player.x;
		ray->ry = data->player.y;
		ray->dof = 8;
	}
}

void	init_draw_rays_vertical(t_data *data, t_raycast *ray)
{
	ray->dof = 0;
	ray->disV = 100000;
	ray->Tan = tan(RAD(ray->ra));
	if (cos(RAD(ray->ra)) > 0.001)
	{
		ray->rx = (((int)data->player.x / data->pixel) * data->pixel)
			+ data->pixel;
		ray->ry = (data->player.x - ray->rx) * ray->Tan + data->player.y;
		ray->xo = data->pixel;
		ray->yo = -ray->xo * ray->Tan;
	}
	else if (cos(RAD(ray->ra)) < -0.001)
	{
		ray->rx = (((int)data->player.x / data->pixel) * data->pixel) - 0.0001;
		ray->ry = (data->player.x - ray->rx) * ray->Tan + data->player.y;
		ray->xo = -data->pixel;
		ray->yo = -ray->xo * ray->Tan;
	}
	else
	{
		ray->rx = data->player.x;
		ray->ry = data->player.y;
		ray->dof = 8;
	}
}

int	draw_rays_horizontal_main_loop(t_data *data, t_raycast *ray)
{
	ray->mx = (int)(ray->rx) / data->pixel;
	ray->my = (int)(ray->ry) / data->pixel;
	if (ray->mx >= 0 && ray->my >= 0 && ray->mx < data->map_x
		&& ray->my < data->map_y)
	{
		ray->mp = ray->my * data->map_x + ray->mx;
		if (ray->mp >= 0 && ray->mp < data->map_x * data->map_y
			&& data->map2d[ray->my][ray->mx] == '1')
		{
			ray->dof = 8;
			ray->disH = cos(RAD(ray->ra)) * (ray->rx - data->player.x)
				- sin(RAD(ray->ra)) * (ray->ry - data->player.y);
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof += 1;
		}
	}
	else
		ray->dof = 8;
	if (ray->dof < 8)
		return (1);
	return (0);
}

int	draw_rays_vertical_main_loop(t_data *data, t_raycast *ray)
{
	ray->mx = (int)(ray->rx) / data->pixel;
	ray->my = (int)(ray->ry) / data->pixel;
	if (ray->mx >= 0 && ray->my >= 0 && ray->mx < data->map_x
		&& ray->my < data->map_y)
	{
		ray->mp = ray->my * data->map_x + ray->mx;
		if (ray->mp >= 0 && ray->mp < data->map_x * data->map_y
			&& data->map2d[ray->my][ray->mx] == '1')
		{
			ray->dof = 8;
			ray->disV = cos(RAD(ray->ra)) * (ray->rx - data->player.x)
				- sin(RAD(ray->ra)) * (ray->ry - data->player.y);
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof += 1;
		}
	}
	else
		ray->dof = 8;
	if (ray->dof < 8)
		return (1);
	return (0);
}
