/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:52:28 by mrudge            #+#    #+#             */
/*   Updated: 2021/10/08 18:52:33 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Функция ищет последний входящий байт равный ch, работает как strchr.*/

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i;

	i = (size_t) ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i--;
	}
	if (str[i] == ch)
		return ((char *)str + i);
	return (NULL);
}
