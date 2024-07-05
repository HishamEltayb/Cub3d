/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:24:59 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/05 18:43:26 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free2d(void ***content);
void	free_data(t_data *data);
void	init_data(t_data *data);
void	print_list(t_data *data);
void	elements_handel(t_data *data);
void	fill_elements(char *line, t_data *data, int fd);
void	file_store_data(char *filename, t_data *data);
void	file_pre_check(int ac,char **av, t_data *data);
void	fill_map(char *line, t_data *data, bool *map, int fd);

int	count_comma(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	return (count);
}

void	fill_elements(char *line, t_data *data, int fd)
{
	char	*temp;
	char	**temp_split;

	temp = ft_strtrim(line, " ");
	if (*temp == 'C' || *temp == 'F')
	{
		if (count_comma(temp) != 2)
			(ft_putstr_fd("Error\nInvalid color format\n", 2), 
				free_data(data), free(temp), free(line), close(fd), exit(1));
		temp_split = ft_split(temp, ' ');
		element_add_back(&data->element,
			element_new((void **)temp_split));
		free(temp);
		free(line);
	}
	else
	{
		element_add_back(&data->element,
			element_new((void **)ft_split(temp, ' ')));
		free(temp);
		free(line);
	}
	data->file_size++;	
}

void	fill_map(char *line, t_data *data, bool *map, int fd)
{
	while(!*line && *map == false)
	{
		free(line);
		line = get_next_line(fd);
	}
	*map = true;
	ft_lstadd_back(&data->map, ft_lstnew(line));
	data->file_size++;
}
void	file_store_data(char *filename, t_data *data)
{
	char	*line;
	bool	map;
	int		fd;
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		(ft_putstr_fd("Error\nInvalid file\n", 2), exit(1));
	line = get_next_line(fd);
	map = false;
	while (line)
	{
		if (*line && data->file_size <= 5)
			fill_elements(line, data, fd);
		else if (data->file_size >= 6)
			fill_map(line, data, &map, fd);
		else
			free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	map_check(t_data *data)
{
	t_list	*temp;
	int		i;
	
	temp = data->map;
	while (temp)
	{
		i = 0;
		while (((char *)temp->content)[i])
		{
			i++;
		}
		temp = temp->next;
	}

}

int		ft_strlen2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	elements_handel(t_data *data)
{
	t_element	*temp;
	char		*str;
	char		**temp2d;
	char		**temp2d_comma;
	int			i;
	int			j;

	
	temp = data->element;
	while (temp)
	{
		if (temp->content && (!ft_strncmp(temp->content[0], "C", 1) || !ft_strncmp(temp->content[0], "F", 1)))
			{
				str = ft_strnjoin(ft_strlen2d((char **)temp->content) - 1, ((char **)(&(temp->content[1]))));
				temp2d_comma = ft_split(str, ',');
				temp2d = malloc(sizeof(char *) * (ft_strlen2d(temp2d_comma) + 2));
				if (!temp2d)
					(ft_putstr_fd("Error\nMalloc failed\n", 2), free_data(data), exit(1));
				i = 0;
				j = 0;
				temp2d[j++] = ft_strdup(temp->content[0]);
				while (temp2d_comma[i])
				{
					temp2d[j] = ft_strdup(temp2d_comma[i]);
					i++;
					j++;
				}
				temp2d[j] = NULL;
				free(str);
				free2d((void ***)&temp->content);
				free2d((void ***)&temp2d_comma);
				temp->content = (void **)temp2d;
			}
		temp = temp->next;
	}
}

void	file_pre_check(int ac,char **av, t_data *data)
{
	if (ac != 2)
		(ft_putstr_fd("Error\nInvalid number of arguments\n", 2), exit(1));
	if (ft_strcmp(ft_strrchr(av[1], '.'), ".cub"))
		(ft_putstr_fd("Error\nInvalid file extension\n", 2), exit(1));
	file_store_data(av[1], data);
	elements_handel(data);
	map_check(data);
}

void	print_list(t_data *data)
{
	t_list		*temp_map;
	t_element	*temp_element;
	int			i;
	
	if (!data)
		return ;
	temp_map = data->map;
	temp_element = data->element;
	printf("file_size = %d\n", data->file_size);
	while (temp_element)
	{
		i = 0;
		while (temp_element && temp_element->content[i])
		{
			printf("(%s)", (char *)temp_element->content[i]);
			i++;
		}
		printf("\n");
		temp_element = temp_element->next;
	}
	while (temp_map)
	{
		printf("(%s)\n", (char *)temp_map->content);
		temp_map = temp_map->next;
	}
}
void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->map = NULL;
	data->element = NULL;
	data->file_size = 0;
}

void	free2d(void ***content)
{
	int	i;

	i = 0;
	while (content && *content && (*content)[i])
	{
		free((*content)[i]);
		(*content)[i] = NULL;
		i++;
	}
	free(*content);
	*content = NULL;
}

void	free_data(t_data *data)
{
	ft_lstclear(&data->map, free);
	element_clear(&data->element, free2d);
}