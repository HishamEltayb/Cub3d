/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:44:45 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/22 14:32:06 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>

#define MAPX 8      // map width
#define MAPY 8      // map height
#define MAPS 64     // map cube size
#define deg_to_rad(x) (x * M_PI / 180.0)

typedef struct s_image {
    void *image;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_image;

typedef struct s_data {
    void *mlx;
    void *win;
	
	//player position
    float px;
    float py;
    float pdx;
    float pdy;
    int pa;
	//player position
	
	//map
    int pixel;
    int width_map;
    int height_map;
    int width_win;
    int height_win;
	//map
	
	//image
    t_image image;
	//image
	
} t_data;


//init
void	init(t_data *data);

//utils
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		handle_keys(int keycode, t_data *data);

//draw
int		draw(t_data *data);
int		draw_player(t_data *data);
void	draw_square(t_data *data, int x, int y, int color);
void	drawMap2D(t_data *data);


void draw_rays(t_data *data);

void draw_line(t_data *data, int x0, int y0, int x1, int y1, int color);

#endif