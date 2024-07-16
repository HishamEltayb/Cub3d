/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_map_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:36:26 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/16 08:31:17 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_map2d(t_data *data);
int		is_valid_map_line(char *str, t_data *data);
void	fill_map(char *line, t_data *data, int fd);
void	fill_map(char *line, t_data *data, int fd);
void	file_maps_create(t_data *data, char **line, int fd);

void	file_maps_create(t_data *data, char **line, int fd)
{
	bool	map_pos;

	map_pos = false;
	while (*line && data->valid_line_count >= 6)
	{
		if (map_pos == false)
			skip_empty_line(line, data, fd, MAP);
		map_pos = true;
		if (*line && data->valid_line_count >= 6)
			fill_map(*line, data, fd);
		if (*line)
			free(*line);
		*line = get_next_line(fd);
	}
}

void	create_map2d(t_data *data)
{
	t_list	*temp;
	int		i;

	data->height_y = ft_lstsize(data->map);
	data->map2d = ft_calloc(ft_lstsize(data->map) + 1, sizeof(char *));
	if (!data->map2d)
	{
		ft_putstr_fd("Error\nMalloc failed\n", 2);
		free_data(data);
		exit(1);
	}
	temp = data->map;
	data->width_x = ft_strlen(temp->content);
	i = 0;
	while (temp)
	{
		if (data->width_x <= (int)(ft_strlen(temp->content)))
			data->width_x = ft_strlen(temp->content);
		data->map2d[i] = ft_strdup(temp->content);
		temp = temp->next;
		i++;
	}
}

int	is_valid_map_line(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (is_valid_map_char(str[i], data))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	fill_map(char *line, t_data *data, int fd)
{
	char	*temp;

	temp = ft_strrtrim(line, ' ');
	if (temp && (!*temp || is_valid_map_line(temp, data)))
	{
		ft_putstr_fd("Error\nInvalid Element\n", 2);
		ft_putstr_fd("Note: Check the order of the elements and the map\n", 2);
		(free(line), close(fd));
		free_data(data);
		free(temp);
		exit(1);
	}
	else if (!temp)
	{
		ft_putstr_fd("Error\nInvalid Element\n", 2);
		ft_putstr_fd("Note: Check the order of the elements and the map\n", 2);
		(free(line), close(fd));
		free_data(data);
		exit(1);
	}
	else
		ft_lstadd_back(&data->map, ft_lstnew(temp));
	data->valid_line_count++;
}
