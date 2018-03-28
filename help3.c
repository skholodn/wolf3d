/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 11:42:48 by skholodn          #+#    #+#             */
/*   Updated: 2017/04/02 12:31:40 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_point	*init_point(void)
{
	t_point	*p;

	p = malloc(sizeof(t_point));
	p->rgb = malloc(sizeof(float) * 4);
	p->rgb[0] = 0;
	p->rgb[1] = 0;
	p->rgb[2] = 0;
	p->rgb[3] = 0;
	return (p);
}

void	null_rgb(t_point *p)
{
	p->rgb[0] = 0;
	p->rgb[1] = 0;
	p->rgb[2] = 0;
	p->rgb[3] = 0;
}

void	free_point(t_point *p)
{
	free(p->rgb);
	free(p);
}

void	new_img_create(t_wolf *w)
{
	mlx_destroy_image(w->sc->mlx, w->sc->img);
	w->sc->img = mlx_new_image(w->sc->mlx, SCWIDTH, SCHEIGHT);
	w->sc->data = mlx_get_data_addr(w->sc->img, &(w->sc->bpp),
			&(w->sc->sizeline), &(w->sc->endian));
}

void	inject_color(int b, int g, int r, t_point *p)
{
	p->rgb[0] = b;
	p->rgb[1] = g;
	p->rgb[2] = r;
}
