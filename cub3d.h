/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:20:24 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/03 11:39:37 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>
# include "libft.h"


typedef struct s_element
{
	void				**content;
	struct s_element	*next;
}			t_element;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_list		*map;
	t_element	*element;
	int			file_size;

}	t_data;

// utils.c
void	free_data(t_data *data);
void	init_data(t_data *data);
void	print_list(t_data *data);
void	file_store_data(int fd, t_data *data);
void	file_pre_check(int ac,char **av, t_data *data);

// element.c
t_element	*element_new(void **content);
void		element_add_back(t_element **lst, t_element *new);
void		element_delone(t_element *lst, void (*del)(void **));
void		element_clear(t_element **lst, void (*del)(void **));
t_element	*element_last(t_element *lst);
void	elements_check(t_data *data);

#endif