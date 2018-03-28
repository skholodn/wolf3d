/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 18:30:31 by skholodn          #+#    #+#             */
/*   Updated: 2017/04/02 12:45:34 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_screen	*init_screen(void)
{
	t_screen	*sc;

	sc = malloc(sizeof(t_screen));
	sc->mlx = mlx_init();
	sc->win = mlx_new_window(sc->mlx, SCWIDTH, SCHEIGHT, "Wolf 3D");
	sc->img = mlx_new_image(sc->mlx, SCWIDTH, SCHEIGHT);
	return (sc);
}

t_raycast	*init_raycaster(void)
{
	t_raycast	*rc;

	rc = malloc(sizeof(t_raycast));
	rc->dir_x = -1;
	rc->dir_y = 0;
	rc->plane_x = 0;
	rc->plane_y = 0.66;
	rc->time = 0;
	rc->old_time = 0;
	return (rc);
}

t_text		*init_texture(t_wolf *w)
{
	t_text	*tx;

	tx = (t_text*)malloc(sizeof(t_text) * 4);
	tx[0].img = mlx_xpm_file_to_image(w->sc->mlx, "text/floor.xpm",
			&tx[0].w, &tx[0].h);
	tx[1].img = mlx_xpm_file_to_image(w->sc->mlx, "text/brick1.xpm",
			&tx[1].w, &tx[1].h);
	tx[2].img = mlx_xpm_file_to_image(w->sc->mlx, "text/safe.xpm",
			&tx[2].w, &tx[2].h);
	tx[3].img = mlx_xpm_file_to_image(w->sc->mlx, "text/up.xpm",
			&tx[3].w, &tx[3].h);
	return (tx);
}

t_wolf		*global_init(t_world *wld)
{
	t_wolf	*w;

	w = malloc(sizeof(t_wolf));
	w->sc = init_screen();
	w->wld = wld;
	w->rc = init_raycaster();
	w->tx = init_texture(w);
	return (w);
}
