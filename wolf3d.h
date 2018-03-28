/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 11:32:39 by skholodn          #+#    #+#             */
/*   Updated: 2017/04/02 12:58:27 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

# define SCWIDTH 640
# define SCHEIGHT 480
# define TEX_W 64
# define TEX_H 64
# define X (w->rc->x)
# define CAMERA_X (w->rc->camera_x)
# define RAY_POS_X (w->rc->ray_pos_x)
# define RAY_POS_Y (w->rc->ray_pos_y)
# define POS_X (w->rc->pos_x)
# define POS_Y (w->rc->pos_y)
# define RAY_DIR_X (w->rc->ray_dir_x)
# define RAY_DIR_Y (w->rc->ray_dir_y)
# define DIR_X (w->rc->dir_x)
# define DIR_Y (w->rc->dir_y)
# define PLANE_X (w->rc->plane_x)
# define PLANE_Y (w->rc->plane_y)
# define MAP_X (w->rc->map_x)
# define MAP_Y (w->rc->map_y)
# define DELTA_DIST_X (w->rc->delta_dist_x)
# define DELTA_DIST_Y (w->rc->delta_dist_y)
# define WLD (w->wld->map)
# define HIT (w->rc->hit)
# define STEP_X (w->rc->step_x)
# define STEP_Y (w->rc->step_y)
# define SIDE_DIST_X (w->rc->side_dist_x)
# define SIDE_DIST_Y (w->rc->side_dist_y)
# define SIDE (w->rc->side)
# define PER_WALL_DIST (w->rc->perp_wall_dist)
# define LINE_HEIGHT (w->rc->line_height)
# define DRAW_START (w->rc->draw_start)
# define DRAW_END (w->rc->draw_end)
# define OLD_DIR_X (w->rc->old_dir_x)
# define OLD_PLANE_X (w->rc->old_plane_x)
# define ROT_SPEED (w->rc->rot_speed)
# define MOVE_SPEED (w->rc->move_speed)

# define DIGIT(d) (d >= '0' && d <= '9' ? 1 : 0)
# define ABS(x) (x < 0 ? -(x) : (x))

typedef struct	s_world
{
	int			**map;
	int			map_width;
	int			map_height;
}				t_world;

typedef struct	s_screen
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	int			sizeline;
	int			endian;
	char		*data;
}				t_screen;

typedef struct	s_raycast
{
	int			x;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		camera_x;
	double		ray_pos_x;
	double		ray_pos_y;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		old_dir_x;
	double		plane_x;
	double		plane_y;
	double		old_plane_x;
	double		time;
	double		old_time;
	double		frame_time;
	double		move_speed;
	double		rot_speed;
}				t_raycast;

typedef struct	s_text
{
	void		*img;
	int			w;
	int			h;
	int			color;
}				t_text;

typedef struct	s_wolf
{
	t_world		*wld;
	t_screen	*sc;
	t_raycast	*rc;
	t_text		*tx;
}				t_wolf;

typedef struct	s_tx
{
	int			txnb;
	double		wallx;
	int			tx_x;
	int			tx_y;
	int			d;
	int			color;
}				t_tx;

typedef struct	s_fl
{
	double		dist;
	double		floor_x;
	double		floor_y;
	double		weight;
	int			y;
	double		d_wall;
	double		d_plr;
	double		d_cur;
	double		f_wallx;
	double		f_wally;
	double		wallx;
	int			f_tx_x;
	int			f_tx_y;
	int			color;
}				t_fl;

typedef struct	s_point
{
	float		*rgb;
}				t_point;

t_wolf			*global_init(t_world *wld);
void			my_wolf(t_world *wld);
void			draw_verline(t_wolf *w, t_point *p);
int				close_kross(void *x);
void			make_raycaster(t_wolf *w);
int				use_key(int keycode, t_wolf *w);
void			draw_text(t_wolf *w, int s, int f);
void			draw_up_floor(t_wolf *w);
int				img_pixel_get(int x, int y, t_text *tx, t_wolf *w);
void			img_pixel_put(t_wolf *w, int x, int y, int rgb);
void			rc_draw(t_wolf *w, t_point *p);
void			rc_color_switch(t_wolf *w, t_point *p);
void			rc_camera(t_wolf *w);
void			rc_ray_select(t_wolf *w);
void			rc_ray_search(t_wolf *w);
t_point			*init_point(void);
void			null_rgb(t_point *p);
void			free_point(t_point *p);
void			new_img_create(t_wolf *w);
void			inject_color(int b, int g, int r, t_point *p);
int				close_kross(void *x);
void			next_map_parse(char *map);
void			basic_valid(char *str);
size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_strnew(size_t size);
void			print_error(char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
char			*clear_copy(char *dst, char *src);
int				ft_atoi(const char *s);

#endif
