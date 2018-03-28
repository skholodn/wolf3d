/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keykode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 12:36:08 by skholodn          #+#    #+#             */
/*   Updated: 2017/04/02 12:33:50 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move_up(t_wolf *w)
{
	if (WLD[(int)(POS_X + DIR_X * MOVE_SPEED)][(int)POS_Y] == 0)
		POS_X += DIR_X * MOVE_SPEED;
	if (WLD[(int)POS_X][(int)(POS_Y + DIR_Y * MOVE_SPEED)] == 0)
		POS_Y += DIR_Y * MOVE_SPEED;
}

void	move_down(t_wolf *w)
{
	if (WLD[(int)(POS_X - DIR_X * MOVE_SPEED)][(int)POS_Y] == 0)
		POS_X -= DIR_X * MOVE_SPEED;
	if (WLD[(int)POS_X][(int)(POS_Y - DIR_Y * MOVE_SPEED)] == 0)
		POS_Y -= DIR_Y * MOVE_SPEED;
}

void	move_right(t_wolf *w)
{
	OLD_DIR_X = DIR_X;
	DIR_X = DIR_X * cos(-ROT_SPEED) - DIR_Y * sin(-ROT_SPEED);
	DIR_Y = OLD_DIR_X * sin(-ROT_SPEED) + DIR_Y * cos(-ROT_SPEED);
	OLD_PLANE_X = PLANE_X;
	PLANE_X = PLANE_X * cos(-ROT_SPEED) - PLANE_Y * sin(-ROT_SPEED);
	PLANE_Y = OLD_PLANE_X * sin(-ROT_SPEED) + PLANE_Y * cos(-ROT_SPEED);
}

void	move_left(t_wolf *w)
{
	OLD_DIR_X = DIR_X;
	DIR_X = DIR_X * cos(ROT_SPEED) - DIR_Y * sin(ROT_SPEED);
	DIR_Y = OLD_DIR_X * sin(ROT_SPEED) + DIR_Y * cos(ROT_SPEED);
	OLD_PLANE_X = PLANE_X;
	PLANE_X = PLANE_X * cos(ROT_SPEED) - PLANE_Y * sin(ROT_SPEED);
	PLANE_Y = OLD_PLANE_X * sin(ROT_SPEED) + PLANE_Y * cos(ROT_SPEED);
}

int		use_key(int keycode, t_wolf *w)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 13)
		move_up(w);
	else if (keycode == 1)
		move_down(w);
	else if (keycode == 0)
		move_left(w);
	else if (keycode == 2)
		move_right(w);
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
		make_raycaster(w);
	return (0);
}
