/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:34:58 by tquence           #+#    #+#             */
/*   Updated: 2020/03/05 18:34:59 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	*ft_realloc(void *buf, size_t old, size_t new_size)
{
	unsigned char	*new_buf;

	if (!(new_buf = (unsigned char *)ft_memalloc(new_size)))
		exit(1);
	if (buf)
		ft_memcpy(new_buf, buf, old);
	free(buf);
	return (new_buf);
}

char	**read_map(char *fname)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;
	int		size;

	size = DEF_MAP_SIZE;
	if ((fd = open(fname, O_RDONLY)) < 0)
		return (NULL);
	i = 0;
	if (!(map = (char **)ft_memalloc(sizeof(char *) * size)))
		return (NULL);
	while ((get_next_line(fd, &line)) != 0)
	{
		if (i == size - 2)
		{
			size *= 2;
			map = ft_realloc(map, (sizeof(char *) * size) / 2,
					sizeof(char *) * size);
		}
		map[i++] = line;
	}
	map[i] = 0;
	close(fd);
	return (map);
}

int		main(int argc, char **argv)
{
	char **map;
	t_graph	*graph;

	if (argc != 2)
		return (0);
	rm = 0;
	if (!(graph = (t_graph *)ft_memalloc(sizeof(t_graph))))
		return (0);
	map = read_map(argv[1]);
	graph = valid(map, graph);
	while (*map != NULL)
	{
		ft_putstr(*map);
		ft_putchar('\n');
		map++;
	}
	
	return (0);
}
