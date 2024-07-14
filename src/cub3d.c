/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:52:10 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/14 11:52:13 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_image(char **element, t_data *data, char *line);
void	check_image_path(char *image_path, t_data *data);
void	error_free_exit(t_data *data, char *msg);

void	error_free_exit(t_data *data, char *msg)
{
	int	i;

	i = 0;
	if (data)
		free_data(data);
	ft_putstr_fd(msg, 2);
	while (i < 100)
		close(i++);
	exit(1);
}

void	check_image_path(char *image_path, t_data *data)
{
	char	*line;

	line = ft_strrchr(image_path, '.');
	if (!line || ft_strncmp(line, ".xpm", 5))
		error_free_exit(data, "Error\nInvalid image extension\n");
}

void	check_image(char **element, t_data *data, char *line)
{
	int		i;
	void	*image;
	
	check_image_path(element[1], data);
	image = mlx_xpm_file_to_image(data->mlx, element[1], &i, &i);
	if (!image)
		(free(line),
			error_free_exit(data, "Error\nInvalid or corrupted image\n"));
}

// void	mlx_initilize(t_data *data)
// {
// }
int	main(int ac, char **av)
{
	t_data	data;
	
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 150 , 150, "CUB3D");
	init_data(&data);
	// mlx_initilize(&data);
	file_pre_check(ac, av);
	file_store_data(av[1], &data);
	map_check(&data);
	// print_data(&data);
	mlx_loop(data.mlx);
	free_data(&data);
}
