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

void	check_image_path(char *image_path, t_data *data, char *line);
void	check_image(char **element, t_data *data, char *line);
void	fill_image_data(t_img *texture, int arr[2], void **image);

void	check_image_path(char *image_path, t_data *data, char *line)
{
	char	*temp;

	temp = ft_strrchr(image_path, '.');
	if (!temp)
		error_free_exit(data, "Error\nInvalid image extension\n");
	if (ft_strcmp(temp, ".xpm"))
		(free(line), error_free_exit(data, "Error\nInvalid image extension\n"));
}

void	fill_image_data(t_img *texture, int arr[2], void **image)
{
	(*texture).img = *image;
	(*texture).addr = mlx_get_data_addr((*texture).img,
			&((*texture).bits_per_pixel),
			&((*texture).line_length),
			&((*texture).endian));
	(*texture).width = arr[0];
	(*texture).height = arr[1];
}

void	check_image(char **element, t_data *data, char *line)
{
	int		arr[2];
	int		i;
	int		j;
	void	*image;

	i = 0;
	j = 0;
	image = NULL;
	if (element && element[0] && element[1])
		check_image_path(element[1], data, line);
	if (data && data->mlx)
		image = mlx_xpm_file_to_image(data->mlx, element[1], &i, &j);
	if (!image)
		(free(line), error_free_exit(data, "Error\nCorrupted image\n"));
	arr[0] = i;
	arr[1] = j;
	if (!ft_strcmp(element[0], "EA"))
		fill_image_data(&data->image_ea, arr, &image);
	else if (!ft_strcmp(element[0], "WE"))
		fill_image_data(&data->image_we, arr, &image);
	else if (!ft_strcmp(element[0], "SO"))
		fill_image_data(&data->image_so, arr, &image);
	else if (!ft_strcmp(element[0], "NO"))
		fill_image_data(&data->image_no, arr, &image);
}
