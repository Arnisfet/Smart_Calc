/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:24:34 by mrudge            #+#    #+#             */
/*   Updated: 2021/10/08 18:24:36 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Функция заполняет массив s1,  символом с n раз и возвращает массив s1*/

#include "libft.h"

void	*ft_memset(void *s1, int c, size_t n)
{
	unsigned char	*p1;
	unsigned char	p2;
	size_t			i;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char)c;
	while (i++ < n)
		*p1++ = p2;
	return (s1);
}