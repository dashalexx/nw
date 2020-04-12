/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:34:05 by tquence           #+#    #+#             */
/*   Updated: 2020/03/05 18:34:08 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

# define DEF_MAP_SIZE 20

int					rm;

typedef struct		s_listl
{
	void			*data;
	struct s_listl	*next;
}					t_listl;

typedef struct		s_room
{
	char			*name;
	t_listl			*links;
    int				distance;
	struct s_room	*parent;
    struct s_room	*pred;
	struct s_room	*succ;
}					t_room;

typedef struct		s_link
{
	int				weight;
	t_room			*dst;
}					t_link;

typedef struct		s_graph
{
    t_listl			*rooms;
    t_room			*start;
	t_room			*end;
	int				ants;
	int				flag;
	int				fa;
	int				fr;
	int				fl;
}					t_graph;

t_graph	*valid(char **map, t_graph *graph);
void	sort(t_listl *list);
char  **rooms_sort(t_listl *list);
char **qs(char **arr, int first, int last);
int binSearch(t_room **a, char **val, int size);
int		count_let(char **c);

#endif
