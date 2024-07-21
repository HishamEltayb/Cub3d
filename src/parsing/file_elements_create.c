/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_elements_create.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:36:26 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/21 21:08:08 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		create_rgb(t_data *data, char **str);
void	fill_elements(char *line, t_data *data, int fd);
void	file_elements_create(t_data *data, char **line, int fd);
void	skip_empty_line(char **line, t_data *data, int fd, int flag);

void	skip_empty_line(char **line, t_data *data, int fd, int flag)
{
	while (line && *line && !**line)
	{
		free(*line);
		*line = NULL;
		*line = get_next_line(fd);
	}
	if (!line || !*line)
	{
		if (flag == 1)
			ft_putstr_fd("Error\nEmpty elements\n", 2);
		else if (flag == 2)
			ft_putstr_fd("Error\nEmpty map\n", 2);
		if (line)
			free(*line);
		(free_data(data), close(fd), exit(1));
	}
}

void	fill_elements(char *line, t_data *data, int fd)
{
	char	*temp;
	char	**temp_split;

	temp = ft_strtrim(line, " ");
	if (!temp)
	{
		ft_putstr_fd("Error\nInvalid Elements\n", 2);
		ft_putstr_fd("Note: Check the order of the elements and the map\n", 2);
		free_data(data);
		(free(line), close(fd));
		exit(1);
	}
	temp_split = ft_split(temp, ' ');
	free(temp);
	if (is_element(temp_split, data))
		element_add_back(&data->element, element_new((void **)temp_split));
	else
	{
		ft_putstr_fd("Error\nInvalid Element\n", 2);
		ft_putstr_fd("Note: Check the order of the elements and the map\n", 2);
		(free(line), close(fd));
		(free2d((void **)temp_split), free_data(data));
		exit(1);
	}
	data->valid_line_count++;
}

void	file_elements_create(t_data *data, char **line, int fd)
{
	while (*line && data->valid_line_count < 6)
	{
		skip_empty_line(line, data, fd, ELEMENT);
		if (*line && data->valid_line_count <= 5)
			fill_elements(*line, data, fd);
		if (*line)
			free(*line);
		*line = get_next_line(fd);
	}
	floor_ceiling_re_arrange(data, *line, fd);
	file_check_elements(data, *line);
	if (!*line)
		(free(*line), error_free_exit(data, "Error\nEmpty map\n"));
}

int	create_rgb(t_data *data, char **str)
{
	int	r;
	int	g;
	int	b;

	if (!str || !str[1] || !str[2] || !str[3])
		return (1);
	r = ft_mini_atoi(str[1]);
	g = ft_mini_atoi(str[2]);
	b = ft_mini_atoi(str[3]);
	if (r == -1 || g == -1 || b == -1)
		return (1);
	if (!ft_strcmp(str[0], "F"))
		data->floor_color = (r << 16 | g << 8 | b);
	else if (!ft_strcmp(str[0], "C"))
		data->ceiling_color = (r << 16 | g << 8 | b);
	else
		return (1);
	return (0);
}
