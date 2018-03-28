/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_wolf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:47:20 by skholodn          #+#    #+#             */
/*   Updated: 2017/04/02 12:39:05 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	rc_color_switch(t_wolf *w, t_point *p)
{
	if (WLD[MAP_X][MAP_Y] == 1)
		inject_color(255, 0, 0, p);
	else if (WLD[MAP_X][MAP_Y] == 2)
		inject_color(0, 255, 0, p);
	else if (WLD[MAP_X][MAP_Y] == 3)
		inject_color(0, 0, 255, p);
	else if (WLD[MAP_X][MAP_Y] == 4)
		inject_color(255, 255, 255, p);
	else if (WLD[MAP_X][MAP_Y] == 5)
	{
		p->rgb[0] = 0;
		p->rgb[1] = 255;
		p->rgb[2] = 0;
		p->rgb[3] = 240;
	}
	else
		inject_color(255, 255, 0, p);
}

void	make_raycaster(t_wolf *w)
{
	t_point *p;

	p = init_point();
	new_img_create(w);
	X = -1;
	while (++X < SCWIDTH)
	{
		rc_camera(w);
		rc_ray_select(w);
		rc_ray_search(w);
		rc_draw(w, p);
		null_rgb(p);
	}
	free_point(p);
	w->rc->old_time = w->rc->time;
	w->rc->time = clock();
	w->rc->frame_time = (w->rc->time - w->rc->old_time) / CLOCKS_PER_SEC;
	MOVE_SPEED = w->rc->frame_time * 15.5;
	ROT_SPEED = w->rc->frame_time * 9.5;
	mlx_put_image_to_window(w->sc->mlx, w->sc->win, w->sc->img, 0, 0);
}

void	get_player_pos(t_wolf *w)
{
	int		x;
	int		y;

	y = -1;
	while (++y < w->wld->map_height)
	{
		x = -1;
		while (++x < w->wld->map_width)
		{
			if (WLD[y][x] == 0 && WLD[y][x - 1] == 0 &&
					WLD[y - 1][x] == 0 && WLD[y][x + 1] == 0 &&
					WLD[y + 1][x] == 0)
			{
				POS_X = x;
				POS_Y = y;
				return ;
			}
		}
	}
	print_error("No place for player\n");
}

void	my_wolf(t_world *wld)
{
	t_wolf	*w;

	w = global_init(wld);
	get_player_pos(w);
	make_raycaster(w);
	mlx_hook(w->sc->win, 17, 0, close_kross, 0);
	mlx_hook(w->sc->win, 2, 0, use_key, w);
	mlx_loop(w->sc->mlx);
}
