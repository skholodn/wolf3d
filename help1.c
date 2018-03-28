/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 11:33:07 by skholodn          #+#    #+#             */
/*   Updated: 2017/04/02 12:30:49 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	rc_draw(t_wolf *w, t_point *p)
{
	if (SIDE == 0)
		PER_WALL_DIST = (MAP_X - RAY_POS_X + (1 - STEP_X) / 2) / RAY_DIR_X;
	else
		PER_WALL_DIST = (MAP_Y - RAY_POS_Y + (1 - STEP_Y) / 2) / RAY_DIR_Y;
	LINE_HEIGHT = (int)(SCHEIGHT / PER_WALL_DIST);
	DRAW_START = -(LINE_HEIGHT) / 2 + SCHEIGHT / 2;
	DRAW_START = (DRAW_START < 0 ? 0 : DRAW_START);
	DRAW_END = LINE_HEIGHT / 2 + SCHEIGHT / 2;
	DRAW_END = (DRAW_END >= SCHEIGHT ? (SCHEIGHT - 1) : DRAW_END);
	rc_color_switch(w, p);
	if (SIDE == 1)
	{
		p->rgb[0] = (p->rgb[0] == 0 ? 0 : p->rgb[0] / 2);
		p->rgb[1] = (p->rgb[1] == 0 ? 0 : p->rgb[1] / 2);
		p->rgb[2] = (p->rgb[2] == 0 ? 0 : p->rgb[2] / 2);
	}
	draw_verline(w, p);
	draw_text(w, w->rc->draw_start, w->rc->draw_end);
	draw_up_floor(w);
}

void	rc_camera(t_wolf *w)
{
	CAMERA_X = 2 * X / (double)(SCWIDTH) - 1;
	RAY_POS_X = POS_X;
	RAY_POS_Y = POS_Y;
	RAY_DIR_X = DIR_X + PLANE_X * CAMERA_X;
	RAY_DIR_Y = DIR_Y + PLANE_Y * CAMERA_X;
	MAP_X = (int)RAY_POS_X;
	MAP_Y = (int)RAY_POS_Y;
	DELTA_DIST_X = sqrt(1 + pow(RAY_DIR_Y, 2) / pow(RAY_DIR_X, 2));
	DELTA_DIST_Y = sqrt(1 + pow(RAY_DIR_X, 2) / pow(RAY_DIR_Y, 2));
	HIT = 0;
}

void	rc_ray_select(t_wolf *w)
{
	if (RAY_DIR_X < 0)
	{
		STEP_X = -1;
		SIDE_DIST_X = (RAY_POS_X - MAP_X) * DELTA_DIST_X;
	}
	else
	{
		STEP_X = 1;
		SIDE_DIST_X = (MAP_X + 1.0 - RAY_POS_X) * DELTA_DIST_X;
	}
	if (RAY_DIR_Y < 0)
	{
		STEP_Y = -1;
		SIDE_DIST_Y = (RAY_POS_Y - MAP_Y) * DELTA_DIST_Y;
	}
	else
	{
		STEP_Y = 1;
		SIDE_DIST_Y = (MAP_Y + 1.0 - RAY_POS_Y) * DELTA_DIST_Y;
	}
}

void	rc_ray_search(t_wolf *w)
{
	while (HIT == 0)
	{
		if (SIDE_DIST_X < SIDE_DIST_Y)
		{
			SIDE_DIST_X += DELTA_DIST_X;
			MAP_X += STEP_X;
			SIDE = 0;
		}
		else
		{
			SIDE_DIST_Y += DELTA_DIST_Y;
			MAP_Y += STEP_Y;
			SIDE = 1;
		}
		HIT = (WLD[MAP_X][MAP_Y] > 0 ? 1 : 0);
	}
}
