/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_pre_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:11:57 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/06 11:09:22 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	file_pre_check(int ac, char **av);

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
	if (!line)
		(ft_putstr_fd("Error\nEmpty file\n", 2), close(fd), exit(1));
	free(line);
	close(fd);
}
