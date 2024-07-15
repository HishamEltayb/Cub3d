/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_data_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:36:26 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/15 12:01:59 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	file_store_data(char *filename, t_data *data);

void	file_store_data(char *filename, t_data *data)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	file_elements_create(data, &line, fd);
	file_maps_create(data, &line, fd);
	create_map2d(data);
	close(fd);
}
