/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_pre_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:11:57 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/14 09:56:04 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_space_or_one(char c);
void	file_pre_check(int ac, char **av);
bool	is_valid_map_char_helper(t_data *data, char c);
bool	is_valid_map_char_helper2(t_data *data, char c);

void	file_pre_check(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac != 2)
		error_free_exit(NULL , "Error\nInvalid number of arguments\n");
	if (ft_strcmp(ft_strrchr(av[1], '.'), ".cub"))
		error_free_exit(NULL , "Error\nInvalid file extension\n");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_free_exit(NULL , "Error\nInvalid file\n");
	line = get_next_line(fd);
	while (line && !*line)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		error_free_exit(NULL , "Error\nInvalid file\n");
	free(line);
	close(fd);
}

bool	is_space_or_one(char c)
{
	return (c == ' ' || c == '1');
}

bool	is_valid_map_char_helper2(t_data *data, char c)
{
	if (c == 'W' && data->flags.PlayerW == NOT_EXIST
		&& data->player.is_exist == NOT_EXIST)
	{
		data->flags.PlayerW = EXIST;
		data->player.is_exist = EXIST;
		return (TRUE);
	}
	else if (c == 'E' && data->flags.PlayerE == NOT_EXIST
		&& data->player.is_exist == NOT_EXIST)
	{
		data->flags.PlayerE = EXIST;
		data->player.is_exist = EXIST;
		return (TRUE);
	}
	return (FALSE);
}

bool	is_valid_map_char_helper(t_data *data, char c)
{
	if (c == 'N' && data->flags.PlayerN == NOT_EXIST
		&& data->player.is_exist == NOT_EXIST)
	{
		data->flags.PlayerN = EXIST;
		data->player.is_exist = EXIST;
		return (TRUE);
	}
	else if (c == 'S' && data->flags.PlayerS == NOT_EXIST
		&& data->player.is_exist == NOT_EXIST)
	{
		data->flags.PlayerS = EXIST;
		data->player.is_exist = EXIST;
		return (TRUE);
	}
	return (FALSE);
}
