/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:35:22 by glegendr          #+#    #+#             */
/*   Updated: 2018/04/10 19:40:02 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "get_next_line.h"
# include "libft.h"
# include "libmem.h"
# include "vector.h"
# include "matrice.h"

int g_player;

typedef struct	s_map
{
	char	**map;
	int		height;
	int		length;
}				t_map;

typedef struct	s_score
{
	int		score;
	int		y;
	int		x;
}				t_score;
int				is_last_action(char c);
int				is_place_free(t_map *map, int y, int x, int *rep);
int				who_is_it(t_map *map, int y, int x);
int				is_a_star_here(t_map *piece, int y);
void			give_height_value(t_map *map, char *s);
int				del_queue(t_vec *vec, int ret);
void			print_result(int y, int x);
int				who_is_it(t_map *map, int y, int x);
void			know_distance(t_map *map, int y, int x, t_score *score);
int				is_last_action(char c);
void			sort_queue(t_vec *queue);
int				algo(t_map *map, t_map *piece);
#endif
