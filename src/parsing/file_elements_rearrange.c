/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_elements_rearrange.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:01:34 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/07 20:01:33 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			count_comma(char *line);
int			is_floor_ceiling(char *str);
static int	rearrange_helper(t_data *data);
void		floor_ceiling_re_arrange(t_data *data, char *line);

int	is_floor_ceiling(char *str)
{
	if (!ft_strcmp(str, "F") || !ft_strcmp(str, "C"))
		return (0);
	return (1);
}

 int	count_comma(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line && line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	return (count);
}

static int	rearrange_helper(t_data *data)
{
	char	**temp_content;
	char	*str;
	char	**temp2d_comma_without_first;
	char	**new_2d;
	int		i;

	temp_content = (char **)(data->element->content);
	str = ft_strnjoin(ft_strlen2d(temp_content) - 1, &(temp_content[1]));
	if (count_comma(str) != 2)
		return (free(str), ft_putstr_fd("Error\nCheck The Commas\n", 2), 0);
	temp2d_comma_without_first = ft_split(str, ',');
	new_2d = ft_calloc((ft_strlen2d(temp2d_comma_without_first) + 2),
			sizeof(char *));
	i = 0;
	new_2d[i++] = ft_strdup(temp_content[0]);
	while ((i - 1 >= 0) && temp2d_comma_without_first[i - 1])
	{
		new_2d[i] = ft_strdup(temp2d_comma_without_first[i - 1]);
		i++;
	}
	(free2d((void **)temp_content), free(str));
	free2d((void **)temp2d_comma_without_first);
	data->element->content = (void **)new_2d;
	return (1);
}

void	floor_ceiling_re_arrange(t_data *data, char *line)
{
	t_element	*temp;
	char		**temp_content;

	temp = data->element;
	while (data->element)
	{
		temp_content = (char **)(data->element->content);
		if (temp_content && !is_floor_ceiling(temp_content[0]))
		{
			if (!rearrange_helper(data))
			{
				data->element = temp;			
				(free_data(data), free(line), exit(1));
			}
		}
		data->element = data->element->next;
	}
	data->element = temp;
}
