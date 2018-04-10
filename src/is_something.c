/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_something.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:10:00 by glegendr          #+#    #+#             */
/*   Updated: 2018/04/10 19:39:26 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	give_height_value(t_map *map, char *s)
{
	char **tmp;

	tmp = NULL;
	tmp = ft_strsplit(s, ' ');
	map->height = ft_atoi(tmp[1]);
	map->length = ft_atoi(tmp[2]);
	del_tab(tmp);
}

int		is_place_free(t_map *map, int y, int x, int *rep)
{
	if (who_is_it(map, y, x) == 1 && *rep == 0)
		*rep = 1;
	else if (map->map[y][x] != '.')
		return (0);
	return (1);
}

int		is_last_action(char c)
{
	if (c == '.' || c == 'X' || c == 'O')
		return (0);
	else if (g_player == 1 && c == 'x')
		return (1);
	else if (g_player == 2 && c == 'o')
		return (1);
	else
		return (2);
}

int		who_is_it(t_map *map, int y, int x)
{
	if (map->map[y][x] == '.')
		return (2);
	if (g_player == 1)
	{
		if (map->map[y][x] == 'X' || map->map[y][x] == 'x')
			return (0);
		else
			return (1);
	}
	else
	{
		if (map->map[y][x] == 'X' || map->map[y][x] == 'x')
			return (1);
		else
			return (0);
	}
}

int		is_a_star_here(t_map *piece, int y)
{
	int i;

	i = 0;
	while (i < piece->length)
	{
		if (piece->map[y][i] == '*')
			return (1);
		++i;
	}
	return (0);
}
