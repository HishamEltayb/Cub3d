/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:24:59 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/23 16:38:07 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_mlx(t_data *data);
void	free2d(void **content);
void	init_data(t_data *data);
int		free_data(t_data *data);
void	init_draw(t_data *data);

void	init_draw(t_data *data)
{
	draw_image(data);
	data->player.dx = cos(deg_to_rad(data->player.angle));
	data->player.dy = -sin(deg_to_rad(data->player.angle));
}

void	init_data(t_data *data)
{
	init_flags(data);
	init_player(data);
	init_image(&data->main);
	init_image(&data->image_ea);
	init_image(&data->image_we);
	init_image(&data->image_so);
	init_image(&data->image_no);
	init_parsing(data);
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
	if (content)
		free(content);
	content = NULL;
}

void	free_mlx(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->image_ea.img)
		mlx_destroy_image(data->mlx, data->image_ea.img);
	if (data->image_we.img)
		mlx_destroy_image(data->mlx, data->image_we.img);
	if (data->image_so.img)
		mlx_destroy_image(data->mlx, data->image_so.img);
	if (data->image_no.img)
		mlx_destroy_image(data->mlx, data->image_no.img);
#ifdef Linux
	mlx_destroy_display(data->mlx);
#endif
	if (data->mlx)
		free(data->mlx);
}

int	free_data(t_data *data)
{
	int	i;

	i = 0;
	free_mlx(data);
	free2d((void **)data->map2d);
	ft_lstclear(&data->map, free);
	element_clear(&data->element, free2d);
	while (i < 100)
		close(i++);
	return (0);
}
