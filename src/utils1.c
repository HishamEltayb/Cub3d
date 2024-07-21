 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:24:59 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/19 15:49:53 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_2d(t_data *data);
int		ft_strlen2d(char **str);
void	print_data(t_data *data);
void	print_list(t_data *data);
void	print_elements(t_data *data);
void 	print_2d_int(t_data *data);

int	ft_strlen2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_elements(t_data *data)
{
	t_element	*temp_element;
	int			i;

	temp_element = data->element;
	while (data->element && data->element->content)
	{
		i = 0;
		while (data->element && data->element->content[i])
		{
			printf("(%s)", (char *)data->element->content[i]);
			i++;
		}
		printf("\n");
		data->element = data->element->next;
	}
	data->element = temp_element;
}

void	print_list(t_data *data)
{
	t_list		*temp_map;

	temp_map = data->map;
	while (data->map && data->map->content)
	{
		printf("(%s)\n", (char *)data->map->content);
		data->map = data->map->next;
	}
	data->map = temp_map;
}

void	print_2d(t_data *data)
{
	int	i;

	i = 0;
	while (data->map2d && data->map2d[i])
	{
		printf("(%s)\n", data->map2d[i]);
		i++;
	}
}

void 	print_2d_int(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_num && i < data->map_size)
	{
		printf("%d", data->map_num[i]);
		i++;
		if (i % data->width_x == 0)
			printf("\n");
	}
}

void	print_data(t_data *data)
{
	if (!data || !data->map || !data->element)
		return ;
	printf("valid_line_count = %d\n", data->valid_line_count);
	printf("data->width_x = %d\n", data->width_x);
	printf("data->height_y = %d\n", data->height_y);
	printf("data->map_size = %d\n", data->map_size);
	printf("data->player.x = %f\n", data->player.x);
	printf("data->player.y = %f\n", data->player.y);
	printf("data->player.dir = %c\n", data->player.dir);
	printf("data->ceiling_color = %d\n", data->ceiling_color);
	printf("data->floor_color = %d\n", data->floor_color);
	printf("data->pixel = %d\n", data->pixel);
	printf("printing elements\n");
	print_elements(data);
	printf("\n");
	printf("printing map as list\n");
	print_list(data);
	printf("\n");
	printf("printing map as 2d\n");
	print_2d(data);
	printf("printing map as integers\n");
	print_2d_int(data);
}
