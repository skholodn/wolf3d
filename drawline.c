/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 08:26:56 by skholodn          #+#    #+#             */
/*   Updated: 2017/04/02 12:28:45 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_pixel(int x, int y, t_wolf *w, t_point *p)
{
	int		cord;

	if (x < SCWIDTH && y < SCHEIGHT && x >= 0 && y >= 0)
	{
		cord = ((y * w->sc->sizeline) + (x * w->sc->bpp / 8));
		w->sc->data[cord] = (char)p->rgb[0];
		w->sc->data[cord + 1] = (char)p->rgb[1];
		w->sc->data[cord + 2] = (char)p->rgb[2];
		w->sc->data[cord + 3] = (char)p->rgb[3];
	}
}

void	draw_verline(t_wolf *w, t_point *p)
{
	int		start;

	start = w->rc->draw_start;
	while (start < w->rc->draw_end)
	{
		put_pixel(w->rc->x, start, w, p);
		start++;
	}
}
