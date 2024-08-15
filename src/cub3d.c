/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:52:10 by heltayb           #+#    #+#             */
/*   Updated: 2024/08/04 14:01:05 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	parsing(&data, ac, av);
	init_draw(&data);
	mlx_hook(data.win, ON_KEYDOWN, 1L << 0, key_hook, &data);
	mlx_hook(data.win, ON_DESTROY, 1L << 3, exit_mouse, &data);
	mlx_loop(data.mlx);
	free_data(&data);
}
