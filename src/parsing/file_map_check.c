/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_map_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:06:37 by heltayb           #+#    #+#             */
/*   Updated: 2024/08/11 21:29:43 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_check(t_data *data);
int		is_valid_map_char(char c, t_data *data);

void	map_check(t_data *data)
{
	data->pixel_x = 64;
	data->pixel_y = 64;
	data->map_pixel_x = data->pixel_x * 64;
	data->map_pixel_y = data->pixel_y * 64;
	if (map_player_check(data))
	{
		ft_putstr_fd("Error\nInvalid Map Characters1\n", 2);
		(free_data(data), exit(1));
	}
	if (check_space(data))
	{
		ft_putstr_fd("Error\nInvalid Map\n", 2);
		(free_data(data), exit(1));
	}
	if (is_sourrounded_by_walls(data))
	{
		ft_putstr_fd("Error\nInvalid Map\n", 2);
		(free_data(data), exit(1));
	}
}

int	is_valid_map_char(char c, t_data *data)
{
	if (c == '0' || c == '1' || c == ' ')
		return (TRUE);
	else if (!is_valid_map_char_helper(data, c))
		return (TRUE);
	else if (!is_valid_map_char_helper2(data, c))
		return (TRUE);
	return (FALSE);
}
