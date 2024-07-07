/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_map_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:06:37 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/07 10:52:28 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		map_check(t_data *data);
static int	is_valid_map_char(char c);
static void	map_characters_check(t_data *data);

int is_valid_map_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' 
		|| c == 'W' || c == 'E' || c == ' ')
		return (1);
	return (0);
}

static void	map_characters_check(t_data *data)
{
	t_list	*temp;
	char	*line;
	int		i;

	temp = data->map;
	while (temp)
	{
		i = -1;
		line = (char *)temp->content;
		if (line && !*line)
			(ft_putstr_fd("Error\nEmpty line\n", 2), free_data(data), exit(1));
		while (line && line[++i])
		{
			if (!is_valid_map_char(line[i]))
				(ft_putstr_fd("Error\nInvalid Map Char\n", 2),
					free_data(data), exit(1));
		}
		temp = temp->next;
	}	
}
void	map_check(t_data *data)
{
	map_characters_check(data);
}

