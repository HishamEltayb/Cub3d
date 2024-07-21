/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment_delete_me.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:29:42 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/20 13:27:43 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>

typedef struct s_data {
    void *mlx;
    void *win;
    int width;
    int height;
    float px;
    float py;
    float pdx;
    float pdy;
    int pa;
} t_data;

# define RAD(x) (x * M_PI / 180.0)

void init(t_data *data);
int draw_player(t_data *data);
int draw(t_data *data);
int handle_keys(int keycode, t_data *data);

int handle_keys(int keycode, t_data *data)
{
    if (keycode == 0x00) // 'a' key
    {
        data->pa += 5;
        data->pa = data->pa % 360;
        data->pdx = cos(RAD(data->pa));
        data->pdy = -sin(RAD(data->pa));
    }
    if (keycode == 0x02) // 'd' key
    {
        data->pa -= 5;
        data->pa = data->pa % 360;
        data->pdx = cos(RAD(data->pa));
        data->pdy = -sin(RAD(data->pa));
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


int draw_player(t_data *data)
{
    int x = (int)data->px;
    int y = (int)data->py;
    int size = 8;

    // Draw player as a small rectangle
    for (int i = -size; i < size; i++)
    {
        for (int j = -size; j < size; j++)
        {
            mlx_pixel_put(data->mlx, data->win, x + i, y + j, 0xFFFF00);
        }
    }

    // Draw player direction
    mlx_pixel_put(data->mlx, data->win, x + data->pdx * 20, y + data->pdy * 20, 0xFFFF00);
	return (0);
}

int draw(t_data *data)
{
    // Clear the window by drawing a background
    mlx_clear_window(data->mlx, data->win);

    // Draw the player
    draw_player(data);

    return (0);
}

void init(t_data *data)
{
    // data->width = 1024;
    // data->height = 510;
    data->px = 150;
    data->py = 400;
    data->pa = 90;
    data->pdx = cos(RAD(data->pa));
    data->pdy = -sin(RAD(data->pa));

}

int main(void)
{
    t_data data;

    data.mlx = mlx_init();
    if (!data.mlx)
        return (1);
    data.win = mlx_new_window(data.mlx, 1024, 510, "CUB3D");
    if (!data.win)
        return (1);

    init(&data);

    // Hook your drawing and key handling functions here
    mlx_loop_hook(data.mlx, draw, &data);
	mlx_hook(data.win, 2, 1L << 0, handle_keys, &data);
    // mlx_key_hook(data.win, handle_keys, &data);
    
    mlx_loop(data.mlx);
    return (0);
}
