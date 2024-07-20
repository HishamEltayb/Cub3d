/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:24:59 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/16 20:13:10 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free2d(void **content);
void	init_data(t_data *data);
int		free_data(t_data *data);

void	init_data(t_data *data)
{
	data->win = NULL;
	data->mlx = NULL;
	data->map = NULL;
	data->element = NULL;
	data->valid_line_count = 0;
	data->flags.C = NOT_EXIST;
	data->flags.F = NOT_EXIST;
	data->flags.EA = NOT_EXIST;
	data->flags.WE = NOT_EXIST;
	data->flags.SO = NOT_EXIST;
	data->flags.NO = NOT_EXIST;
	data->map2d = NULL;
	data->flags.PlayerN = NOT_EXIST;
	data->flags.PlayerS = NOT_EXIST;
	data->flags.PlayerW = NOT_EXIST;
	data->flags.PlayerE = NOT_EXIST;
	data->player.is_exist = NOT_EXIST;
	data->player.x = 0;
	data->player.y = 0;
	data->player.dir = 0;
	data->image.imageEA = NULL;
	data->image.imageWE = NULL;
	data->image.imageSO = NULL;
	data->image.imageNO = NULL;
	data->image.background = NULL;
	(data->image.background) = malloc(sizeof(t_img));
	(data->image.background)->img = NULL;
	data->image.background->addr = NULL;
	data->image.background->bits_per_pixel = 0;
	data->image.player = NULL;
	(data->image.player) = malloc(sizeof(t_img));
	data->image.floor = NULL;
	(data->image.floor) = malloc(sizeof(t_img));
	data->image.floor->img = NULL;
	data->image.floor->addr = NULL;
	data->image.floor->bits_per_pixel = 0;
	(data->image.space) = malloc(sizeof(t_img));
	data->image.space->img = NULL;
	data->image.space->addr = NULL;
	data->image.space->bits_per_pixel = 0;
	data->image.player->img = NULL;
	data->image.player->addr = NULL;
	data->image.player->bits_per_pixel = 0;
	
	data->pixel = 64;
	data->height_y = 0;
	data->width_x = 0;
	data->floor_color = 0;
	data->ceiling_color = 0;
	data->player.angle = 0;
	data->player.dx = 0;
	data->player.dy = 0;
	
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
	if (data->image.imageEA)
		mlx_destroy_image(data->mlx, data->image.imageEA);
	if (data->image.imageWE)
		mlx_destroy_image(data->mlx, data->image.imageWE);
	if (data->image.imageSO)
		mlx_destroy_image(data->mlx, data->image.imageSO);
	if (data->image.imageNO)
		mlx_destroy_image(data->mlx, data->image.imageNO);
# ifdef Linux
	mlx_destroy_display(data->mlx);
# endif
	if (data->mlx)
 		free(data->mlx);
}
int		free_data(t_data *data)
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


