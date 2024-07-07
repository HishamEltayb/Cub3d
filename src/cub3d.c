/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:41:28 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/07 21:28:15 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int 	check_helper(t_data *data, char *s1);
void	file_check_elements(t_data *data, char *line);
int 	check_helper2(int flag, char *s1, char *s2);
int	is_validpath(t_data *mlx, int width, int height);
void	validpath(t_data *mlx, int width, int height);
int	ft_index_of(char *str, char c);
int	is_surrounded_by_walls(t_data *data, int width, int height);


void	check_image(char *image_path, t_data *data)
{
	// int	i;
	// int	j;
	
	(void)data;
	(void)image_path;
	// data->mlx = mlx_init();
	// image = mlx_xpm_file_to_image(data->mlx, image_path, &i, &j);
	// if (!image)
	// {
	// 	ft_putstr_fd("Error\nInvalid image path", 2);
	// 	free_data(data);
	// 	exit(1);
	// }
}


int	main(int ac, char **av)
{
	t_data	data;
	int	i;
	// char **map2d;
	int	index;
	// char *line;
	
	init_data(&data);
	file_pre_check(ac, av);
	file_store_data(av[1], &data);
	i = 0;
	// print_data(&data); 
	while (data.map2d[i])
	{
		printf("i = %d\n", i);
		index = ft_index_of(data.map2d[i], ' ');
		printf("index = %d\n", index);
		if (index != -1)
			i++;
		else if (is_surrounded_by_walls(&data, index, i))
			printf("Valid space\n");
		else
			printf("Error\nInvalid space\n");
	}
	// index = ft_index_of(data.map2d[0], ' ');
	// printf("index = %d\n", index);
	// printf("i = %d\n", i);
	// validpath(&data, index, i);
	
	// if (!data.is_valid)
	// 	printf("Error\nInvalid space\n");
	// print_data(&data);
	free_data(&data);
}



int	is_validpath(t_data *data, int width, int height)
{
	int	i;
	int	j;

	if (height < 0 || width < 0)
		return (0);
	i = 0;
	if ((*data).map2d[height][width] != '1')
	{
		(*data).map2d[height][width] = '1';
		while (((*data).map2d[i]) && (i < ft_strlen2d(data->map2d) - 1))
		{
			j = 0;
			while ((*data).map2d[i][j] && (*data).map2d[i][j] != '\0')
			{
				if ((*data).map2d[i][j] == ' ')
					return (1);
				j++;
			}
			i++;
		}
		(*data).is_valid = 1;
	}
	// i = width;
	// j = height;
	// if (!height)
	// {
		
	// }

	// else if (height == ft_strlen2d((*data).map2d) - 1)
	// else
	return (0);
}

void	validpath(t_data *data, int width, int height)
{
	(*data).map2d[height][width] = '1';
	if (!(*data).is_valid && is_validpath(data, width, height - 1))
		validpath(data, width, height - 1);
	if (!(*data).is_valid && is_validpath(data, width + 1, height))
		validpath(data, width + 1, height);
	if (!(*data).is_valid && is_validpath(data, width, height + 1))
		validpath(data, width, height + 1);
	if (!(*data).is_valid && is_validpath(data, width - 1, height))
		validpath(data, width - 1, height);
}

int	ft_index_of(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (i == 0 && str[i] != c)
		return (-1);
	return (i);
}


int	is_surrounded_by_walls(t_data *data, int width, int height)
{
	char	**map;

	map = data->map2d;

	if (width == 5)
	{
		printf("width = %d\n", width);
		printf("height = %d\n", height);
		printf("map[height - 1][width] = %c\n", map[height - 1][width]);
		printf("map[height + 1][width] = %c\n", map[height + 1][width]);
		printf("map[height][width - 1] = %c\n", map[height][width - 1]);
		printf("map[height][width + 1] = %c\n", map[height][width + 1]);
	}
	return (
		(map[height - 1][width] == ' ' || map[height - 1][width] == '1')
			&& (map[height + 1][width] == ' ' || map[height - 1][width] == '1')
			&& (map[height][width - 1] == ' ' || map[height - 1][width] == '1')
			&& (map[height][width + 1] == ' ' || map[height - 1][width] == '1')
	);
}
