/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:29:42 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/26 16:24:22 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int map2d[MAPY][MAPX] = { // the map array. Edit to change level but keep the outer walls
    {1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1},
};

int draw(t_data *data)
{
    mlx_clear_window(data->mlx, data->win);
    drawMap2D(data);
	draw_rays(data);
    draw_player(data);
    return (0);
}

int main(void)
{
    t_data data;

    data.mlx = mlx_init();
    init(&data);
    data.win = mlx_new_window(data.mlx, data.width_win, data.height_win, "CUB3D");
    mlx_loop_hook(data.mlx, draw, &data);
	mlx_hook(data.win, 2, 1L << 0, handle_keys, &data);
    mlx_key_hook(data.win, handle_keys, &data);
    mlx_loop(data.mlx);
}

//init
void init(t_data *data)
{
	//player position
    data->px = 150;
    data->py = 400;
    data->pa = 90;
    data->pdx = cos(deg_to_rad(data->pa));
    data->pdy = -sin(deg_to_rad(data->pa));
	//player position

	//map && window	
	data->width_map = MAPX;
    data->height_map = MAPY;
    data->pixel = MAPS;
    data->width_win= MAPX * data->pixel;
    data->height_win = MAPY * data->pixel;
	//map && window
	
	//image
	data->image.image = mlx_new_image(data->mlx, data->width_map * data->pixel, data->height_map * data->pixel);
    data->image.addr = mlx_get_data_addr(data->image.image, &data->image.bits_per_pixel, &data->image.line_length, &data->image.endian);
}

//player
int draw_player(t_data *data)
{
    int x = (int)data->px;
    int y = (int)data->py;
    int size = 8;

    for (int i = -size; i < size; i++)
        for (int j = -size; j < size; j++)
            mlx_pixel_put(data->mlx, data->win, x + i, y + j, 0xFFFF00);

    mlx_pixel_put(data->mlx, data->win, x + data->pdx * 20, y + data->pdy * 20, 0xFFFF00);
	return (0);
}

//keys
int handle_keys(int keycode, t_data *data)
{
    if (keycode == 0x00) // 'a' key
    {
        data->pa += 5;
        data->pa = data->pa % 360;
        data->pdx = cos(deg_to_rad(data->pa));
        data->pdy = -sin(deg_to_rad(data->pa));
    }
    if (keycode == 0x02) // 'd' key
    {
        data->pa -= 5;
        data->pa = data->pa % 360;
        data->pdx = cos(deg_to_rad(data->pa));
        data->pdy = -sin(deg_to_rad(data->pa));
    }
    if (keycode == 0x0D) // 'w' key
    {
        data->px += data->pdx * 5;
        data->py += data->pdy * 5;
    }
    if (keycode == 0x01) // 's' key
    {
        data->px -= data->pdx * 5;
        data->py -= data->pdy * 5;
    }
    if (keycode == 0x35) // 'ESC' key
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    return (0);
}

//map
void draw_square(t_data *data, int x, int y, int color)
{
    int i, j;

    for (i = 0; i < data->pixel - 1; i++)
    {
        for (j = 0; j < data->pixel - 1; j++)
        {
            my_mlx_pixel_put(data, x + j, y + i, color);
        }
    }
}

void drawMap2D(t_data *data)
{
    int x, y;

    for (y = 0; y < data->height_map; y++)
    {
        for (x = 0; x < data->width_map; x++)
        {
            if (map2d[y][x] == 1)
                draw_square(data, x * data->pixel, y * data->pixel, 0xFFFFFF); // White color
            else
                draw_square(data, x * data->pixel, y * data->pixel, 0xA0A0A0); // Black color
        }
    }
    mlx_put_image_to_window(data->mlx, data->win, data->image.image, 0, 0);
}

//utils
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    if (x < 0 || x >= data->width_map * data->pixel || y < 0 || y >= data->height_map * data->pixel) // Ensure coordinates are within bounds
        return;

    dst = data->image.addr + (y * data->image.line_length + x * (data->image.bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

//rays
void draw_rays(t_data *data)
{
    int r, mx, my, mp, dof;
    float ra, rx, ry, xo, yo, dis_v, dis_h;
    int mapX = data->width_map;
    int mapY = data->height_map;
    int mapS = data->pixel;
    float px = data->px;
    float py = data->py;
    float pa = data->pa;

    ra = pa - 30; // ray set back 30 degrees
    if (ra < 0) ra += 360;
    if (ra > 360) ra -= 360;

    for (r = 0; r < 60; r++)
    {
        //---Vertical---
        dof = 0;
        dis_v = 100000;
        float Tan = tan(deg_to_rad(ra));
        if (cos(deg_to_rad(ra)) > 0.001) { 
            rx = (((int)px >> 6) << 6) + 64; 
            ry = (px - rx) * Tan + py; 
            xo = 64; 
            yo = -xo * Tan; 
        }
        else if (cos(deg_to_rad(ra)) < -0.001) { 
            rx = (((int)px >> 6) << 6) - 0.0001; 
            ry = (px - rx) * Tan + py; 
            xo = -64; 
            yo = -xo * Tan; 
        }
        else { 
            rx = px; 
            ry = py; 
            dof = 8; 
        }
        while (dof < 8) 
        {
            mx = (int)(rx) >> 6; 
            my = (int)(ry) >> 6; 
            mp = my * mapX + mx; 
            if (mp > 0 && mp < mapX * mapY && map2d[my][mx] == 1) { 
                dof = 8; 
                dis_v = cos(deg_to_rad(ra)) * (rx - px) - sin(deg_to_rad(ra)) * (ry - py); 
            }
            else { 
                rx += xo; 
                ry += yo; 
                dof += 1; 
            }
        }
        float vertical_x = rx, vertical_y = ry;

        //---Horizontal---
        dof = 0;
        dis_h = 100000;
        Tan = 1.0 / Tan;
        if (sin(deg_to_rad(ra)) > 0.001) { 
            ry = (((int)py >> 6) << 6) - 0.0001; 
            rx = (py - ry) * Tan + px; 
            yo = -64; 
            xo = -yo * Tan; 
        }
        else if (sin(deg_to_rad(ra)) < -0.001) { 
            ry = (((int)py >> 6) << 6) + 64; 
            rx = (py - ry) * Tan + px; 
            yo = 64; 
            xo = -yo * Tan; 
        }
        else { 
            rx = px; 
            ry = py; 
            dof = 8; 
        }

        while (dof < 8) 
        {
            mx = (int)(rx) >> 6; 
            my = (int)(ry) >> 6; 
            mp = my * mapX + mx; 
            if (mp > 0 && mp < mapX * mapY && map2d[my][mx] == 1) { 
                dof = 8; 
                dis_h = cos(deg_to_rad(ra)) * (rx - px) - sin(deg_to_rad(ra)) * (ry - py); 
            }
            else { 
                rx += xo; 
                ry += yo; 
                dof += 1; 
            }
        }

        if (dis_v < dis_h) { 
            rx = vertical_x; 
            ry = vertical_y; 
        }

        // mlx_pixel_put(data->mlx, data->win, rx, ry, 0xFF0000); // Draw the ray
        draw_line(data, px, py, rx, ry, 0xFF0000); // Draw line from player to hit point

        ra += 1;
        if (ra < 0) ra += 360;
        if (ra > 360) ra -= 360;
    }
}

void draw_line(t_data *data, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = -abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;
    int e2;

    while (1)
    {
        mlx_pixel_put(data->mlx, data->win, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}
