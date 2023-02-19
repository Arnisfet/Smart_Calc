/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:29:01 by mrudge            #+#    #+#             */
/*   Updated: 2021/10/08 18:29:05 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*функция конкатениркет строки и гарантированно устанавливает в конец строки
нулевой символ. Ctrlcat копирует н больше дест символовЮ
return: суммарная длина строк.*/
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	p_src;
	size_t	len_dst;
	size_t	len_src;
	int		i;

	i = 0;
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	p_src = 0;
	if (n < len_dst)
		return (len_src + n);
	while (src[i] && (len_dst + i + 1) < n)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
