/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_data_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:36:26 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/07 20:22:57 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		file_store_data(char *filename, t_data *data);
void		fill_elements(char *line, t_data *data, int fd);
void		fill_map(char *line, t_data *data, int fd);
void		skip_empty_line(char **line, t_data *data, int fd);
int			is_element(char *str);
static void	file_elements_create(t_data *data, char **line, int fd);
static void	file_maps_create(t_data *data, char **line, int fd);

void	skip_empty_line(char **line, t_data *data, int fd)
{
	while (line && *line && !**line)
	{
		free(*line);
		*line = NULL;
		*line = get_next_line(fd);
	}
	if (!line || !*line)
	{
		ft_putstr_fd("Error\nEmpty map4\n", 2);
		(free_data(data), close(fd), exit(1));
	}
}
static void	file_elements_create(t_data *data, char **line, int fd)
{
	while (*line && data->file_size < 6)
	{
		skip_empty_line(line, data, fd);
		if (*line && data->file_size <= 5)
			fill_elements(*line, data, fd);
		if (line)
			free(*line);
		*line = get_next_line(fd);
	}
	floor_ceiling_re_arrange(data, *line);
	file_check_elements(data, *line);
	if (!*line)
	{
		ft_putstr_fd("Error\nEmpty map3\n", 2);
		(free_data(data), close(fd), exit(1));
	}
}
static void	file_maps_create(t_data *data, char **line, int fd)
{
	bool	map_pos;

	map_pos = false;
	
	while (*line && data->file_size >= 6)
	{
		if (map_pos == false)
			skip_empty_line(line, data, fd);
		map_pos = true;
		if (*line && data->file_size >= 6)
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

	data->map2d = ft_calloc(ft_lstsize(data->map) + 1, sizeof(char *));
	if (!data->map2d)
	{
		ft_putstr_fd("Error\nMalloc failed\n", 2);
		free_data(data);
		exit(1);
	}
	temp = data->map;
	i = 0;
	while (temp)
	{
		data->map2d[i] = ft_strdup(temp->content);
		temp = temp->next;
		i++;
	}
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
	close(fd);
}
int	is_element(char *str)
{
	if (!ft_strcmp(str, "F") || !ft_strcmp(str, "C")
		|| !ft_strcmp(str, "NO") || !ft_strcmp(str, "SO")
		|| !ft_strcmp(str, "WE") || !ft_strcmp(str, "EA"))
			return (1);
	return (0);
}
void	fill_elements(char *line, t_data *data, int fd)
{
	char	*temp;
	char	**temp_split;

	temp = ft_strtrim(line, " ");
	if (!temp)
	{
		ft_putstr_fd("Error\nInvalid Element1\n", 2);
		ft_putstr_fd("Note: Check the order of the elements and the map\n", 2);
		(free(line), close(fd));
		free_data(data);
		exit(1);
	}
	temp_split = ft_split(temp, ' ');
	free(temp);
	if (is_element(temp_split[0]))
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

static int is_valid_map_line(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (!is_valid_map_char(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	fill_map(char *line, t_data *data, int fd)
{
	char *temp;

	temp = ft_strrtrim(line, ' ');
	if (temp && (!*temp || is_valid_map_line(temp)))
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
	data->file_size++;
}
