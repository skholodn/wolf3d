/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:17:34 by skholodn          #+#    #+#             */
/*   Updated: 2017/04/02 12:40:53 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	fill_world(char *map, t_world *wld)
{
	int		x;
	int		y;
	int		n;

	y = -1;
	while (++y < wld->map_height)
	{
		x = -1;
		while (++x < wld->map_height)
		{
			if (DIGIT(*map) || *map == '-' || *map == '+')
			{
				n = ft_atoi(map);
				if (n > wld->map[y][x] || n == -1)
					wld->map[y][x] = n;
				while (*map && (DIGIT(*map) || *map == '-' || *map == '+'))
					map++;
			}
			if (*map == ' ')
				map++;
		}
		map = ft_strchr(map, '\n') + 1;
	}
}

void	map_scope(t_world *wld)
{
	int		x;
	int		y;

	y = -1;
	while (++y < wld->map_height)
	{
		x = -1;
		while (++x < wld->map_width)
		{
			if (y == 0 || x == 0 || y == (wld->map_height - 1)
					|| x == (wld->map_width - 1))
				wld->map[y][x] = 1;
			else
				wld->map[y][x] = 0;
		}
	}
}

t_world	*init_world(char **map)
{
	t_world	*wld;
	int		y;

	wld = (t_world *)malloc(sizeof(t_world));
	wld->map_width = ft_atoi(*map);
	*map = ft_strchr(*map, ' ') + 1;
	wld->map_height = ft_atoi(*map);
	*map = ft_strchr(*map, '\n') + 1;
	!(wld->map_width && wld->map_height) ? print_error("Bad keys\n") : 0;
	wld->map = malloc(sizeof(int*) * wld->map_height);
	y = -1;
	while (++y < wld->map_height)
		wld->map[y] = malloc(sizeof(int) * wld->map_width);
	map_scope(wld);
	return (wld);
}

void	next_map_parse(char *map)
{
	t_world	*wld;

	basic_valid(map);
	wld = init_world(&map);
	fill_world(map, wld);
	my_wolf(wld);
}
