/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:24:38 by mcoppola          #+#    #+#             */
/*   Updated: 2024/04/11 00:22:52 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include "./get_next_line/get_next_line.h"
# include <stdio.h>
# include <math.h>

# define PI 3.14159265358979323846

// # define WIN_WIDTH 900
// # define WIN_HEIGHT 530
# define WIN_WIDTH 720
# define WIN_HEIGHT 405

# define MAP_WIDTH 180
// # define MAP_WIDTH 225
# define MAP_HEIGHT MAP_WIDTH
# define MAP_START_X 20
# define MAP_START_Y 20

# define IMG_SIZ 64

# define MAP_BIT 64

# define NO 0
# define SO 1
# define WE 2
# define EA 3

# define MOVESPEED 4
# define CAMERASPEED 4
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_RIGHT 65363
# define KEY_LEFT 65361

/* MINIMAP MACROS */
// # define MMAP_PIXEL_SIZE 128
// # define MMAP_VIEW_DIST 4
# define MMAP_COLOR_PLAYER 0x00FF00
// # define MMAP_COLOR_WALL 0x808080
// # define MMAP_color_fLOOR 0xE6E6E6
// # define MMAP_COLOR_SPACE 0x404040
// colors

# define COLOR_YELLOW 0xFFFF00 // WALKABLE
# define COLOR_RED 0xFF0000 //PLAYER
# define COLOR_GREEN 0x00FF00 // NOT WALKABLE
# define COLOR_BLUE 0x0000FF // DOORS
# define COLOR_PURPLE 0xFF00FF // DOORS
# define COLOR_BLACK 0x000000 // WALLS
# define TEMP_CEILING 0xF728AA
# define TEMP_FLOOR 0x808080

# define ERROR_TEXTURES "Error\nFile not found! Check the path of the textures!"
# define ERROR_CHAR_MAP "Error\nFound illegal charcacter inside the map!"
# define ERROR_CONFIG "Error\nMissing map configs or found after map!"

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define GREEN_BOLD "\033[1;32m"
# define RED_BOLD "\033[1;31m"
# define YELLOW_BOLD "\033[1;33m"
# define CYAN_BOLD "\033[1;36m"
# define BLUE_BOLD "\033[1;34m"
# define RESET "\033[0m"

typedef struct t_range
{
	int	start_inx;
	int	end_inx;
	int	start_outx;
	int	end_outx;
	int	start_iny;
	int	end_iny;
	int	start_outy;
	int	end_outy;
}				t_range;

typedef struct s_print_line_wall_helper
{
	int		s_x;
	float	ca;
	float	height;
	int		wall_start;
	int		wall_end;
	int		s_y;
	int		s_x_end;
	int		half_x;
	int		wall_wd;
	int		start_x;
	int		offff;
	int		tex_x;
	int		tex_y;
	t_range	r;
}				t_print_line_wall_helper;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
	int		endian;
}				t_texture;

typedef struct s_print_px_map_helper
{
	float	x2;
	float	y2;
	int		calc_x;
	int		calc_y;
}				t_print_px_map_helper;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_vector
{
	float	x;
	float	y;
}				t_vector;

typedef struct s_vector_int
{
	int	x;
	int	y;
}				t_vector_int;

typedef struct s_render
{
	short	fov;
}				t_render;

typedef struct s_map
{
	t_vector	*p_pos;
	float		degree;
	char		*name;
	int			width;
	int			height;
	char		**map_matrix;
	char		*path_n;
	char		*path_s;
	char		*path_e;
	char		*path_w;
	int			*color_f;
	int			*color_c;
}				t_map;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	int				px_mv;
	t_image			*canva;
	t_map			*map;
	t_render		*render;
	t_texture		*texture;
	unsigned int	**col_mtrx_texts[4];
	int				mouse_x_pos;
	unsigned int	hex_col_f;
	unsigned int	hex_col_c;
	int				movespeed;
	char			*tmp;
	float			tmp_float;
	int				err;
	int				ray_offset;
}				t_game;

// LIBFT
char				*ft_strstr(const char *haystack, const char *needle);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strdup(const char *s1);
char				**ft_split(char const *s, char c);
int					ft_atoi(const char *str);
char				*ft_strtrim(char const *s1, char *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);

// DEBUG

void				print_player_position(t_game *game);

// FREE
void				free_game(t_game *game, short stage);

// CLOSE GAME
void				ft_close_game(t_game *game, short stage, char *message);
int					ft_end_game(t_game *game);

// MAP
void				ft_map_checker(t_game *game, int argc, char **argv);
void				full_check(t_game *game);
int					check_condition_no(t_game *game, char *line, int gm_h);
int					check_condition_so(t_game *game, char *line, int gm_h);
int					check_condition_we(t_game *game, char *line, int gm_h);
int					check_condition_ea(t_game *game, char *line, int gm_h);
int					check_condition_f(t_game *game, char *line, int gm_h);
int					check_condition_c(t_game *game, char *line, int gm_h);
void				check_widht(t_game *game, int line_len);
void				read_map_condition_h(t_game *game, char *line,
						int *line_len);
int					is_numeric(char *str);
int					check_numbers(const char *str);
int					check_is_empty(char **matrix, int i);
int					check_dbl_comma(char *s, char c);
int					*convert_to_int_arr(char **matrix, int size);
int					*string_to_num_arr(char *string, char divider);

// UTILS
int					is_space(char c);
int					is_content(char c);
int					is_player(char c);
int					is_digit(char c);
int					change_rangey(t_range r, int input);
int					change_rangex(t_range r, int input);

// TEST
void				my_mlx_pixel_put(t_image *data, int x, int y, int color);

// RENDER
void				my_mlx_pixel_put(t_image *data, int x, int y, int color);
void				minimap_init(t_game *game);// MINIMAP
int					update_player_pos(t_game *game);
void				line_length_calcultor_helper_1(float *line_lenght,
						t_vector_int *end, t_vector_int start,
						float directionRadians);
void				line_length_calcultor_helper_2(float directionRadians,
						int *side);
void				line_length_calcultor_helper_3(float directionRadians,
						int *side);
void				line_length_calcultor_helper_4(t_game *game,
						t_vector_int end);
void				line_length_calcultor_helper_5(t_game *game,
						t_vector_int end);
void				print_line_wall_helper_1(t_game *game, float *line_length,
						float deg, t_print_line_wall_helper *var);
void				print_line_wall_helper_2(t_game *game, float i,
						t_print_line_wall_helper *var);
void				print_line_wall_helper_3(t_game *game, float i, int side,
						t_print_line_wall_helper *var);
// void				minimap_update(t_game *game);

void				player_direction(int x, int y, int end_x, int end_y);
void				draw_straight_line_from_player(t_game *game,
						float directionDegrees);
void				drawer(t_game *game);

// INPUT
int					on_input(int key, void *param);
int					on_mouse_move(int x, int y, void *param);
void				movement_rotate(int key, t_game *game);
void				movement_move_ws(int key, t_game *game);
void				movement_move_ad(int key, t_game *game);

//TEXTURES_UTILS
unsigned int		get_color(t_texture *texture, int x, int y);
void				create_texture_matrix(t_game *game, char *path, int text_i);
unsigned int		rgb_to_hex(int rgb[3]);

#endif
