/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_elements_create.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:36:26 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/08 20:59:44 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_element(char **split);
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

static int	while_loop(char **split, int *i, int *check)
{
	int	j;

	while (split && split[(*i)])
	{
		j = 0;
		while (split[*i][j])
		{
			if (ft_isdigit(split[*i][j]) || split[*i][j] == ',')
				j++;
			else
				return (0);
		}
		(*i)++;
		(*check)++;
	}
	return (1);
}

int	is_element(char **split)
{
	int	i;
	int	check;

	check = 0;
	i = 1;
	if (!ft_strcmp(split[0], "NO") || !ft_strcmp(split[0], "SO")
		|| !ft_strcmp(split[0], "WE") || !ft_strcmp(split[0], "EA"))
		return (1);
	else if (!ft_strcmp(split[0], "F") || !ft_strcmp(split[0], "C"))
	{
		if (!while_loop(split, &i, &check) || check > 3)
			return (0);
	}
	return (1);
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
		(free(line), close(fd));
		free_data(data);
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
	print_data(data);
	floor_ceiling_re_arrange(data, *line);
	file_check_elements(data, *line);
	if (!*line)
	{
		ft_putstr_fd("Error\nEmpty map\n", 2);
		(free_data(data), close(fd), exit(1));
	}
}
