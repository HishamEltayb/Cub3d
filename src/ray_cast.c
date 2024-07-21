/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:26:17 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/21 23:25:11 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_line(t_data *data, int x0, int y0, int x1, int y1, int color)
{
	t_raycast ray;
	
    ray.dx = abs(x1 - x0);
    ray.dy = -abs(y1 - y0);
	if (x0 < x1)
		ray.sx = 1;
	else
		ray.sx = -1;
	if (y0 < y1)
		ray.sy = 1;
	else
		ray.sy = -1;
    ray.err = ray.dx + ray.dy;
    while (1)
    {
        mlx_pixel_put(data->mlx, data->win, x0, y0, color);
        if (x0 == x1 && y0 == y1)
			break;
        ray.e2 = 2 * ray.err;
        if (ray.e2 >= ray.dy)
        {
            ray.err += ray.dy;
            x0 += ray.sx;
        }
        if (ray.e2 <= ray.dx)
        {
            ray.err += ray.dx;
            y0 += ray.sy;
        }
    }
}
void draw_rays(t_data *data)
{
    t_raycast ray;
    int mx, my;

    ray.ra = data->player.angle - 30;
    if (ray.ra < 0)
        ray.ra += 360;
    if (ray.ra > 360)
        ray.ra -= 360;
    ray.r = 0;
    while (ray.r < 60)
    {
        ray.dof = 0;
        ray.disV = 100000;
        ray.Tan = tan(RAD(ray.ra));
        if (cos(RAD(ray.ra)) > 0.001)
        {
            ray.rx = (((int)data->player.x >> 6) << 6) + 64;
            ray.ry = (data->player.x - ray.rx) * ray.Tan + data->player.y;
            ray.xo = 64;
            ray.yo = -ray.xo * ray.Tan;
        }
        else if (cos(RAD(ray.ra)) < -0.001)
        {
            ray.rx = (((int)data->player.x >> 6) << 6) - 0.0001;
            ray.ry = (data->player.x - ray.rx) * ray.Tan + data->player.y;
            ray.xo = -64;
            ray.yo = -ray.xo * ray.Tan;
        }
        else
        {
            ray.rx = data->player.x;
            ray.ry = data->player.y;
            ray.dof = 8;
        }

        while (ray.dof < 8)
        {
            mx = (int)(ray.rx) >> 6;
            my = (int)(ray.ry) >> 6;
            if (mx >= 0 && my >= 0 && mx < data->map_x && my < data->map_y)
            {
                ray.mp = my * data->map_x + mx;
                if (ray.mp >= 0 && ray.mp < data->map_x * data->map_y && data->map2d[my][mx] == '1')
                {
                    ray.dof = 8;
                    ray.disV = cos(RAD(ray.ra)) * (ray.rx - data->player.x) - sin(RAD(ray.ra)) * (ray.ry - data->player.y);
                }
                else
                {
                    ray.rx += ray.xo;
                    ray.ry += ray.yo;
                    ray.dof += 1;
                }
            }
            else
            {
                ray.dof = 8;
            }
        }
        ray.vx = ray.rx;
        ray.vy = ray.ry;

        ray.dof = 0;
        ray.disH = 100000;
        ray.Tan = 1.0 / ray.Tan;
        if (sin(RAD(ray.ra)) > 0.001)
        {
            ray.ry = (((int)data->player.y >> 6) << 6) - 0.0001;
            ray.rx = (data->player.y - ray.ry) * ray.Tan + data->player.x;
            ray.yo = -64;
            ray.xo = -ray.yo * ray.Tan;
        }
        else if (sin(RAD(ray.ra)) < -0.001)
        {
            ray.ry = (((int)data->player.y >> 6) << 6) + 64;
            ray.rx = (data->player.y - ray.ry) * ray.Tan + data->player.x;
            ray.yo = 64;
            ray.xo = -ray.yo * ray.Tan;
        }
        else
        {
            ray.rx = data->player.x;
            ray.ry = data->player.y;
            ray.dof = 8;
        }

        while (ray.dof < 8)
        {
            mx = (int)(ray.rx) >> 6;
            my = (int)(ray.ry) >> 6;
            if (mx >= 0 && my >= 0 && mx < data->map_x && my < data->map_y)
            {
                ray.mp = my * data->map_x + mx;
                if (ray.mp >= 0 && ray.mp < data->map_x * data->map_y && data->map2d[my][mx] == '1')
                {
                    ray.dof = 8;
                    ray.disH = cos(RAD(ray.ra)) * (ray.rx - data->player.x) - sin(RAD(ray.ra)) * (ray.ry - data->player.y);
                }
                else
                {
                    ray.rx += ray.xo;
                    ray.ry += ray.yo;
                    ray.dof += 1;
                }
            }
            else
            {
                ray.dof = 8;
            }
        }

        if (ray.disV < ray.disH)
        {
            ray.rx = ray.vx;
            ray.ry = ray.vy;
        }

        mlx_pixel_put(data->mlx, data->win, ray.rx, ray.ry, 0xFF0000);
        draw_line(data, data->player.x, data->player.y, ray.rx, ray.ry, 0xFF0000);
        
        ray.r++;
        ray.ra += 1;
        if (ray.ra < 0)
            ray.ra += 360;
        if (ray.ra > 360)
            ray.ra -= 360;
    }
}
