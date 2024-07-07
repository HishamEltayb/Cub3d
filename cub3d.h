/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:20:24 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/07 14:08:07 by heltayb          ###   ########.fr       */
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

#define EXIST 0
#define NOT_EXIST 1
#define TRUE 0
#define FALSE 1

typedef struct s_element
{
	void				**content;
	struct s_element	*next;
}			t_element;

typedef struct s_flags
{
	int			C;
	int			F;
	int			EA;
	int			WE;
	int			SO;
	int			NO;
}			t_flags;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_list		*map;
	char		**map2d;
	t_element	*element;
	t_flags		flags;
	int			file_size;
	int			max_len;
}	t_data;


// utils.c
void	file_store_data(char *filename, t_data *data);
void	check_image(char *image_path, t_data *data);



void	file_check_elements(t_data *data, char *line);














//src/parsing/file_helpers.c
void			free2d(void **content);
void			free_data(t_data *data);
void			init_data(t_data *data);
void			print_data(t_data *data);
int				ft_strlen2d(char **str);
void			print_list(t_data *data);
void			print_elements(t_data *data);

//src/parsing/file_pre_check.c
void			file_pre_check(int ac,char **av);

//src/parsing/file_store_data.c
void			file_store_data(char *filename, t_data *data);
void			fill_elements(char *line, t_data *data, int fd);
void			fill_map(char *line, t_data *data, int fd);

//src/parsing/file_element_utils.c
t_element		*element_new(void **content);
t_element		*element_last(t_element *lst);
void			element_add_back(t_element **lst, t_element *new);
void			element_delone(t_element *lst, void (*del)(void **));
void			element_clear(t_element **lst, void (*del)(void **));

//src/parsing/file_rearrange_elements.c
void			floor_ceiling_re_arrange(t_data *data, char *line);

//src/parsing/file_map_check.c
void			map_check(t_data *data);
void	map_spaces_fill(t_data *data);

int	check_helper2(int flag, char *s1, char *s2);
int is_valid_map_char(char c);

#endif