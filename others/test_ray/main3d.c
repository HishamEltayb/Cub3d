/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:29:42 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/27 10:26:15 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Map settings
#define mapX 8
#define mapY 8
#define mapS 64

// Window settings
#define win_width 1024
#define win_height 510

int map[] = {
    1,1,1,1,1,1,1,1,
    1,0,1,0,0,0,0,1,
    1,0,1,0,0,0,0,1,
    1,0,1,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,1,
    1,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,
};

typedef struct {
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    float px, py, pdx, pdy, pa;
} t_data;

float degToRad(int a) { return a * M_PI / 180.0; }
int FixAng(int a) { if (a > 359) a -= 360; if (a < 0) a += 360; return a; }
float distance(float ax, float ay, float bx, float by, int ang) { return cos(degToRad(ang)) * (bx - ax) - sin(degToRad(ang)) * (by - ay); }

void my_mlx_pixel_put(t_data *data, int x, int y, int color) {
    char *dst;

    if (x < 0 || x >= win_width || y < 0 || y >= win_height)
        return;
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void drawMap2D(t_data *data) {
    int x, y, xo, yo;

    for (y = 0; y < mapY; y++) {
        for (x = 0; x < mapX; x++) {
            if (map[y * mapX + x] == 1) {
                for (yo = 0; yo < mapS; yo++) {
                    for (xo = 0; xo < mapS; xo++) {
                        my_mlx_pixel_put(data, x * mapS + xo, y * mapS + yo, 0xFFFFFF);
                    }
                }
            }
        }
    }
}

void drawPlayer2D(t_data *data) {
    int x, y;

    for (y = -5; y < 5; y++) {
        for (x = -5; x < 5; x++) {
            my_mlx_pixel_put(data, data->px + x, data->py + y, 0xFFFF00);
        }
    }

    for (int i = 0; i < 20; i++) {
        my_mlx_pixel_put(data, data->px + data->pdx * i, data->py + data->pdy * i, 0xFFFF00);
    }
}

int handle_keypress(int key, t_data *data) {
    if (key == 0x00) {// 'a' key
        data->pa += 5; data->pa = FixAng(data->pa); data->pdx = cos(degToRad(data->pa)); data->pdy = -sin(degToRad(data->pa));
    }
    if (key == 0x02) { // 'd' key
        data->pa -= 5; data->pa = FixAng(data->pa); data->pdx = cos(degToRad(data->pa)); data->pdy = -sin(degToRad(data->pa));
    }
    if (key == 0x0D) { // 'w' key
        data->px += data->pdx * 5; data->py += data->pdy * 5;
    }
    if (key == 0x01) { // 's' key
        data->px -= data->pdx * 5; data->py -= data->pdy * 5;
    }
    if (key == 0x35) { // 'ESC' key
        exit(0);
    }
    return 0;
}

void drawRays2D(t_data *data) {
    int r, mx, my, mp, dof, side; float vx, vy, rx, ry, ra, xo, yo, disV, disH;

    ra = FixAng(data->pa + 30);
    for (r = 0; r < 60; r++) {
        //---Vertical---
        dof = 0; side = 0; disV = 100000;
        float Tan = tan(degToRad(ra));
        if (cos(degToRad(ra)) > 0.001) { rx = (((int)data->px >> 6) << 6) + 64; ry = (data->px - rx) * Tan + data->py; xo = 64; yo = -xo * Tan; }
        else if (cos(degToRad(ra)) < -0.001) { rx = (((int)data->px >> 6) << 6) - 0.0001; ry = (data->px - rx) * Tan + data->py; xo = -64; yo = -xo * Tan; }
        else { rx = data->px; ry = data->py; dof = 8; }

        while (dof < 8) {
            mx = (int)(rx) >> 6; my = (int)(ry) >> 6; mp = my * mapX + mx;
            if (mp > 0 && mp < mapX * mapY && map[mp] == 1) { dof = 8; disV = cos(degToRad(ra)) * (rx - data->px) - sin(degToRad(ra)) * (ry - data->py); }
            else { rx += xo; ry += yo; dof += 1; }
        }
        vx = rx; vy = ry;

        //---Horizontal---
        dof = 0; disH = 100000;
        Tan = 1.0 / Tan;
        if (sin(degToRad(ra)) > 0.001) { ry = (((int)data->py >> 6) << 6) - 0.0001; rx = (data->py - ry) * Tan + data->px; yo = -64; xo = -yo * Tan; }
        else if (sin(degToRad(ra)) < -0.001) { ry = (((int)data->py >> 6) << 6) + 64; rx = (data->py - ry) * Tan + data->px; yo = 64; xo = -yo * Tan; }
        else { rx = data->px; ry = data->py; dof = 8; }

        while (dof < 8) {
            mx = (int)(rx) >> 6; my = (int)(ry) >> 6; mp = my * mapX + mx;
            if (mp > 0 && mp < mapX * mapY && map[mp] == 1) { dof = 8; disH = cos(degToRad(ra)) * (rx - data->px) - sin(degToRad(ra)) * (ry - data->py); }
            else { rx += xo; ry += yo; dof += 1; }
        }

        if (disV < disH) { rx = vx; ry = vy; disH = disV; }

        int ca = FixAng(data->pa - ra); disH = disH * cos(degToRad(ca)); 
        int lineH = (mapS * 320) / disH; if (lineH > 320) { lineH = 320; } 
        int lineOff = 160 - (lineH >> 1); 

        for (int y = lineOff; y < lineOff + lineH; y++) {
            my_mlx_pixel_put(data, r * 8 + 530, y, 0x0000FF);
        }

        ra = FixAng(ra - 1);
    }
}

int render_frame(t_data *data) {
    data->img = mlx_new_image(data->mlx, win_width, win_height);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
    mlx_clear_window(data->mlx, data->win);
    drawMap2D(data);
    drawPlayer2D(data);
    drawRays2D(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
    return 0;
}

int main() {
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, win_width, win_height, "MiniLibX Example");
    data.img = mlx_new_image(data.mlx, win_width, win_height);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

    data.px = 150;
    data.py = 400;
    data.pa = 90;
    data.pdx = cos(degToRad(data.pa));
    data.pdy = -sin(degToRad(data.pa));

    mlx_loop_hook(data.mlx, render_frame, &data);
    mlx_key_hook(data.win, handle_keypress, &data);
    mlx_loop(data.mlx);

    return 0;
}
