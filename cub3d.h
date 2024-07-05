/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:20:24 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/05 19:11:17 by heltayb          ###   ########.fr       */
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

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_list		*map;
	t_element	*element;
	int			file_size;
	int			flag_c;
	int			flag_f;
	int			flag_ea;
	int			flag_we;
	int			flag_so;
	int			flag_no;

}	t_data;


// element.c
t_element	*element_new(void **content);
void		element_add_back(t_element **lst, t_element *new);
void		element_delone(t_element *lst, void (*del)(void ***));
void		element_clear(t_element **lst, void (*del)(void ***));
t_element	*element_last(t_element *lst);

// utils.c
void	free2d(void ***content);
void	free_data(t_data *data);
void	init_data(t_data *data);
void	print_list(t_data *data);
void	elements_handel(t_data *data);
void	file_store_data(char *filename, t_data *data);
void	file_pre_check(int ac,char **av, t_data *data);
void	fill_elements(char *line, t_data *data, int fd);
void	fill_map(char *line, t_data *data, bool *map, int fd);
void	check_image(char *image_path, t_data *data);



int		ft_2dlen(char **arr);
int 	check_helper(t_data *data, char *s1);
void	file_check_elements(t_data *data);
int 	check_helper2(int flag, char *s1, char *s2, char **str);


#endif