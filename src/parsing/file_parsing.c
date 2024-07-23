/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:36:26 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/23 16:28:31 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_image(t_data *data);
void	parsing(t_data *data, int ac, char **av);
void	file_store_data(char *filename, t_data *data);

void	parsing(t_data *data, int ac, char **av)
{
	int	map_x;
	int	map_y;

	init_data(data);
	file_pre_check(ac, av);
	file_store_data(av[1], data);
	map_check(data);
	map_x = data->pixel * data->map_x;
	map_y = data->pixel * data->map_y;
	data->win = mlx_new_window(data->mlx, map_x, map_y, "CUB3D");
}

void	draw_image(t_data *data)
{
	data->main.img = mlx_new_image(data->mlx, data->pixel * data->map_x,
			data->pixel * data->map_y);
	data->main.addr = mlx_get_data_addr(data->main.img,
			&data->main.bits_per_pixel,
			&data->main.line_length,
			&data->main.endian);
}

void	file_store_data(char *filename, t_data *data)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	file_elements_create(data, &line, fd);
	file_maps_create(data, &line, fd);
	create_map2d(data);
	resize_map(data);
	close(fd);
}
