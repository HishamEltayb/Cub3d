/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:20:24 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/14 09:59:40 by heltayb          ###   ########.fr       */
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

# ifdef Linux

typedef enum key_map
{

	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_W = 119,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_ESC = 65307
}					t_key;

# else

typedef enum key_map
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_ESC = 53
}					t_key;

# endif

# define EXIST 0
# define NOT_EXIST 1
# define TRUE 0
# define FALSE 1
# define MAP 2
# define ELEMENT 1
# define PLAYER "NSWE"


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
	int			PlayerN;
	int			PlayerS;
	int			PlayerW;
	int			PlayerE;
}			t_flags;

typedef struct s_player
{
	bool	is_exist;
	double	x;
	double	y;
	char	dir;
}			t_player;

typedef struct s_image
{
	void	*imageEA;
	void	*imageWE;
	void	*imageSO;
	void	*imageNO;
}			t_image;

typedef struct s_data
{
	t_list		*map;
	char		**map2d;
	t_element	*element;
	t_flags		flags;
	t_player	player;
	t_image		image;
	void		*mlx;
	void		*win;

	int			file_size;
	int			max_len;
	int			is_valid;
	int			height;
	int			width;
}	t_data;



//src/parsing/file_data_store.c
void	file_store_data(char *filename, t_data *data);

//src/parsing/file_elements_check.c
int		check_colors(char **str);
int		check_colors_helper(char **str);
int		check_helper(t_data *data, char *s1);
int		check_helper2(int flag, char *s1, char *s2);
void	file_check_elements(t_data *data, char *line);

//src/parsing/file_elements_create.c
int		is_element(char **split);
void	fill_elements(char *line, t_data *data, int fd);
void	skip_empty_line(char **line, t_data *data, int fd, int flag);
void	file_elements_create(t_data *data, char **line, int fd);

//src/parsing/file_elements_rearrange.c
int		count_comma(char *line);
int		is_floor_ceiling(char *str);
int		rearrange_helper(t_data *data, t_element *element);
void	floor_ceiling_re_arrange(t_data *data, char *line, int fd);

//src/parsing/file_elements_utils.c
t_element	*element_new(void **content);
t_element	*element_last(t_element *lst);
void		element_add_back(t_element **lst, t_element *new);
void		element_delone(t_element *lst, void (*del)(void **));
void		element_clear(t_element **lst, void (*del)(void **));

//src/parsing/file_map_check_utils.c
bool	checking(t_data *data, int x, int y, char c);
bool	check_up(t_data *data, int x, int y, char c);
bool	check_left(t_data *data, int x, int y, char c);
bool	check_down(t_data *data, int x, int y, char c);
bool	check_right(t_data *data, int x, int y, char c);

//src/parsing/file_map_check.c
void	map_check(t_data *data);
bool	check_space(t_data *data);
int		map_player_check(t_data *data);
bool	is_sourrounded_by_walls(t_data *data);
int		is_valid_map_char(char c, t_data *data);

//src/parsing/file_map_create.c
void	create_map2d(t_data *data);
int		is_valid_map_line(char *str, t_data *data);
void	fill_map(char *line, t_data *data, int fd);
void	fill_map(char *line, t_data *data, int fd);
void	file_maps_create(t_data *data, char **line, int fd);

//src/parsing/file_pre_check.c
bool	is_space_or_one(char c);
void	file_pre_check(int ac, char **av);
bool	is_valid_map_char_helper(t_data *data, char c);
bool	is_valid_map_char_helper2(t_data *data, char c);

//src/cub3d.c
void	check_image(char **element, t_data *data, char *line);


//src/utils1.c
int		ft_strlen2d(char **str);
void	print_data(t_data *data);
void	print_list(t_data *data);
void	print_elements(t_data *data);

//src/utils2.c
void	free2d(void **content);
void	init_data(t_data *data);
void	free_data(t_data *data);



bool	is_valid_map_char_helper(t_data *data, char c);
bool	is_valid_map_char_helper2(t_data *data, char c);


void	check_image_path(char *image_path, t_data *data);
void	error_free_exit(t_data *data, char *msg);

#endif