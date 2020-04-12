/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:39:21 by tquence           #+#    #+#             */
/*   Updated: 2020/03/05 18:39:22 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		count_let(char **c)
{
	int k;

	k = 0;
	while (**c != '-' && **c != 0)
	{
		(*c)++;
		k++;
	}
	return (k);
}

t_room		**new_rooms_array(t_listl *list)
{
	t_room **arr_rooms;
	int		i;

	i = 0;
	arr_rooms = (t_room **)ft_memalloc(sizeof(t_room *) * rm);
	while (list)
	{
		arr_rooms[i] = (t_room *)ft_memalloc(sizeof(t_room));
		arr_rooms[i] = (t_room *)list->data;
		i++;
		list = list->next;
	}
	return (arr_rooms);
}

void		valid_links(char *map, t_room **arr)
{
	int i;

	i = 0;
	while(map[i] != 0)
	{
		if (binSearch(arr, &map, rm) != -1)
		{
			if (map[i++] != '-')
			exit (1);
		}
		if (binSearch(arr, &map, rm) != -1)
			i++;
	}
}

// void		valid_links(char *map, t_listl *list)
// {
// 	int i;
// 	t_listl *p;
// 	t_room *tmp;

// 	i = 0;
// 	p = list;
// 	while(map[i] != 0)
// 	{
// 		while (p != NULL)
// 		{
// 			tmp = (t_room *)p->data;
// 			if (ft_strncmp(tmp->name, &map[i], count_let(&map[i])) == 0)
// 			{
// 				while (map[i] != '-')
// 					i++;
// 				break;
// 			}
// 			p = p->next;
// 		}
// 		if (map[i++] != '-')
// 			exit (1);
// 		p = list;
// 		tmp = (t_room *)p->data;
// 		while (p != NULL)
// 		{
// 			tmp = (t_room *)p->data;
// 			if (ft_strncmp(tmp->name, &map[i], count_let(&map[i])) == 0)
// 			{
// 				while (map[i] != '-' && map[i] != 0)
// 					i++;
// 				// break;
// 			}
// 			p = p->next;
// 		}
// 	}
// }

char		*ft_word_dup(const char *s1)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != ' ')
		++i;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = 0;
	while (j < i)
	{
		str[j] = s1[j];
		++j;
	}
	return (str);
}

t_room	*new_room(char *map)
{
	int i;
	t_room *room;

	room = (t_room *)ft_memalloc(sizeof(t_room));
	i = 0;
	if ((ft_isprint(map[i]) == 1) && map[i] != 'L' && map[i] != '#')
		room->name = ft_word_dup(map);
	while (map[i] != 0)
		i++;
	rm++;
	return (room);
}

void	init_ants(char *map, t_graph *graph)
{
	if (ft_isdigit(*map) == 1)
		graph->ants = ft_atoi(map);
	while (*map != 0)
		map++;
}

void	list_new(char *map, t_listl **first)
{
	static t_listl *curr;
	t_listl	*new;

	if (!(new = (t_listl *)ft_memalloc(sizeof(t_listl))))
		exit (1);
	new->data = new_room(map);
	if (!curr)
		*first = new;
	else
		curr->next = new;
	curr = new;
}

int			count_argc(char *map)
{
	int		k;
	int		i;

	k = 0;
	i = 0;
	if (!map)
		return (0);
	if (map[0] != ' ')
		k++;
	while (map[i] != 0)
	{
		if ((map[i] == ' ') && ((map[i + 1] != ' ' && map[i + 1])))
			k++;
		i++;
	}
	return (k);
}

t_listl	*parse_map(char *map, t_listl **list)
{
	list_new(map, list);
	return (*list);
}

// void	list_new(char *map, t_listl **first)
// {
// 	static t_listl *curr;
// 	t_listl	*new;

// 	if (!(new = (t_listl *)ft_memalloc(sizeof(t_listl))))
// 		exit (1);
// 	new->data = new_link(map);
// 	if (!curr)
// 		*first = new;
// 	else
// 		curr->next = new;
// 	curr = new;
// }

t_graph		*valid(char **map, t_graph *graph)
{
	int i;
	t_listl *list;
	t_room **rooms;

	i = 0;
	if (count_argc(map[i]) == 1 || *(map[i]) == '#')
	{
		while (*(map[i]) == '#')
			i++;
		init_ants(map[i++], graph);
		graph->fa = 1;
	}
	else
		exit(1);
	while (*(map[i]) == '#')
		i++;
	while (graph->fa == 1 && (count_argc(map[i]) == 3 || *(map[i]) == '#'))
	{
		if (*(map[i]) == '#')
			i++;
		else
		{
			list = parse_map(map[i++], &list);
			graph->fr = 1;
		}
	}
	sort(list);
	rooms = new_rooms_array(list);
	while (graph->fa ==1 && graph->fr == 1 && (map[i] != 0 && (count_argc(map[i]) == 1 || *(map[i]) == '#')))
	{
		if (*(map[i]) == '#')
			i++;
		valid_links(map[i++], rooms);
	}
	if (map[i] != 0)
		exit (1);
	graph->rooms = list;
	return (graph);
}
