/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 12:36:21 by skholodn          #+#    #+#             */
/*   Updated: 2017/04/02 12:37:19 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*map;
	char	c[1024];
	ssize_t	red;

	if (ac != 2)
		print_error("Need: <filename>.mff\n");
	map = ft_strnew(0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1 || fd == 0)
		print_error("READING ERROR!\n");
	while ((red = read(fd, c, 1023)))
	{
		c[red] = '\0';
		map = clear_copy(map, c);
	}
	next_map_parse(map);
	free(map);
	return (0);
}

char	*clear_copy(char *dst, char *src)
{
	char	*tmp;

	tmp = dst;
	dst = ft_strjoin(tmp, src);
	free(tmp);
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if ((str = malloc(size + 1)) == NULL)
		return (NULL);
	while (i < size + 1)
		str[i++] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ls1;
	size_t	ls2;
	size_t	i;
	size_t	j;
	char	*strnew;

	if (s1 && s2)
	{
		i = -1;
		ls1 = ft_strlen(s1);
		ls2 = ft_strlen(s2);
		strnew = ft_strnew(ls1 + ls2);
		if (!strnew)
			return (NULL);
		while (s1[++i])
			strnew[i] = s1[i];
		j = 0;
		while (s2[j])
			strnew[i++] = s2[j++];
		return (strnew);
	}
	return (NULL);
}
