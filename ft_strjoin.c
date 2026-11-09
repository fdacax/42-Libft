/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedacax <fedacax@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:02:52 by fedacax           #+#    #+#             */
/*   Updated: 2026/11/09 18:37:28 by fedacax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	total;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	total = (ft_strlen(s2) + s1_len + 1);
	str = ft_calloc(sizeof(char), total);
	if (!str)
		return (NULL);
	ft_strlcpy (str, s1, s1_len + 1);
	ft_strlcat (str, s2, total);
	return (str);
}
