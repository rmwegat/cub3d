/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:49:57 by rwegat            #+#    #+#             */
/*   Updated: 2023/11/02 18:00:23 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	wordcount;

	i = 0;
	wordcount = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			wordcount ++;
			while (s[i] != c && s[i])
				i++;
			i--;
		}
		i++;
	}
	return (wordcount);
}

void	free_split(char **str_array, int wordcount)
{
	while (wordcount >= 0)
	{
		free(str_array[wordcount]);
		wordcount--;
	}
	free(str_array);
}

char	**splitter(char const *s, char c, char **str_array, size_t wordcount)
{
	size_t	s_counter;
	size_t	a_counter;
	size_t	wordlen;

	s_counter = 0;
	a_counter = 0;
	wordlen = 0;
	while (s[s_counter] && a_counter < wordcount)
	{
		while (s[s_counter] == c)
			s_counter++;
		while (s[s_counter] != c && s[s_counter])
		{
			wordlen++;
			s_counter++;
		}
		str_array[a_counter] = ft_substr(s, s_counter - wordlen, wordlen);
		if (!str_array[a_counter])
			return (free_split(str_array, a_counter), NULL);
		wordlen = 0;
		a_counter++;
	}
	str_array[a_counter] = NULL;
	return (str_array);
}

char	**ft_split(char const *s, char c)
{
	char	**str_array;
	size_t	wordcount;

	if (!s)
		return (NULL);
	wordcount = count_words(s, c);
	str_array = (char **)malloc((wordcount + 1) * sizeof(char *));
	if (!str_array)
		return (NULL);
	return (splitter(s, c, str_array, wordcount));
}
