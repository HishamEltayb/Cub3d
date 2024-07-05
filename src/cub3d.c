/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:41:28 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/05 19:11:44 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_2dlen(char **arr);
int 	check_helper(t_data *data, char *s1);
void	file_check_elements(t_data *data);
int 	check_helper2(int flag, char *s1, char *s2, char **str);

int	ft_2dlen(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

int check_helper(t_data *data, char *s1)
{
	if (!ft_strcmp(s1, "EA") && data->flag_ea == NOT_EXIST)
	{
		data->flag_ea = EXIST;
		return (TRUE);
	}
	else if (!ft_strcmp(s1, "WE") && data->flag_we == NOT_EXIST)
	{
		data->flag_we = EXIST;
		return (TRUE);
	}
	else if (!ft_strcmp(s1, "SO") && data->flag_so == NOT_EXIST)
	{
		data->flag_so = EXIST;
		return (TRUE);
	}
	else if (!ft_strcmp(s1, "NO") && data->flag_no == NOT_EXIST)
	{
		data->flag_no = EXIST;
		return (TRUE);
	}
	else
		return (FALSE);
}
int check_helper2(int flag, char *s1, char *s2, char **str)
{
	int	i;
	int temp;

	if (str && !ft_strcmp(s1, s2) && flag == NOT_EXIST)
	{
		
		if (ft_2dlen(str) == 4)
		{
			i = 1;
			while (str && str[i])
			{
				temp = ft_atoi(str[i]);
				if (temp > 255 || temp < 0)
					return (FALSE);
				i++;
			}
		}
		else
			return (FALSE);
			
		return (TRUE);
	}
	else
		return (FALSE);
}

void	check_image(char *image_path, t_data *data)
{
	void	*image;
	int	i;
	int	j;
	
	image = mlx_xpm_file_to_image(data->mlx, image_path, &i, &j);
	if (!image)
	{
		ft_putstr_fd("Error\nInvalid image path", 2);
		free_data(data);
		exit(1);
	}
}
void	file_check_elements(t_data *data)
{
	t_element	*temp;
	char		**str;

	temp = data->element;
	while (temp)
	{
		str = (char **)temp->content;
		if (!check_helper(data, str[0]))
			check_image(str[1], data);
		else if (!check_helper2(data->flag_f, str[0], "F", str))
			data->flag_f = EXIST;
		else if (!check_helper2(data->flag_c, str[0], "C", str))
			data->flag_c = EXIST;
		else
		{
			ft_putstr_fd("Error\nInvalid Elements", 2);
			free_data(data);
			exit(1);
		}
		temp = temp->next;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	init_data(&data);
	file_pre_check(ac, av, &data);
	file_check_elements(&data);
	print_list(&data);
	free_data(&data);
	// file_validaty_check(file_size, )
}
