/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:52:01 by tquence           #+#    #+#             */
/*   Updated: 2019/04/26 16:30:48 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
	{
		while (*s1 == *s2 && n != 0 && *s1 != '\0' && *s2 != '\0')
		{
			s1++;
			s2++;
			n--;
		}
		if (n == 0 || (*s1 == '\0' && *s2 == '\0'))
			return (1);
	}
	return (0);
}
