/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:52:10 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/21 10:51:05 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_draw(t_data *data)
{
	install_background_image(data);
	data->player.dx = cos(RAD(data->player.angle));
	data->player.dy = -sin(RAD(data->player.angle));
}

int	main(int ac, char **av)
{
	t_data	data;
	
	parsing(&data, ac, av);
	printf("data->width_x = %d\n", data.width_x);
	init_draw(&data);
	print_data(&data);
	mlx_loop_hook(data.mlx, display, &data);
	mlx_hook(data.win, ON_KEYDOWN, 1L << 0, key_hook, &data);
	mlx_hook(data.win, ON_DESTROY, 1L << 3, exit_mouse, &data);
	mlx_loop(data.mlx);
	free_data(&data);
}
