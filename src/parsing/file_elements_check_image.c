/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_elements_check_c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 07:31:29 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/20 14:59:18 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_free_exit(t_data *data, char *msg);
void	check_image_path(char *image_path, t_data *data);
void	fill_image_data(t_data *data, int flag, void **image);
void	check_image(char **element, t_data *data, char *line);

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

void	fill_image_data(t_data *data, int flag, void **image)
{
	if (flag == 0)
	{
		data->imageEA.img = *image;
		data->imageEA.addr = mlx_get_data_addr(data->imageEA.img,
				&data->imageEA.bits_per_pixel,
				&data->imageEA.line_length,
				&data->imageEA.endian);
	}
	if (flag == 1)
	{
		data->imageWE.img = *image;
		data->imageWE.addr = mlx_get_data_addr(data->imageWE.img,
				&data->imageWE.bits_per_pixel,
				&data->imageWE.line_length,
				&data->imageWE.endian);
	}
	if (flag == 2)
	{
		data->imageSO.img = *image;
		data->imageSO.addr = mlx_get_data_addr(data->imageSO.img,
				&data->imageSO.bits_per_pixel,
				&data->imageSO.line_length,
				&data->imageSO.endian);
	}
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
		(free(line), error_free_exit(data, "Error\nCorrupted image\n"));
	if (!ft_strcmp(element[0], "EA"))
		fill_image_data(data, 0, &image);
	else if (!ft_strcmp(element[0], "WE"))
		fill_image_data(data, 1, &image);
	else if (!ft_strcmp(element[0], "SO"))
		fill_image_data(data, 2, &image);
	else if (!ft_strcmp(element[0], "NO"))
	{
		data->imageNO.img = image;
		data->imageNO.addr = mlx_get_data_addr(data->imageNO.img,
				&data->imageNO.bits_per_pixel,
				&data->imageNO.line_length,
				&data->imageNO.endian);
	}
}
