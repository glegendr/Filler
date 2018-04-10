/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:17:11 by glegendr          #+#    #+#             */
/*   Updated: 2018/04/10 18:54:25 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			del_queue(t_vec *vec, int ret)
{
	v_del(vec);
	return (ret);
}

void		print_result(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

void		know_distance_neg(t_map *map, int y, int x, t_score *sc)
{
	int dis_y;
	int dis_x;

	dis_x = 0;
	dis_y = 0;
	while (x - dis_x > 0 || y - dis_y > 0)
	{
		if (!who_is_it(map, y - dis_y, x - dis_x) && sc->score > dis_y + dis_x)
			sc->score = dis_y + dis_x;
		if (x - dis_x > 0)
			++dis_x;
		else
		{
			++dis_y;
			dis_x = 0;
		}
	}
}

void		know_distance(t_map *map, int y, int x, t_score *sc)
{
	int dis_y;
	int dis_x;

	dis_x = 0;
	dis_y = 0;
	sc->score = map->height + map->length;
	while (dis_x + x != map->length - 1 || dis_y + y != map->height - 1)
	{
		if (!who_is_it(map, y + dis_y, x + dis_x) && sc->score > dis_y + dis_x)
			sc->score = dis_y + dis_x;
		if (dis_x + x != map->length - 1)
			++dis_x;
		else
		{
			++dis_y;
			dis_x = 0;
		}
	}
	know_distance_neg(map, y, x, sc);
}

void		sort_queue(t_vec *vec)
{
	int		i;
	int		y;
	t_score tmp;
	t_score tmp2;

	if ((y = v_size(vec)) < 2)
		return ;
	while (y > 0)
	{
		i = 0;
		while (i < v_size(vec) - 1)
		{
			tmp = *(t_score *)v_get(vec, i);
			tmp2 = *(t_score *)v_get(vec, i + 1);
			if (tmp.score < tmp2.score)
				v_swap(vec, i, i + 1);
			++i;
		}
		--y;
	}
}
