/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:20:24 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/16 09:43:14 by heltayb          ###   ########.fr       */
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
	ON_DESTROY = 36,
	ESC = 65307,
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_RIGHT = 65363,
	KEY_LEFT = 65361,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}					t_key;

# else

typedef enum key_map
{
	ON_DESTROY = 17,
	ESC = 53,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_RIGHT = 124,
	KEY_LEFT = 123,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12
}					t_key;

# endif

# define EXIST 0
# define NOT_EXIST 1
# define TRUE 0
# define FALSE 1
# define MAP 2
# define ELEMENT 1
# define PLAYER "NSWE"

//start_colors
# define Red 0xFF0000
# define Green 0x00FF00
# define Blue 0x0000FF
# define Cyan 0x00FFFF
# define Magenta 0xFF00FF
# define Yellow 0xFFFF00
# define Black 0x000000
# define White 0xFFFFFF
# define Gray 0x808080
# define Maroon 0x800000
# define Olive 0x808000
# define Navy 0x000080
# define Purple 0x800080
# define Teal 0x008080
# define Silver 0xC0C0C0
# define Lime 0x00FF00
# define Aqua 0x00FFFF
# define Fuchsia 0xFF00FF
# define Orange 0xFFA500
# define Brown 0xA52A2A
# define Gold 0xFFD700
# define Pink 0xFFC0CB
# define Lavender 0xE6E6FA
# define Turquoise 0x40E0D0
# define Beige 0xF5F5DC
# define Coral 0xFF7F50
# define Salmon 0xFA8072
# define Khaki 0xF0E68C
# define Indigo 0x4B0082
# define Violet 0xEE82EE
//end_colors

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

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_image
{
	t_img	*imageEA;
	t_img	*imageWE;
	t_img	*imageSO;
	t_img	*imageNO;
	t_img	*background;
	t_img	*player;
	t_img	*floor;
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
	int			pixel;
	int			valid_line_count;

	int			height_y;
	int			width_x;
	int			floor_color;
	int			ceiling_color;
		
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
int		is_element(char **split, t_data *data);
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
int		free_data(t_data *data);



bool	is_valid_map_char_helper(t_data *data, char c);
bool	is_valid_map_char_helper2(t_data *data, char c);


void	check_image_path(char *image_path, t_data *data);
void	error_free_exit(t_data *data, char *msg);


void	parsing(t_data *data, int ac, char **av);


#endif