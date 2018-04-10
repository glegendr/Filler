/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_piece_placable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:58:07 by glegendr          #+#    #+#             */
/*   Updated: 2018/04/10 19:42:34 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			can_i_place(t_map *map, t_map *piece, int y_map, int x_map)
{
	int i;
	int y;
	int rep;

	rep = 0;
	i = 0;
	while (i < piece->height)
	{
		y = 0;
		if (i + y_map >= map->height && is_a_star_here(piece, i))
			return (0);
		else if (i + y_map >= map->height && !is_a_star_here(piece, i))
			break ;
		while (y++ < piece->length)
		{
			if (piece->map[i][y - 1] == '*' && y - 1 + x_map >= map->length)
				return (0);
			if (piece->map[i][y - 1] == '*')
				if (!is_place_free(map, i + y_map, y + x_map - 1, &rep))
					return (0);
		}
		++i;
	}
	return (rep);
}

t_score		where_is_other_player(t_map *map, t_map *piece, int y, int x)
{
	int		p_y;
	int		p_x;
	int		tmp_y;
	int		tmp_x;
	t_score score;

	score.y = y;
	score.x = x;
	tmp_y = piece->height;
	tmp_x = piece->length;
	p_y = 0;
	while (p_y < piece->height)
	{
		p_x = 0;
		while (p_x++ < piece->length)
			if (piece->map[p_y][p_x - 1] == '*' &&
					tmp_y + tmp_x > p_x - 1 + p_y)
			{
				tmp_y = p_y;
				tmp_x = p_x - 1;
			}
		++p_y;
	}
	know_distance(map, y + tmp_y, x + tmp_x, &score);
	return (score);
}

int			algo(t_map *map, t_map *piece)
{
	t_vec	queue;
	int		i;
	int		y;
	t_score tmp;

	queue = v_new(sizeof(t_score));
	i = 0;
	while (i < map->height)
	{
		y = 0;
		while (y++ < map->length)
			if (can_i_place(map, piece, i, y - 1))
			{
				tmp = where_is_other_player(map, piece, i, y - 1);
				v_push(&queue, &tmp);
			}
		++i;
	}
	if (v_size(&queue) == 0)
		return (del_queue(&queue, 0));
	sort_queue(&queue);
	tmp = *(t_score *)v_get(&queue, v_size(&queue) - 1);
	print_result(tmp.y, tmp.x);
	return (del_queue(&queue, 1));
}
