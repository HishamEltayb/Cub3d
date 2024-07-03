/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:24:59 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/03 12:23:38 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free2d(void **content);
void	free_data(t_data *data);
void	init_data(t_data *data);
void	print_list(t_data *data);
void	elements_check(t_data *data);
void	file_store_data(int fd, t_data *data);
void	file_pre_check(int ac,char **av, t_data *data);

void	file_store_data(int fd, t_data *data)
{
	char	*line;
	char	*temp;
	bool	map;
	
	line = get_next_line(fd);
	temp = NULL;
	map = false;
	while (line)
	{
		if (*line && data->file_size <= 5)
		{
			temp = ft_strtrim(line, " ");
			if (*temp == 'C' || *temp == 'F')
			{
				element_add_back(&data->element,
					element_new((void **)ft_split(temp, ',')));
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
		else if (data->file_size >= 6)
		{
			while(!*line && map == false)
			{
				free(line);
				line = get_next_line(fd);
			}
			map = true;
			ft_lstadd_back(&data->map, ft_lstnew(line));
			data->file_size++;
		}
		else
			free(line);
		line = get_next_line(fd);
	}
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

void	elements_check(t_data *data)
{
	t_element	*temp;
	char		*str;
	char		**temp2d;

	temp = data->element;
	while (temp)
	{
		if (!ft_strcmp(temp->content[0], "NO") || !ft_strcmp(temp->content[0], "SO")
			|| !ft_strcmp(temp->content[0], "WE") || !ft_strcmp(temp->content[0], "EA"))
				;
		else if (!ft_strncmp(temp->content[0], "C", 1) || !ft_strncmp(temp->content[0], "F", 1))
			{
				str = ft_strnjoin(ft_strlen2d((char **)temp->content), (char **)(temp->content));
				temp2d = ft_split(str, ' ');
				free(str);
				free2d((void **)temp->content);
				temp->content = (void **)temp2d;
			}
		else
			(ft_putstr_fd("Error\nInvalid element\n", 2), free_data(data), exit(1));
		temp = temp->next;
	}
}

void	file_pre_check(int ac,char **av, t_data *data)
{
	int fd;
	
	if (ac != 2)
		(ft_putstr_fd("Error\nInvalid number of arguments\n", 2), exit(1));
	if (ft_strcmp(ft_strrchr(av[1], '.'), ".cub"))
		(ft_putstr_fd("Error\nInvalid file extension\n", 2), exit(1));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		(ft_putstr_fd("Error\nInvalid file\n", 2), exit(1));
	close(fd);
	fd = open(av[1], O_RDONLY);
	file_store_data(fd, data);
	close(fd);
	elements_check(data);
	map_check(data);
}

void	print_list(t_data *data)
{
	t_list		*temp_map;
	t_element	*temp_element;
	int			i;
	
	temp_map = data->map;
	temp_element = data->element;
	printf("file_size = %d\n", data->file_size);
	while (temp_element)
	{
		i = 0;
		while (temp_element->content[i])
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

void	free2d(void **content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		free(content[i]);
		i++;
	}
	free(content);
}

void	free_data(t_data *data)
{
	ft_lstclear(&data->map, free);
	element_clear(&data->element, free2d);
}