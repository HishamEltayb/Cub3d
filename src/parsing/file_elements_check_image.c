/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_elements_check_image.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 07:31:29 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/20 14:59:18 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		error_free_exit(t_data *data, char *msg);
void		check_image_path(char *image_path, t_data *data);
static void	fill_image_data(t_data *data, int flag, void **image);
void		check_image(char **element, t_data *data, char *line);

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
void fill_image_data(t_data *data, int flag, void **image)
{
	if (flag == 0)
	{
		data->image.imageEA = *image;
		data->image.imageEA->addr = mlx_get_data_addr(data->image.imageEA,
				&data->image.imageEA->bits_per_pixel,
				&data->image.imageEA->line_length,
				&data->image.imageEA->endian);		
	}
	if (flag == 1)
	{
		data->image.imageWE = *image;
		data->image.imageWE->addr = mlx_get_data_addr(data->image.imageWE,
				&data->image.imageWE->bits_per_pixel,
				&data->image.imageWE->line_length,
				&data->image.imageWE->endian);		
	}
	if (flag == 2)
	{
		data->image.imageSO = *image;
		data->image.imageSO->addr = mlx_get_data_addr(data->image.imageSO,
				&data->image.imageSO->bits_per_pixel,
				&data->image.imageSO->line_length,
				&data->image.imageSO->endian);		
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
		data->image.imageNO = image;
		data->image.imageNO->addr = mlx_get_data_addr(data->image.imageNO,
				&data->image.imageNO->bits_per_pixel,
				&data->image.imageNO->line_length,
				&data->image.imageNO->endian);	
	}
}
