/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:50:42 by mrudge            #+#    #+#             */
/*   Updated: 2021/10/08 18:50:51 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Функция итерируется по строке с, производя операции с каждым элементом
функцией ф, после, выделяя память под новый масиив арр и записывая
результаты в него*/

#include "libft.h"

char	*ft_strmapi(char const *c, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*arr;
	size_t			len_c;

	i = 0;
	if (!c || !f)
		return (NULL);
	len_c = ft_strlen(c);
	arr = (char *)malloc(sizeof(char) * (len_c + 1));
	if (!arr)
		return (NULL);
	while (c[i])
	{
		arr[i] = (*f)(i, c[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
