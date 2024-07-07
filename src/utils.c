/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:24:59 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/07 11:24:03 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free2d(void **content);
int		ft_strlen2d(char **str);
void	free_data(t_data *data);
void	init_data(t_data *data);
void	print_data(t_data *data);
void	print_list(t_data *data);
void	print_elements(t_data *data);

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

	while (temp_element && temp_element->content)
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
}

void	print_list(t_data *data)
{
	t_list		*temp_map;

	temp_map = data->map;
	while (temp_map && temp_map->content)
	{
		printf("(%s)\n", (char *)temp_map->content);
		temp_map = temp_map->next;
	}
}
void	print_data(t_data *data)
{

	if (!data || !data->map || !data->element)
		return ;
	printf("file_size = %d\n", data->file_size);
	printf("max len = %d\n", data->max_len);
	print_elements(data);
	print_list(data);

}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->map = NULL;
	data->element = NULL;
	data->file_size = 0;
	data->flags.C = NOT_EXIST;
	data->flags.F = NOT_EXIST;
	data->flags.EA = NOT_EXIST;
	data->flags.WE = NOT_EXIST;
	data->flags.SO = NOT_EXIST;
	data->flags.NO = NOT_EXIST;
	data->map2d = NULL;
	data->max_len = 0;
	
}

void	free2d(void **content)
{
	int	i;

	i = 0;
	while (content && (content)[i])
	{
		free((content)[i]);
		(content)[i] = NULL;
		i++;
	}
	free(content);
	content = NULL;
}

void	free_data(t_data *data)
{
	ft_lstclear(&data->map, free);
	element_clear(&data->element, free2d);
}
