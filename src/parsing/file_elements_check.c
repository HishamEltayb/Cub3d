/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:54:39 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/06 14:08:55 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		file_check_elements(t_data *data);
void		check_colors(t_data *data);
static int	check_helper(t_data *data, char *s1);
static int	check_helper2(int flag, char *s1, char *s2);

void	check_colors_helper(t_element *element, t_data *data)
{
	int		i;
	int		j;
	char	**str;

	i = 1;
	str = (char **)element->content;
	if (ft_strlen2d(str) != 4)
		(ft_putstr_fd("Error\nInvalid Colors\n", 2), free_data(data), exit(1));
	while (str && str[i])
	{
		j = 0;
		while (str[i] && str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				(ft_putstr_fd("Error\nInvalid Colors\n", 2),
					free_data(data), exit(1));
			j++;
		}
		if (ft_atoi(str[i]) < 0 || ft_atoi(str[i]) > 255)
			(ft_putstr_fd("Error\nInvalid Colors\n", 2),
				free_data(data), exit(1));
		i++;
	}
}

void	check_colors(t_data *data)
{
	t_element	*temp;
	char		**str;
	
	temp = data->element;
	while (temp)
	{
		str = (char **)temp->content;
		if (!ft_strcmp(str[0], "F"))
			check_colors_helper(temp, data);
		else if (!ft_strcmp(str[0], "C"))
			check_colors_helper(temp, data);
		temp = temp->next;
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
		else if (!check_helper2(data->flags.F, str[0], "F")
			|| !check_helper2(data->flags.C, str[0], "C"))
		{
			if (!ft_strcmp(str[0], "F"))
				data->flags.F = EXIST;
			else if (!ft_strcmp(str[0], "C"))
				data->flags.C = EXIST;
		}
		else
		{
			(ft_putstr_fd("Error\nInvalid Elements", 2), free_data(data));
			exit(1);
		}
		temp = temp->next;
	}
	(check_colors(data), map_check(data));
}

static int	check_helper(t_data *data, char *s1)
{
	if (!ft_strcmp(s1, "EA") && data->flags.EA == NOT_EXIST)
	{
		data->flags.EA = EXIST;
		return (TRUE);
	}
	else if (!ft_strcmp(s1, "WE") && data->flags.WE == NOT_EXIST)
	{
		data->flags.WE = EXIST;
		return (TRUE);
	}
	else if (!ft_strcmp(s1, "SO") && data->flags.SO == NOT_EXIST)
	{
		data->flags.SO = EXIST;
		return (TRUE);
	}
	else if (!ft_strcmp(s1, "NO") && data->flags.NO == NOT_EXIST)
	{
		data->flags.NO = EXIST;
		return (TRUE);
	}
	else
		return (FALSE);
}

static int	check_helper2(int flag, char *s1, char *s2)
{
	if (flag == NOT_EXIST && !ft_strcmp(s1, s2))
		return (TRUE);
	else
		return (FALSE);
}
