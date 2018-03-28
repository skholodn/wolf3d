/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 21:29:05 by skholodn          #+#    #+#             */
/*   Updated: 2017/04/02 12:32:30 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	print_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(-1);
}

int		close_kross(void *x)
{
	x = NULL;
	exit(0);
	return (0);
}
