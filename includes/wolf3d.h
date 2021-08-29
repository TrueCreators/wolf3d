/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:58:08 by sreicher          #+#    #+#             */
/*   Updated: 2020/11/06 14:21:43 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <OpenCL/opencl.h>

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include <fcntl.h>
# include <stdio.h>
# define MAX_SOURCE_SIZE (0x400000)
# define RGB(r, g, b) (r << 16 | g << 8 | b)

enum		e_mkey
{
	MK_LEFT = 1,
	MK_RIGHT,
	MK_SCRLUP = 4,
	MK_SCRLDOWN
};
enum		e_nkey
{
	NK_PLUS = 69,
	NK_MINUS = 78,
	NK_N0 = 82,
	NK_N1,
	NK_N2,
	NK_N3,
	NK_N4,
	NK_N5,
	NK_N6,
	NK_N7,
	NK_N8 = 91,
	NK_N9
};
enum		e_key
{
	K_A = 0,
	K_S,
	K_D,
	K_W = 13,
	K_ESC = 53,
	K_LEFT = 123,
	K_RIGHT,
	K_DOWN,
	K_UP,
	K_PLUS = 24,
	K_MINUS = 27,
	K_BACKSPACE = 51,
	K_H = 4
};

typedef struct			s_win
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					x_win;
	int					y_win;
	char				*n_win;
}						t_win;

typedef struct			s_img
{
	void				*img_ptr;
	int					*data;
	int					bpp;
	int					size_line;
	int					endian;
}						t_img;

typedef struct			s_imgbut
{
	void				*img_ptr;
	int					*data;
	int					bpp;
	int					size_line;
	int					endian;
}						t_imgbut;

typedef	struct			s_butt
{
	int					size_x;
	int					size_y;
	int					pos_x;
	int					pos_y;
	char				*text;
	int					color_button;
	int					color_text;
}						t_butt;

typedef struct			s_flag
{
	int					mouse;
	int					menu_glb;
	int					menu;
	int					move_menu;
	int					background;
	int					change_wolf;
	int					settings;
	int					controls;
	int					color;
	int					helpingame;
}						t_flag;

typedef struct			s_xyz
{
	int					x;
	int					y;
	int					z;
}						t_xyz;

typedef struct			s_tex
{
	void				*img;
	char				*data;
	int					bpp;
	int					sizeline;
	int					endian;
}						t_tex;

typedef struct			s_map
{
	int					width;
	int					height;
	char				***temp;
	t_xyz				*vertices;
	t_xyz				**vertices2;
	unsigned int		color;
}						t_map;

typedef	struct			s_player
{
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				camera_x;
	double				ray_pos_x;
	double				ray_pos_y;
	double				ray_dir_x;
	double				ray_dir_y;
	double				time;
	double				oldtime;
	bool				valid;
}						t_player;

typedef struct			s_move
{
	clock_t				start;
	clock_t				end;
	double				time;
	double				oldtime;
	double				frametime;
	double				movespeed;
	double				rotspeed;
	double				olddirx;
	double				oldplanex;
}						t_move;

typedef struct			s_raycast
{
	int					mapx;
	int					mapy;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	double				perpwalldist;
	int					stepx;
	int					stepy;
	int					lineheight;
	int					drawstart;
	int					drawend;
	int					hit;
	int					side;
	unsigned int		color;
}						t_raycast;

typedef struct			s_env
{
	t_tex				tex[9];
	t_map				*map;
	t_win				*win;
	t_img				img;
	t_player			*plr;
	t_raycast			*rc;
	t_move				*move;
	t_imgbut			img_butt;
	t_butt				*button;
	t_flag				flag;
}						t_env;

void					raycasting2(t_env *e);
void					raycasting3(t_env *e);
void					raycasting4(t_env *e);

void					wolf3d(char *file);
void					error_exit(char *str);
void					faq_message(void);
void					parsing_map(t_env *e, t_map *map, char *file);
void					freeall(char **splt_line, char *line);
void					raycasting(t_env *e, int i);

int						one_string(char *file);
void					lenght_xy(char fd, t_map *map, char *file);
void					map_to_array(char fd, t_map *map);
void					ft_init_player(t_env *e, int i, int x, int y);
void					map_validation(t_player *player, t_map *map, int i);
t_xyz					**create_map(t_map *map);
void					init_map_content(t_env *e, t_map *map, int i);

void					ft_init_player(t_env *e, int i, int x, int y);
void					move(int keycode, t_env *e);
void					move2(int keycode, t_env *e);

int						key_press(int keycode, t_env *e);
int						key_change_window(int keycode, t_env *e);
int						manipulate(int keycode, t_env *e);
int						move3(int keycode, t_env *e);
int						close_programm(void *param);
int						mouse_press(int	button, int x, int y, t_env *e);
int						mouse_move(int x, int y, t_env *e);

int						animation_menu(t_env *e);
void					color_menu(t_env *e, int i);
void					init_menu(t_env *e, int x_win, int y_win);
void					init_menu_press(t_env *e, int x_win, int y_win);
void					main_menu(t_env *e);
void					menu_text(t_env *e);

void					button_play_canvas(t_env *e);
void					button_settings_e_canvas(t_env *e);

void					create_button(t_env *e, t_butt *butt);
void					button_pressed(int button, int x, int y, t_env *e);

void					draw(t_env *e);
void					init_win_img(t_env *e);
void					ft_init_move(t_env *e);
#endif
