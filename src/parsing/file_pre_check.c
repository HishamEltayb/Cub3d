/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_pre_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:11:57 by heltayb           #+#    #+#             */
/*   Updated: 2024/08/11 21:33:36 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_space_or_one(char c);
void	file_pre_check(t_data *data, int ac, char **av);
bool	is_valid_map_char_helper(t_data *data, char c);
bool	is_valid_map_char_helper2(t_data *data, char c);

void	file_pre_check(t_data *data, int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac != 2)
		error_free_exit(data, "Error\nInvalid number of arguments\n");
	if (ft_strcmp(ft_strrchr(av[1], '.'), ".cub"))
		error_free_exit(data, "Error\nInvalid file extension\n");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_free_exit(data, "Error\nInvalid file\n");
	line = get_next_line(fd);
	while (line && !*line)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		error_free_exit(data, "Error\nInvalid file\n");
	free(line);
	close(fd);
}

bool	is_space_or_one(char c)
{
	return (c == ' ' || c == '1');
}

bool	is_valid_map_char_helper2(t_data *data, char c)
{
	if (c == 'W' && data->player.is_exist == NOT_EXIST)
	{
		data->player.is_exist = EXIST;
		data->player.dir = 'W';
		data->player.angle = 180;
		return (TRUE);
	}
	else if (c == 'E' && data->player.is_exist == NOT_EXIST)
	{
		data->player.is_exist = EXIST;
		data->player.dir = 'E';
		data->player.angle = 0;
		return (TRUE);
	}
	return (FALSE);
}

bool	is_valid_map_char_helper(t_data *data, char c)
{
	if (c == 'N' && data->player.is_exist == NOT_EXIST)
	{
		data->player.is_exist = EXIST;
		data->player.dir = 'N';
		data->player.angle = 90;
		return (TRUE);
	}
	else if (c == 'S' && data->player.is_exist == NOT_EXIST)
	{
		data->player.is_exist = EXIST;
		data->player.dir = 'S';
		data->player.angle = 270;
		return (TRUE);
	}
	return (FALSE);
}
