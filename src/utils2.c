/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:24:59 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/07 20:49:55 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free2d(void **content);
void	init_data(t_data *data);
void	free_data(t_data *data);

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
	data->max_len = 0;
	data->map2d = NULL;
	data->is_valid = 0;
	
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
	free2d((void **)data->map2d);
}
