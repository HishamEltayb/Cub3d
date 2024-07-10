/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_elements_create.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:36:26 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/10 10:00:13 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_elements(char *line, t_data *data, int fd);
void	skip_empty_line(char **line, t_data *data, int fd, int flag);
void	file_elements_create(t_data *data, char **line, int fd);

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
	if (is_element(temp_split))
		element_add_back(&data->element, element_new((void **)temp_split));
	else
	{
		ft_putstr_fd("Error\nInvalid Element\n", 2);
		ft_putstr_fd("Note: Check the order of the elements and the map\n", 2);
		(free(line), close(fd));
		(free2d((void **)temp_split), free_data(data));
		exit(1);
	}
	data->file_size++;
}

void	file_elements_create(t_data *data, char **line, int fd)
{
	while (*line && data->file_size < 6)
	{
		skip_empty_line(line, data, fd, ELEMENT);
		if (*line && data->file_size <= 5)
			fill_elements(*line, data, fd);
		if (line)
			free(*line);
		*line = get_next_line(fd);
	}
	floor_ceiling_re_arrange(data, *line, fd);
	file_check_elements(data, *line, fd);
	if (!*line)
	{
		ft_putstr_fd("Error\nEmpty map\n", 2);
		(free_data(data), close(fd), exit(1));
	}
}
