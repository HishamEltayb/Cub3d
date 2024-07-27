/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:36:26 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/27 12:36:32 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_image(t_data *data);
void	parsing(t_data *data, int ac, char **av);
void	file_store_data(char *filename, t_data *data);

void	parsing(t_data *data, int ac, char **av)
{
	init_data(data);
	file_pre_check(ac, av);
	file_store_data(av[1], data);
	map_check(data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "CUB3D");
}

void	create_image(t_data *data)
{
	data->main.img = mlx_new_image(data->mlx, WIDTH,
			HEIGHT);
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
