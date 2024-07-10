/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:41:28 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/10 09:13:30 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_image(char *image_path, t_data *data);

void	check_image(char *image_path, t_data *data)
{
	(void)image_path;
	(void)data;
// 	int	i;
// 	int	j;
// 	void	*image;
	
	
// 	data->mlx = mlx_init();
// 	image = mlx_xpm_file_to_image(data->mlx, image_path, &i, &j);
// 	if (!image)
// 	{
// 		ft_putstr_fd("Error\nInvalid image path", 2);
// 		free_data(data);
// 		exit(1);
// 	}
}

int	main(int ac, char **av)
{
	t_data	data;
	
	init_data(&data);
	file_pre_check(ac, av);
	file_store_data(av[1], &data);
	map_check(&data);
	// print_data(&data);
	free_data(&data);
}
