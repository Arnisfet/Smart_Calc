/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:26:26 by mrudge            #+#    #+#             */
/*   Updated: 2021/10/18 16:05:23 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Функция итерируется по строке, подсчитывая слова при нахождении
разделительного символа с. Создает массив указателей куда записывается
каждое слово по отдельности.

place - указатель на точку входа записи в строке;
i - указатель на точку выхода записи в строке;

Use function: ft_count - подсчет слов*/

#include "libft.h"

static char	**ft_free(char **arr)
{
	int	i;

	i = 0;
	if (arr[i])
	{
		while (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
			i++;
		}
		free(arr);
		arr = NULL;
	}
	return (NULL);
}

static int	ft_count(const char *s, char c)
{
	size_t	i;
	int		counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			counter++;
		while ((s[i] != '\0') && (s[i] != c))
			i++;
	}
	return (counter);
}

static char	*ft_copy(const char *str, size_t n)
{
	char	*new;
	size_t	i;

	new = (char *)malloc(sizeof(char) * (n + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while ((str[i] != '\0') && (i < n))
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	size_t	i;
	size_t	place;
	int		word;

	new = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		place = i;
		while ((s[i] != '\0') && (s[i] != c))
			i++;
		if (place < i)
			new[word++] = ft_copy(s + place, i - place);
		if (!new[word - 1])
			ft_free((char **) new);
	}
	new[word] = NULL;
	return (new);
}
