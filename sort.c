/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:52:32 by tquence           #+#    #+#             */
/*   Updated: 2020/03/10 18:52:33 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int binSearch(t_room **a, char **val, int size)
{
    int l;
	int r;

	l = 0;
	r = size - 1;
    while (r > l)
	{
        int m = (l + r) / 2;
        if (ft_strncmp((a[m])->name, *val, count_let(val)) < 0)
            l = m + 1;
		else if (ft_strncmp((a[m])->name, *val, count_let(val)) > 0)
            r = m - 1;
		else
            return m;
    }
    if (ft_strcmp(a[l]->name, *val) == 0)
        return (l);
	else
        return (-1);
}

void	sort(t_listl *list)
{
	char **sort;
	char **m;
	int i;

	i = 0;
	m = rooms_sort(list);
	// printf("%d", binSearch(m, "3", rm));
	sort = qs(m, 0, rm - 1);
	while (i < rm - 1)
	{
		if (ft_strcmp(sort[i], sort[i + 1]) == 0)
			exit(1);
		i++;
	}
	
}

char  **rooms_sort(t_listl *list)
{
	char **names;
	int i;
	t_listl *p;
	t_room *tmp;

	i = 0;
	p = list;
	names = (char **)ft_memalloc(sizeof(char *) * (rm + 1));
	while (i != rm)
	{
		tmp = (t_room *)p->data;
		names[i] = ft_strdup(tmp->name);
		i++;
		p = p->next;
	}
	names[i] = 0;
	return (names);
}

char **qs(char **arr, int first, int last)
{
	int left;
	int right;
	char *middle;

    if (first < last)
    {
        left = first;
		right = last;
		middle = ft_strdup(arr[(left + right) / 2]);
        while (left <= right)
        {
            while (ft_strcmp(arr[left], middle) < 0)
				left++;
            while (ft_strcmp(arr[right], middle) > 0)
				right--;
            if (left <= right)
            {
                char *tmp = ft_strdup(arr[left]);
                arr[left] = arr[right];
                arr[right] = tmp;
                left++;
                right--;
            }
        }
        qs(arr, first, right);
        qs(arr, left, last);
    }
	return (arr);
}

// int	main()
// {
// 	char **m;
// 	int i = 0;
// 	char	**arr;

// 	m = (char **)malloc(sizeof(char*) * 7);
// 	while (i != 7)
// 	{
// 		m[i] = (char *)ft_memalloc(sizeof(char) * 4);
// 		i++;
// 	}
// 	m[6] = 0;
// 	i = 0;
// 	m[0] = "e";
// 	m[1] = "a";
// 	m[2] = "df";
// 	m[3] = "dfd";
// 	m[4] = "fv";
// 	m[5] = "aa";
// 	arr = (char **)malloc(sizeof(char*) * 7);
// 	while (i != 7)
// 	{
// 		arr[i] = (char *)ft_memalloc(sizeof(char) * 2);
// 		i++;
// 	}
// 	arr[i] = 0;
// 	arr = qs(m, 0, 5);
// 	i = 0;
// 	while (i != 6)
// 	{
// 		printf("%s ", arr[i]);
// 		i++;
// 	}
// 	printf("%d", binSearch(arr, "e", 7));
// 	return (0);
// }
