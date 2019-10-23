/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:26:24 by jphilip-          #+#    #+#             */
/*   Updated: 2018/12/11 20:50:38 by jphilip-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_count_words(s, c);
	if (!(arr = (char **)malloc(sizeof(*arr) * (len + 1))))
		return (NULL);
	while (len--)
	{
		while (*s && *s == c)
			s++;
		if (!(arr[i] = ft_strsub(s, 0, ft_word_len(s, c))))
		{
			while (i)
				free(arr[--i]);
			return (NULL);
		}
		s = s + ft_word_len(s, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
