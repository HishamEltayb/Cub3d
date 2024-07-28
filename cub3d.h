/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:20:24 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/28 17:09:25 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

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
	KEY_D = 100 ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}						t_key;

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
}						t_key;

# endif

# define WIDTH 1920
# define HEIGHT 1080

# define MINIMAP_X 300
# define MINIMAP_Y 200

# define EXIST 			0
# define NOT_EXIST 		1
# define TRUE 			0
# define FALSE 			1
# define MAP 			2
# define ELEMENT 		1
# define PLAYER 		"NSWE"
# define PLAYER_SIZE 	14
//math
# define PI 3.1415926535

//start_colors
# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF
# define YELLOW	0xFFFF00
# define WHITE	0xFFFFFF
# define BLACK	0x000000
# define GRAY	0x808080
# define BROWN	0xA52A2A
//end_colors

typedef struct s_flags
{
	int					c;
	int					f;
	int					ea;
	int					we;
	int					so;
	int					no;
	int					player_n;
	int					player_s;
	int					player_w;
	int					player_e;
}						t_flags;

typedef struct s_player
{
	bool				is_exist;
	double				x;
	double				y;
	double				dx;
	double				dy;
	double				angle;
	char				dir;
}						t_player;

typedef struct s_raycast
{
	int					counter;
	float				angle;
	float				vertical_x;
	float				vertical_y;
	int					mx;
	int					my;
	int					mp;
	int					dist_of_field;
	float				rx;
	float				ry;
	float				xo;
	float				yo;
	float				dis_v;
	float				dis_h;
	float				tan;
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					err;
	int					e2;
	int					arr[4];
	float				final_dist;
	float				line_height;
	int					color;
}						t_raycast;

typedef struct s_img
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_img;

typedef struct s_element
{
	void				**content;
	struct s_element	*next;
}						t_element;

typedef struct s_data
{
	t_flags				flags;
	t_list				*map;
	t_element			*element;
	char				**map2d;
	int					valid_line_count;
	int					floor_color;
	int					ceiling_color;

	t_img				image_ea;
	t_img				image_we;
	t_img				image_so;
	t_img				image_no;
	t_img				main;
	t_img				main_3d;

	t_player			player;

	int					map_y;
	int					map_x;
	int					map_size;
	int					pixel;
	int					pixel_x;
	int					pixel_y;

	void				*mlx;
	void				*win;
	int					player_size;
	int					player_speed;

}						t_data;

//src/parsing/file_elements_check_image.c
void					error_free_exit(t_data *data, char *msg);
void					check_image_path(char *image_path, t_data *data);
void					fill_image_data(t_data *data, int flag, void **image);
void					check_image(char **element, t_data *data, char *line);

//src/parsing/file_elements_check.c
int						check_colors(char **str);
int						check_colors_helper(char **str);
int						check_helper(t_data *data, char *s1);
int						check_helper2(int flag, char *s1, char *s2);
void					file_check_elements(t_data *data, char *line);

//src/parsing/file_elements_create_utils.c
int						ft_mini_atoi(char *str);
void					skip_zeros(int *i, char *str);
int						count_numbers(char *line, int *j);
int						is_element(char **split, t_data *data);
int						check_numbers(char **split, int *i, int *check);

//src/parsing/file_elements_create.c
int						create_rgb(t_data *data, char **str);
void					fill_elements(char *line, t_data *data, int fd);
void					file_elements_create(t_data *data, char **line, int fd);
void					skip_empty_line(char **line, t_data *data, int fd,
							int flag);

//src/parsing/file_elements_rearrange.c
int						count_comma(char *line);
int						is_floor_ceiling(char *str);
int						rearrange_helper(t_data *data, t_element *element);
void					floor_ceiling_re_arrange(t_data *data, char *line,
							int fd);

//src/parsing/file_elements_utils.c
t_element				*element_new(void **content);
t_element				*element_last(t_element *lst);
void					element_add_back(t_element **lst, t_element *new);
void					element_delone(t_element *lst, void (*del)(void **));
void					element_clear(t_element **lst, void (*del)(void **));

//src/parsing/file_init.c
void					init_image(t_img *image);
void					init_flags(t_data *data);
void					init_player(t_data *data);
void					init_parsing(t_data *data);

//src/parsing/file_map_check_utils.c
bool					checking(t_data *data, int x, int y, char c);
bool					check_up(t_data *data, int x, int y, char c);
bool					check_left(t_data *data, int x, int y, char c);
bool					check_down(t_data *data, int x, int y, char c);
bool					check_right(t_data *data, int x, int y, char c);

//src/parsing/file_map_check.c
void					map_check(t_data *data);
void					resize_map(t_data *data);
int						is_valid_map_char(char c, t_data *data);

//src/parsing/file_map_create.c
void					create_map2d(t_data *data);
int						is_valid_map_line(char *str, t_data *data);
void					fill_map(char *line, t_data *data, int fd);
void					fill_map(char *line, t_data *data, int fd);
void					file_maps_create(t_data *data, char **line, int fd);

//src/parsing/file_map_utils.c
bool					check_space(t_data *data);
int						map_player_check(t_data *data);
bool					is_sourrounded_by_walls(t_data *data);

//src/parsing/file_parsing.c
void					create_image(t_data *data);
void					parsing(t_data *data, int ac, char **av);
void					file_store_data(char *filename, t_data *data);

//src/parsing/file_pre_check.c
bool					is_space_or_one(char c);
void					file_pre_check(int ac, char **av);
bool					is_valid_map_char_helper(t_data *data, char c);
bool					is_valid_map_char_helper2(t_data *data, char c);

//src/drawing/drawing_utils.c
int						exit_mouse(t_data *data);
int						draw_player(t_data *data);
void					draw_square(t_data *data, int x, int y, int color);
void					my_mlx_pixel_put(t_data *data, t_img *image, int arr[2], int color);

//src/drawing/drawing_and_keys.c
int						display(t_data *data);
void					draw_map2d(t_data *data);
int						key_hook(int keycode, t_data *data);
void					key_left_right(t_data *data, int keycode);

//src/utils1.c
void					print_2d(t_data *data);
int						ft_strlen2d(char **str);
void					print_data(t_data *data);
void					print_list(t_data *data);
void					print_elements(t_data *data);

//src/utils2.c
void					free_mlx(t_data *data);
void					free2d(void **content);
void					init_data(t_data *data);
int						free_data(t_data *data);
void					init_draw(t_data *data);

//src/ray_cast/ray_cast.c
void					draw_rays(t_data *data);
void			draw_line(t_data *data, t_raycast *oray);
int	draw_line_loop(t_data *data, t_raycast *ray, t_raycast *oray);
//src/ray_cast/ray_cast_utils.c
void					init_help_nearest_horizontal_line(t_raycast *ray);
void					init_nearest_vertical_line(t_data *data,
							t_raycast *ray);
void					init_nearest_horizontal_line(t_data *data,
							t_raycast *ray);
int						nearest_vertical_line_main_loop(t_data *data,
							t_raycast *ray);
int						nearest_horizontal_line_main_loop(t_data *data,
							t_raycast *ray);

//src/ray_cast/ray_cast_equations1.c
int						hit_wall(t_raycast *ray, t_data *data);
void					init_help_nearest_horizontal_line(t_raycast *ray);
void					nearest_vertical_line(t_data *data, t_raycast *ray);
void					nearest_horizontal_line(t_data *data, t_raycast *ray);
float					cal_vert_horz_displacement(t_raycast *ray,
							t_data *data);

//src/ray_cast/ray_cast_equations2.c
float					grid_sinpping(float num, int pixel);
void					map_to_grid(t_raycast *ray, t_data *data);
int						is_valid_bounds(t_raycast *ray, t_data *data);
float					intersection_point_x(float px, float tan, float py,
							float ray_x);
float					intersection_point_y(float px, float tan, float py,
							float ray_y);

//src/ray_cast/ray_cast_equations3.c
float					deg_to_rad(float angle);
void					init_raycast(t_raycast *ray);
void					reset_ray_angle(float *angle);
void					set_nearest_line(t_raycast *ray);
void					set_start_end_line(t_data *data, t_raycast *ray);

void					draw_3drays(t_data *data);
void					draw_2drays(t_data *data);
void					draw_floor_ceiling(t_data *data);


#endif