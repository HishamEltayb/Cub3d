/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_elements_rearrange.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:01:34 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/07 10:56:03 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_comma(char *line);
void		floor_ceiling_re_arrange(t_data *data);
static char	**rearrange_helper(t_element **element, t_data *data);

static int	count_comma(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	return (count);
}

static char	**rearrange_helper(t_element **element, t_data *data)
{
	char	**temp_content;
	char	**temp2d_comma_without_first;
	char	**new_2d;
	char	*str;
	int		i;

	(void)element;
	temp_content = (char **)(data->element->content);
	str = ft_strnjoin(ft_strlen2d(temp_content) - 1, &(temp_content[1]));
	if (count_comma(str) != 2)
		(ft_putstr_fd("Error\nCheck The Commas\n", 2), free(str),
			free_data(data), exit(1));
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
	(data->element)->content = (void **)new_2d;
	return (new_2d);
}

void	floor_ceiling_re_arrange(t_data *data)
{
	t_element	*temp;

	temp = data->element;
	while (temp)
	{
		if (temp->content
			&& (!ft_strncmp(temp->content[0], "C", 1)
				|| !ft_strncmp(temp->content[0], "F", 1)))
			rearrange_helper(&temp, data);
		temp = temp->next;
	}
}
