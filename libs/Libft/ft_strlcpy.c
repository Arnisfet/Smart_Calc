/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:29:29 by mrudge            #+#    #+#             */
/*   Updated: 2021/10/08 18:29:34 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Коприует из строки src  в строку dest не более чем n-1 символов и
устанавливает в конец строки нулевой символ
Возвращает размер строки по исходному массиву*/

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (src[i] && i < (n - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}