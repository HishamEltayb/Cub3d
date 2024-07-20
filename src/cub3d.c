/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:52:10 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/19 18:40:42 by heltayb          ###   ########.fr       */
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
	int		j;
	void	*image;
	
	image = NULL;
	if (element && element[0] && element[1])
		check_image_path(element[1], data);
	if (data && data->mlx)
		image = mlx_xpm_file_to_image(data->mlx, element[1], &i, &j);
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


void	player_display(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->image.player->img, data->player.x , data->player.y);	
}

int	display(t_data *data)
{
	int i = 0;
	int j = 0;
	mlx_clear_window(data->mlx, data->win);
	while (data->map2d[i])
	{
		j = 0;
		while (data->map2d[i][j])
		{
			if (data->map2d[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->image.background->img, j * data->pixel, i * data->pixel);
			else if (data->map2d[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->image.floor->img, j * data->pixel, i * data->pixel);
			else if (data->map2d[i][j] == ' ')
				mlx_put_image_to_window(data->mlx, data->win, data->image.space->img, j * data->pixel, i * data->pixel);
			else
				mlx_put_image_to_window(data->mlx, data->win, data->image.floor->img, j * data->pixel, i * data->pixel);
			j++;
		}
		while (j < data->width_x)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->image.space->img, j * data->pixel, i * data->pixel);
			j++;	
		}
		i++;
	}
	player_display(data);
	// mlx_put_image_to_window(data->mlx, data->win, data->image.player, 512, 256);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	int y = (int)data->player.y;
	int x = (int)data->player.x;
	int p = data->pixel;
	int end_of_player = (data->pixel / 4) - 1;
	
	if (keycode == 53)
		free_data(data), exit(0);
	if (keycode == KEY_UP)
	{
		y = y - 4;
		if (data->map2d[y/p][x/p] != '1' && data->map2d[y/p][(x + end_of_player) / p] != '1')
			data->player.y = y;
		display(data);
	}
	if (keycode == KEY_DOWN)
	{
		y = y + 4;
		if (data->map2d[(y + end_of_player)/p][(x)/p] != '1' && data->map2d[(y + end_of_player)/ p][(x + end_of_player) / p] != '1')
			data->player.y = y;
		// data->player.angle -= 0.1;
		display(data);
	}
	if (keycode == KEY_LEFT)
	{
		x = x - 4;
		if (data->map2d[y/p][x/p] != '1' && data->map2d[(y + end_of_player) / p][x/p] != '1')
			data->player.x = x;
		display(data);
	}
	if (keycode == KEY_RIGHT)
	{
		x = x + 4;
		if (data->map2d[y/ p][(x + end_of_player)/p] != '1' && data->map2d[(y + end_of_player) / p][(x + end_of_player) / p] != '1')
			data->player.x = x;
		display(data);
	}
	return (0);
}

int	exit_mouse(t_data *data)
{
	free_data(data);
	exit(0);
	return (0);
}


int	main(int ac, char **av)
{
	t_data	data;
	
	parsing(&data, ac, av);
	
	// print_data(&data);
	mlx_loop_hook(data.mlx, display, &data);
	
	
	mlx_hook(data.win, ON_KEYDOWN, 1L << 0, key_hook, &data);
	mlx_hook(data.win, ON_DESTROY, 1L << 3, exit_mouse, &data);
	mlx_loop(data.mlx);
	free_data(&data);
}
