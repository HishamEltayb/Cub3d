/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:41:28 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/03 10:19:34 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	file_check_elements(t_data *data)
{
	int	i;
	t_list	*temp;
	char	*str;

	temp = data->map;
	while (temp)
	{
		i = 0;
		str = temp->content;
		while (str && str[i])
		{
			i++;
		}
		temp = temp->next;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	init_data(&data);
	file_pre_check(ac, av, &data);
	// file_check_elements(&data);
	print_list(&data);
	free_data(&data);
	// file_validaty_check(file_size, )
}
