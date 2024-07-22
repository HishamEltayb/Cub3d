/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:24:59 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/22 10:13:00 by heltayb          ###   ########.fr       */
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
	data->player.dx = cos(RAD(data->player.angle));
	data->player.dy = -sin(RAD(data->player.angle));
}

void	init_data(t_data *data)
{
	init_flags(data);
	init_player(data);
	init_raycast(data);
	init_image(&data->main);
	init_image(&data->imageEA);
	init_image(&data->imageWE);
	init_image(&data->imageSO);
	init_image(&data->imageNO);
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
	if (data->imageEA.img)
		mlx_destroy_image(data->mlx, data->imageEA.img);
	if (data->imageWE.img)
		mlx_destroy_image(data->mlx, data->imageWE.img);
	if (data->imageSO.img)
		mlx_destroy_image(data->mlx, data->imageSO.img);
	if (data->imageNO.img)
		mlx_destroy_image(data->mlx, data->imageNO.img);
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
