/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedacax <fedacax@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 11:44:23 by fedacax           #+#    #+#             */
/*   Updated: 2026/09/23 14:33:41 by fedacax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freemem(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
}

static void	ft_putwords(char **arr, char const *str, char c)
{
	int	i;
	int	j;
	int	start_letter;

	j = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] == 0)
			break ;
		start_letter = i;
		while (str[i] && str[i] != c)
			i++;
		arr[j] = ft_substr(str, start_letter, i - start_letter);
		j++;
	}
	arr[j] = NULL;
}

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	in_word;
	int	cw;

	in_word = 1;
	cw = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c && !in_word)
			in_word = 1;
		if (str[i] != c && in_word)
		{
			in_word = 0;
			cw++;
		}
		i++;
	}
	return (cw);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		size;
	int		i;

	size = ft_count_words(s, c);
	arr = ft_calloc(size + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	ft_putwords(arr, s, c);
	i = 0;
	while (i < size)
	{
		if (arr[i] == NULL)
		{
			ft_freemem(arr, size);
			return (NULL);
		}
		i++;
	}
	return (arr);
}
