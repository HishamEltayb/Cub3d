/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:41:28 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/07 12:32:25 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int 	check_helper(t_data *data, char *s1);
void	file_check_elements(t_data *data, char *line);
int 	check_helper2(int flag, char *s1, char *s2);


void	check_image(char *image_path, t_data *data)
{
	// int	i;
	// int	j;
	
	(void)data;
	(void)image_path;
	// data->mlx = mlx_init();
	// image = mlx_xpm_file_to_image(data->mlx, image_path, &i, &j);
	// if (!image)
	// {
	// 	ft_putstr_fd("Error\nInvalid image path", 2);
	// 	free_data(data);
	// 	exit(1);
	// }
}


int	main(int ac, char **av)
{
	t_data	data;

	init_data(&data);
	file_pre_check(ac, av);
	file_store_data(av[1], &data);
	print_data(&data);
	free_data(&data);
	// map_check(data);
	// file_validaty_check(file_size, )
}
