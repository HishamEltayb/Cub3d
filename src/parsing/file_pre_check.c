/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_pre_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:11:57 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/08 17:40:42 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_space_or_one(char c);
void	file_pre_check(int ac, char **av);
void	exit_failuer(t_data *data, char *err);
bool	is_valid_map_char_helper(t_data *data, char c);
bool	is_valid_map_char_helper2(t_data *data, char c);

void	file_pre_check(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac != 2)
		(ft_putstr_fd("Error\nInvalid number of arguments\n", 2), exit(1));
	if (ft_strcmp(ft_strrchr(av[1], '.'), ".cub"))
		(ft_putstr_fd("Error\nInvalid file extension\n", 2), exit(1));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		(ft_putstr_fd("Error\nInvalid file\n", 2), exit(1));
	line = get_next_line(fd);
	while (line && !*line)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		(ft_putstr_fd("Error\nEmpty file\n", 2), close(fd), exit(1));
	free(line);
	close(fd);
}

bool	is_space_or_one(char c)
{
	return (c == ' ' || c == '1');
}

void	exit_failuer(t_data *data, char *err)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(err, 2);
	free_data(data);
	exit(EXIT_FAILURE);
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
