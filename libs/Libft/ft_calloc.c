/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:15:44 by mrudge            #+#    #+#             */
/*   Updated: 2021/10/08 18:16:10 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Функция возващает указатель на блок памяти размером нам элементов размера
сайз*/
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	arr = malloc(size * num);
	if (!arr)
		return (NULL);
	while (i < (num * size))
	{
		arr[i] = '\0';
		i++;
	}
	return ((void *) arr);
}
