/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:24:59 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/15 13:55:50 by heltayb          ###   ########.fr       */
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
	printf("file_size = %d\n", data->file_size);
	printf("max len = %d\n", data->max_len);
	printf("printing elements\n");
	print_elements(data);
	printf("\n");
	printf("printing map as list\n");
	print_list(data);
	printf("\n");
	printf("printing map as 2d\n");
	print_2d(data);
}

static void    mlx_put_pixel_to_image(void *img, int x, int y, int color)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		index;

	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	index = (((int)y) * size_line) + (((int)x) * (bpp / 8));
	data[index] = color & 0xFF;
	data[index + 1] = (color >> 8) & 0xFF;
	data[index + 2] = (color >> 16) & 0xFF;
}

static void install_background_image(t_data *data)
{
	int width = 0;
	int height = 0;
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->image.background = mlx_new_image(data->mlx, 1024, 512);
	if (!data->image.background)
		error_free_exit(data, "Error\nFailed to create main image\n");
	while (data->map2d[x])
	{
		while (data->map2d[x][y])
		{
			while (width <= 512)
			{
				height = 0;
				while (height <= 1024)
				{
					if (data->map2d[x][y] == '1')
					{
						if (!(width % 64 == 0) && !(height % 64 == 0))
							mlx_put_pixel_to_image(data->image.background, height, width, Brown);
					}
					else if (data->map2d[x][y] == '0')
					{
						if (!(width % 64 == 0) && !(height % 64 == 0))
							mlx_put_pixel_to_image(data->image.background, height, width, Gray);
					}
					else if (data->map2d[x][y] == 'E')
					{
						if (!(width % 64 == 0) && !(height % 64 == 0))
							mlx_put_pixel_to_image(data->image.background, height, width, Red);
					}
					else if (data->map2d[x][y] == 'N')
					{
						if (!(width % 64 == 0) && !(height % 64 == 0))
							mlx_put_pixel_to_image(data->image.background, height, width, Blue);
					}
					else if (data->map2d[x][y] == 'W')
					{
						if (!(width % 64 == 0) && !(height % 64 == 0))
							mlx_put_pixel_to_image(data->image.background, height, width, Green);
					}
					else if (data->map2d[x][y] == 'S')
					{
						if (!(width % 64 == 0) && !(height % 64 == 0))
							mlx_put_pixel_to_image(data->image.background, height, width, Yellow);
					}
					height++;
				}
				width++;
			}
			y++;
		}
		x++;
	}
}
			
void install_player_image(t_data *data)
{
	int width = 0;
	int height = 0;
	
	data->image.player = mlx_new_image(data->mlx, 10, 10);
	if (!data->image.player)
		error_free_exit(data, "Error\nFailed to create main image\n");
	while (width < 10)
	{
		height = 0;
		while (height < 10)
		{
			mlx_put_pixel_to_image(data->image.player, height, width, Yellow);
			height++;
		}
		width++;
	}
}			
void	parsing(t_data *data, int ac, char **av)
{
	init_data(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1024 , 512, "CUB3D");
	install_player_image(data);
	install_background_image(data);
	file_pre_check(ac, av);
	file_store_data(av[1], data);
	map_check(data);	
}