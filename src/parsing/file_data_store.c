/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_data_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:36:26 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/07 11:05:29 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	file_store_data(char *filename, t_data *data);
void	fill_elements(char *line, t_data *data, int fd, bool *element);
void	fill_map(char *line, t_data *data, bool *map, int fd);

void	file_store_data(char *filename, t_data *data)
{
	char	*line;
	bool	map_check_pos;
	bool	element_pos;
	int		fd;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	map_check_pos = false;
	element_pos = false;
	while (line)
	{
		if (line && data->file_size <= 5)
			fill_elements(line, data, fd, &element_pos);
		else if (line && data->file_size >= 6)
			fill_map(line, data, &map_check_pos, fd);
		line = get_next_line(fd);
	}
	floor_ceiling_re_arrange(data);
	close(fd);
}

void	fill_elements(char *line, t_data *data, int fd, bool *element)
{
	char	*temp;
	char	**temp_split;

	while (line && !*line)
	{
		printf("line: (%d)\n", *line);
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
	{
		ft_putstr_fd("Error\nEmpty map4\n", 2);
		(free_data(data), close(fd), exit(1));
	}
	printf("line: (%s)\n", line);
	temp = ft_strtrim(line, " ");
	printf("temp: (%s)\n", temp);
	temp_split = ft_split(temp, ' ');
	free(temp);
	if (!ft_strcmp(temp_split[0], "F") || !ft_strcmp(temp_split[0], "C")
		|| !ft_strcmp(temp_split[0], "NO") || !ft_strcmp(temp_split[0], "SO")
		|| !ft_strcmp(temp_split[0], "WE") || !ft_strcmp(temp_split[0], "EA"))
		element_add_back(&data->element, element_new((void **)temp_split));
	else
	{
		ft_putstr_fd("Error\nInvalid Element3\n", 2);
		ft_putstr_fd("Note: Check the order of the elements and the map\n", 2);
		(free(line), close(fd));
		(free2d((void **)temp_split), free_data(data));
		exit(1);
	}
	data->file_size++;
}

void	fill_map(char *line, t_data *data, bool *map, int fd)
{

	while (line && !*line && *map == false)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
	{
		ft_putstr_fd("Error\nEmpty map4\n", 2);
		(free_data(data), close(fd), exit(1));
	}
	else
	{
		*map = true;
		ft_lstadd_back(&data->map, ft_lstnew(line));
	}
	data->file_size++;
}
