/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_yes_no.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:22:15 by skholodn          #+#    #+#             */
/*   Updated: 2017/04/02 12:43:44 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	valid_key(char *str, int *i)
{
	int		key;

	key = 0;
	while (*str && *str != '\n')
	{
		if (DIGIT(*str))
		{
			if (DIGIT(*str) && (*(str + 1) == ' ' || *(str + 1) == '\n'))
				key++;
			str++;
		}
		else if (*str == ' ')
			str++;
		else
			print_error("Bad characters in key line\n");
	}
	if (key != 2)
		print_error("Bad key characters\n");
	*i = 1;
}

void	basic_valid(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (i == 0)
			valid_key(str, &i);
		if (!(DIGIT(*str) || *str == ' ' || *str == '\n'
					|| *str == '-' || *str == '+'))
			print_error("Bad map characters\n");
		if (*str == '\n' && !DIGIT(*(str + 1)))
		{
			if (*str == '\n' && *(str + 1) != 0)
				print_error("Bad characters after new line\n");
		}
		if (*str == ' ' && !(DIGIT(*(str + 1))
					|| *(str + 1) == '-' || *(str + 1) == '+'))
			print_error("Bad spacing\n");
		str++;
	}
	if (*(str - 1) != '\n')
		print_error("Bad characters before end of file\n");
}
