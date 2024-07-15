/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:52:10 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/15 13:47:50 by heltayb          ###   ########.fr       */
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
	ft_putstr_fd(msg, 2);
	if (data)
		free_data(data);
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
	
	image = NULL;
	if (element && element[0] && element[1])
		check_image_path(element[1], data);
	if (data && data->mlx)
		image = mlx_xpm_file_to_image(data->mlx, element[1], &i, &i);
	if (!image)
		(free(line),
			error_free_exit(data, "Error\nInvalid or corrupted image\n"));
	if (!ft_strcmp(element[0], "EA"))
		data->image.imageEA = image;
	else if (!ft_strcmp(element[0], "WE"))
		data->image.imageWE = image;
	else if (!ft_strcmp(element[0], "SO"))
		data->image.imageSO = image;
	else if (!ft_strcmp(element[0], "NO"))
		data->image.imageNO = image;
}

// void	mlx_initilize(t_data *data)
// {
// }
int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		free_data(data), exit(0);
	return (0);
}

int	exit_mouse(t_data *data)
{
	free_data(data);
	exit(0);
	return (0);
}


int	display(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->image.background, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->image.player, 512, 256);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	
	parsing(&data, ac, av);
	
	mlx_loop_hook(data.mlx, display, &data);
	
	
	mlx_hook(data.win, ON_KEYDOWN, 1L << 0, key_hook, &data);
	mlx_hook(data.win, ON_DESTROY, 1L << 3, exit_mouse, &data);
	mlx_loop(data.mlx);
	free_data(&data);
}
