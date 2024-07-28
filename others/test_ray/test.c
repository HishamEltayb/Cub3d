/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:40:47 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/28 17:28:31 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>

# define WIDTH 1080
# define HEIGHT 1080

#define MAPX 3      // map width
#define MAPY 3      // map height
// #define MAPS (135)     // map cube size

#define deg_to_rad(x) (x * M_PI / 180.0)

#define data->minimap_x 200      // map width
#define data->minimap_y 200      // map height
#define MINIMAP_SIZE 40000     // map cube size


//start_colors
# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF
# define YELLOW	0xFFFF00
# define WHITE	0xFFFFFF
# define BLACK	0x000000
# define GRAY	0x808080
# define BROWN	0xA52A2A
//end_colors


int map2d[MAPY][MAPX] = { // the map array. Edit to change level but keep the outer walls
    {1,1,1},
    {1,0,1},
    {1,1,1},
};

typedef struct s_img
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_img;

typedef struct s_data
{
	void				*mlx;
	void				*win;
	t_img				main;

	//map
	int					map_y;
	int					map_x;
	int					map_size;
	int					pixel_x;
	int					pixel_y;
}		t_data;

void	my_mlx_pixel_put(t_data *data, t_img *image, int arr[2], int color);
void	draw_square(t_data *data, int x, int y, int color);
void	draw_map2d(t_data *data);
int	key_hook(int keycode, t_data *data);

void	init_data(t_data *data)
{
	data->map_y = MAPY;
	data->map_x = MAPX;
	data->pixel_x = data->minimap_x / MAPX;
	data->pixel_y = data->minimap_y / MAPY;
}
int main()
{
	t_data	data;
	init_data(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "test");
	data.main.img = mlx_new_image(data.mlx, data->minimap_x, data->minimap_y);
	data.main.addr = mlx_get_data_addr(data.main.img, &data.main.bits_per_pixel, &data.main.line_length, &data.main.endian);
	for(int i = 0; i < data->minimap_y; i++)
	{
		for(int j = 0; j < data->minimap_x; j++)
		{
			my_mlx_pixel_put(&data, &data.main, (int[2]){j, i}, GREEN);
		}
	}
	draw_map2d(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.main.img, 0, 0);
	mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);	
}


int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		(printf("exited\n"), exit(0));
	return (0);
}

void	draw_map2d(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_y)
	{
		x = 0;
		while (x < data->map_x)
		{
			if (map2d[y][x] == 1)
				draw_square(data, x * data->pixel_x, y * data->pixel_y, WHITE);
			else if (map2d[y][x] == 0)
				draw_square(data, x * data->pixel_x, y * data->pixel_y, BLUE);
			x++;
		}
		y++;
	}
}

void	draw_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;
	int arr[2];

	i = 0;
	printf("x = %d, y = %d\n", x, y);
	while (i < data->pixel_y - 1)
	{
		j = 0;
		while (j < data->pixel_x - 1)
		{
			arr[0] = x + j;
			arr[1] = y + i;
			my_mlx_pixel_put(data, &data->main, arr, color);
			j++;
		}
		i++;
	}
	// while (i < 50)
	// {
	// 	j = 0;
	// 	while (j < 50)
	// 	{
	// 		arr[0] = x + j;
	// 		arr[1] = y + i;
	// 		my_mlx_pixel_put(data, &data->main, arr, color);
	// 		j++;
	// 	}
	// 	i++;
	// }
}


void	my_mlx_pixel_put(t_data *data, t_img *image, int arr[2], int color)
{
	char	*dst;

	// if (arr[0] < 0 || arr[0] >= data->map_x *  data->pixel || arr[1] < 0 || arr[1] >= data->map_y
	// 	* data->pixel)
	// 	return ;
	(void)data;
	dst = image->addr + (arr[1] * image->line_length + arr[0]
			* (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}