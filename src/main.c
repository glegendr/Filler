/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:26:25 by glegendr          #+#    #+#             */
/*   Updated: 2018/04/10 19:33:01 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "filler.h"

void		divide_instructions(char **tab, t_map *map, t_map *piece)
{
	int i;

	i = 2;
	map->map = NULL;
	piece->map = NULL;
	give_height_value(map, tab[0]);
	while (ft_strcmp(tab[i], "Piece") != ' ')
	{
		map->map = tab_join(map->map, &(tab[i])[4]);
		++i;
	}
	give_height_value(piece, tab[i]);
	++i;
	while (tab[i])
	{
		piece->map = tab_join(piece->map, tab[i]);
		++i;
	}
	del_tab(tab);
}

char		**wait_ins(void)
{
	char	**tab;
	int		ret;
	char	*s;

	s = NULL;
	tab = NULL;
	while (1)
	{
		ret = get_next_line(0, &s);
		if (ret == 1)
		{
			tab = tab_join(tab, s);
			free(s);
			break ;
		}
	}
	return (tab);
}

char		**read_instructions(void)
{
	char	**tab;
	char	*s;
	char	**tmp;
	int		lignes;

	s = NULL;
	lignes = -1;
	tab = wait_ins();
	while (get_next_line(0, &s) == 1)
	{
		if (lignes == 0)
			break ;
		--lignes;
		tab = tab_join(tab, s);
		if (ft_strcmp(s, "Piece") == ' ')
		{
			tmp = ft_strsplit(s, ' ');
			lignes = ft_atoi(tmp[1]) - 1;
			del_tab(tmp);
		}
		free(s);
	}
	tab = tab_join(tab, s);
	free(s);
	return (tab);
}

int			player_choosen(void)
{
	int		ret;
	char	*s;
	char	**tmp;

	get_next_line(0, &s);
	tmp = ft_strsplit(s, ' ');
	ret = ft_atoi(&tmp[2][1]);
	free(s);
	del_tab(tmp);
	return (ret);
}

int			main(void)
{
	t_map map;
	t_map piece;

	g_player = player_choosen();
	while (1)
	{
		divide_instructions(read_instructions(), &map, &piece);
		if (!algo(&map, &piece))
			break ;
		del_tab(map.map);
		del_tab(piece.map);
	}
	del_tab(map.map);
	del_tab(piece.map);
	return (0);
}
