/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:17:36 by heltayb           #+#    #+#             */
/*   Updated: 2024/08/03 14:53:39 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		exit_mouse(t_data *data);
void	my_mlx_pixel_put(t_data *data, t_img *image, int arr[2], int color);

int	exit_mouse(t_data *data)
{
	free_data(data);
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, t_img *image, int arr[2], int color)
{
	char	*dst;

	if (arr[0] < 0 || arr[0] >= WIDTH || arr[1] < 0 || arr[1] >= HEIGHT)
		return ;
	(void)data;
	dst = image->addr + (arr[1] * image->line_length + arr[0]
			* (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
