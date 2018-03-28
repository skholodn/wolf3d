/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 07:36:09 by skholodn          #+#    #+#             */
/*   Updated: 2017/04/02 12:27:45 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_text(t_wolf *w, int s, int f)
{
	t_tx	t;

	t.txnb = WLD[MAP_X][MAP_Y];
	if (!(t.txnb == 1 || t.txnb == 2))
		return ;
	if (SIDE == 0)
		t.wallx = RAY_POS_Y + PER_WALL_DIST * RAY_DIR_Y;
	else
		t.wallx = RAY_POS_X + PER_WALL_DIST * RAY_DIR_X;
	t.wallx -= floor(t.wallx);
	t.tx_x = (int)(t.wallx * (double)TEX_H);
	if (SIDE == 0 && RAY_DIR_X > 0)
		t.tx_x = TEX_W - t.tx_x - 1;
	if (SIDE == 1 && RAY_DIR_Y < 0)
		t.tx_x = TEX_W - t.tx_x - 1;
	while (s != f)
	{
		t.d = (s << 8) - (SCHEIGHT << 7) + (LINE_HEIGHT << 7);
		t.tx_y = ((t.d * TEX_H) / (LINE_HEIGHT)) >> 8;
		t.color = img_pixel_get(t.tx_x, t.tx_y, &w->tx[t.txnb], w);
		img_pixel_put(w, X, s, t.color);
		s++;
	}
}

void	inside_draw_up_floor(t_wolf *w, t_fl *fl)
{
	if (SIDE == 0 && RAY_DIR_X > 0)
	{
		fl->f_wallx = MAP_X;
		fl->f_wally = MAP_Y + fl->wallx;
	}
	else if (SIDE == 0 && RAY_DIR_X < 0)
	{
		fl->f_wallx = MAP_X + 1.0;
		fl->f_wally = MAP_Y + fl->wallx;
	}
	else if (SIDE == 1 && RAY_DIR_Y > 0)
	{
		fl->f_wallx = MAP_X + fl->wallx;
		fl->f_wally = MAP_Y;
	}
	else
	{
		fl->f_wallx = MAP_X + fl->wallx;
		fl->f_wally = MAP_Y + 1.0;
	}
	fl->d_wall = PER_WALL_DIST;
	fl->d_plr = 0;
}

void	select_floor(t_wolf *w, t_fl *fl)
{
	fl->color = 0x8B4513;
	img_pixel_put(w, X, fl->y, fl->color);
	fl->color = 0xD3D3D3;
	img_pixel_put(w, X, SCHEIGHT - fl->y, fl->color);
}

void	draw_up_floor(t_wolf *w)
{
	t_fl	fl;

	inside_draw_up_floor(w, &fl);
	if (DRAW_END < 0)
		DRAW_END = SCHEIGHT;
	if (DRAW_END < SCHEIGHT)
		fl.y = DRAW_END - 1;
	else
		return ;
	fl.dist = 0;
	fl.floor_x = 0;
	fl.floor_y = 0;
	while (++fl.y != SCHEIGHT)
	{
		fl.dist = SCHEIGHT / (2. * fl.y - SCHEIGHT);
		fl.weight = (fl.dist - fl.d_plr) / (fl.d_wall - fl.d_plr);
		fl.floor_x = fl.weight * fl.f_wallx + (1.0 - fl.weight) * POS_X;
		fl.floor_y = fl.weight * fl.f_wally + (1.0 - fl.weight) * POS_Y;
		fl.f_tx_x = ((int)(fl.floor_x * TEX_W)) % TEX_W;
		fl.f_tx_y = ((int)(fl.floor_y * TEX_H)) % TEX_H;
		select_floor(w, &fl);
	}
}
