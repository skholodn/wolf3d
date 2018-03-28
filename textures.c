/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 13:40:42 by skholodn          #+#    #+#             */
/*   Updated: 2017/04/02 12:42:38 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	img_pixel_put(t_wolf *w, int x, int y, int rgb)
{
	unsigned int	tmp;

	tmp = (mlx_get_color_value(w->sc->mlx, rgb));
	if (x >= 0 && x <= SCWIDTH && y >= 0 && y <= SCHEIGHT)
		ft_memcpy((void*)(w->sc->data + y * SCWIDTH * (w->sc->bpp / 8))
				+ x * (w->sc->bpp / 8), &tmp, 4);
}

int		img_pixel_get(int x, int y, t_text *tx, t_wolf *w)
{
	int				bpp;
	int				sizeline;
	int				endian;
	char			*img;
	unsigned int	tmp;

	tmp = 0;
	img = mlx_get_data_addr(tx->img, &bpp, &sizeline, &endian);
	if (x >= 0 && x <= TEX_W && y >= 0 && y <= TEX_H && w)
		ft_memcpy((void*)(&tmp), (void*)(img + y * TEX_W * bpp / 8
					+ x * bpp / 8), 4);
	return (tmp);
}
