/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:53:07 by mrudge            #+#    #+#             */
/*   Updated: 2021/10/08 18:53:09 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Функция производит вырезание подстроки сет из строки s1 с начала и с конца с
выделением памяти под новый массив*/

#include "libft.h"

static int	ft_count(char const *s1, char c)
{
	while (*s1)
	{
		if (*s1 == c)
			return (1);
		s1++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;
	size_t	begin;
	char	*arr;

	end = ft_strlen(s1);
	i = 0;
	begin = 0;
	if (!s1 || !set)
		return ((char *)s1);
	while (s1[begin] && ft_count(set, s1[begin]))
		begin++;
	while (end > begin && ft_count(set, s1[end - 1]))
		end--;
	arr = (char *) malloc(end - begin + 1);
	if (!arr)
		return (NULL);
	while (end > begin)
	{
		arr[i] = s1[begin];
		i++;
		begin++;
	}
	arr[i] = '\0';
	return (arr);
}
