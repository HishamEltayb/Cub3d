/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:24:59 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/16 08:27:03 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strlen2d(char **str);
void	print_data(t_data *data);
void	print_list(t_data *data);
void	print_elements(t_data *data);

int	ft_strlen2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_elements(t_data *data)
{
	t_element	*temp_element;
	int			i;

	temp_element = data->element;
	while (data->element && data->element->content)
	{
		i = 0;
		while (data->element && data->element->content[i])
		{
			printf("(%s)", (char *)data->element->content[i]);
			i++;
		}
		printf("\n");
		data->element = data->element->next;
	}
	data->element = temp_element;
}

void	print_list(t_data *data)
{
	t_list		*temp_map;

	temp_map = data->map;
	while (data->map && data->map->content)
	{
		printf("(%s)\n", (char *)data->map->content);
		data->map = data->map->next;
	}
	data->map = temp_map;
}

void	print_2d(t_data *data)
{
	int	i;

	i = 0;
	while (data->map2d && data->map2d[i])
	{
		printf("(%s)\n", data->map2d[i]);
		i++;
	}
}

void	print_data(t_data *data)
{
	if (!data || !data->map || !data->element)
		return ;
	printf("valid_line_count = %d\n", data->valid_line_count);
	printf("data->width_x = %d\n", data->width_x);
	printf("data->height_y = %d\n", data->height_y);
	printf("data->player.x = %f\n", data->player.x);
	printf("data->player.y = %f\n", data->player.y);
	printf("data->player.dir = %c\n", data->player.dir);
	printf("data->ceiling_color = %d\n", data->ceiling_color);
	printf("data->floor_color = %d\n", data->floor_color);
	printf("data->pixel = %d\n", data->pixel);
	printf("printing elements\n");
	print_elements(data);
	printf("\n");
	printf("printing map as list\n");
	print_list(data);
	printf("\n");
	printf("printing map as 2d\n");
	print_2d(data);
}

// static void    mlx_put_pixel_to_image(void *img, int x, int y, int color)
// {
// 	char	*data;
// 	int		bpp;
// 	int		size_line;
// 	int		endian;
// 	int		index;

// 	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
// 	index = (((int)y) * size_line) + (((int)x) * (bpp / 8));
// 	data[index] = color & 0xFF;
// 	data[index + 1] = (color >> 8) & 0xFF;
// 	data[index + 2] = (color >> 16) & 0xFF;
// }



void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
		
static void install_background_image(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx, 1920, 1080);
	if (!data->img.img)
		error_free_exit(data, "Error\nFailed to create main image\n");
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	for (int i = 0; i < 1920; i++)
		for (int j = 0; j < 1080; j++)
			my_mlx_pixel_put(&data->img, i, j, 0x00FF0000);
}
// static void install_wall_image(t_data *data)
// {
// 	data->img.img = mlx_new_image(data->mlx, 1920, 1080);
// 	if (!data->img.img)
// 		error_free_exit(data, "Error\nFailed to create main image\n");
// 	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
// 	for (int i = 0; i < 1920; i++)
// 		for (int j = 0; j < 1080; j++)
// 			my_mlx_pixel_put(&data->img, i, j, 0x00FF0000);
// }
// void install_player_image(t_data *data)
// {
// 	int width = 0;
// 	int height = 0;
	
// 	data->image.player = mlx_new_image(data->mlx, 10, 10);
// 	if (!data->image.player)
// 		error_free_exit(data, "Error\nFailed to create main image\n");
// 	while (width < 10)
// 	{
// 		height = 0;
// 		while (height < 10)
// 		{
// 			mlx_put_pixel_to_image(data->image.player, height, width, Yellow);
// 			height++;
// 		}
// 		width++;
// 	}
// }			
void	parsing(t_data *data, int ac, char **av)
{
	init_data(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1024 , 512, "CUB3D");
	file_pre_check(ac, av);
	file_store_data(av[1], data);
	map_check(data);
	print_data(data);	
	// install_player_image(data);
	install_background_image(data);
}