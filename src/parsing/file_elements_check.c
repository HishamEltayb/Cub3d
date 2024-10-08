/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_elements_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:54:39 by heltayb           #+#    #+#             */
/*   Updated: 2024/08/11 21:34:01 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_colors(char **str);
int		check_colors_helper(char **str);
int		check_helper(t_data *data, char *s1);
int		check_helper2(int flag, char *s1, char *s2);
void	file_check_elements(t_data *data, char *line);

int	check_colors_helper(char **str)
{
	int	i;

	i = 1;
	if (ft_strlen2d(str) != 4)
		return (1);
	while (str && str[i])
	{
		if (ft_mini_atoi(str[i]) == -1)
			return (1);
		i++;
	}
	return (0);
}

int	check_colors(char **str)
{
	if (check_colors_helper(str))
		return (1);
	return (0);
}

void	file_check_elements(t_data *data, char *line)
{
	t_element	*temp;
	char		**str;

	temp = data->element;
	while (temp)
	{
		str = (char **)temp->content;
		if (ft_strlen2d(str) == 2 && !check_helper(data, str[0]))
			check_image(str, data, line);
		else if (!check_helper2(data->flags.f, str[0], "F")
			|| !check_helper2(data->flags.c, str[0], "C"))
		{
			if (!ft_strcmp(str[0], "F"))
				data->flags.f = EXIST;
			else if (!ft_strcmp(str[0], "C"))
				data->flags.c = EXIST;
			if (check_colors(str))
				(free(line), error_free_exit(data, "Error\nInvalid Colors\n"));
			if (create_rgb(data, str))
				(free(line), error_free_exit(data, "Error\nInvalid Colors\n"));
		}
		else
			(free(line), error_free_exit(data, "Error\nInvalid Elements\n"));
		temp = temp->next;
	}
}

int	check_helper(t_data *data, char *s1)
{
	if (!ft_strcmp(s1, "EA") && data->flags.ea == NOT_EXIST)
	{
		data->flags.ea = EXIST;
		return (TRUE);
	}
	else if (!ft_strcmp(s1, "WE") && data->flags.we == NOT_EXIST)
	{
		data->flags.we = EXIST;
		return (TRUE);
	}
	else if (!ft_strcmp(s1, "SO") && data->flags.so == NOT_EXIST)
	{
		data->flags.so = EXIST;
		return (TRUE);
	}
	else if (!ft_strcmp(s1, "NO") && data->flags.no == NOT_EXIST)
	{
		data->flags.no = EXIST;
		return (TRUE);
	}
	else
		return (FALSE);
}

int	check_helper2(int flag, char *s1, char *s2)
{
	if (flag == NOT_EXIST && !ft_strcmp(s1, s2))
		return (TRUE);
	else
		return (FALSE);
}
