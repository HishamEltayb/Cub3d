/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 21:44:40 by heltayb           #+#    #+#             */
/*   Updated: 2024/08/04 22:12:28 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		free_data(t_data *data);
void	free2d(void **content);
void	free_mlx(t_data *data);
void	error_free_exit(t_data *data, char *msg);

void	error_free_exit(t_data *data, char *msg)
{
	int	i;

	i = 0;
	ft_putstr_fd(msg, 2);
	if (data)
		free_data(data);
	while (i < 100)
		close(i++);
	exit(1);
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

#ifdef Linux

void	free_mlx(t_data *data)
{
	if (data->image_ea.img)
		mlx_destroy_image(data->mlx, data->image_ea.img);
	if (data->image_we.img)
		mlx_destroy_image(data->mlx, data->image_we.img);
	if (data->image_so.img)
		mlx_destroy_image(data->mlx, data->image_so.img);
	if (data->image_no.img)
		mlx_destroy_image(data->mlx, data->image_no.img);
	if (data->main.img)
		mlx_destroy_image(data->mlx, data->main.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

#else

void	free_mlx(t_data *data)
{
	if (data->image_ea.img)
		mlx_destroy_image(data->mlx, data->image_ea.img);
	if (data->image_we.img)
		mlx_destroy_image(data->mlx, data->image_we.img);
	if (data->image_so.img)
		mlx_destroy_image(data->mlx, data->image_so.img);
	if (data->image_no.img)
		mlx_destroy_image(data->mlx, data->image_no.img);
	if (data->main.img)
		mlx_destroy_image(data->mlx, data->main.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free(data->mlx);
}

#endif