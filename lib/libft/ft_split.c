/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 22:05:25 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/20 14:47:19 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	int		is_in_word;
	size_t	count;

	count = 0;
	is_in_word = FALSE;
	while (*s != '\0')
	{
		if (is_in_word && *s == c)
		{
			is_in_word = FALSE;
			count++;
		}
		else if (!is_in_word && *s != c)
			is_in_word = TRUE;
		s++;
	}
	if (is_in_word)
		count++;
	return (count);
}

static char	*fill_word(char const *s, char c, char **split_words)
{
	size_t	word_index;

	word_index = 0;
	while (s[word_index] != c && s[word_index] != '\0')
		word_index++;
	*split_words = (char *)malloc((word_index + 1) * sizeof(char));
	if (*split_words == NULL)
		return (NULL);
	ft_strlcpy(*split_words, s, word_index + 1);
	if (s[word_index] == '\0')
		return ("\0");
	return ((char *)s + word_index);
}

char	**ft_split(char const *s, char c)
{
	char	**split_words;
	char	**split_words_current;

	if (s == NULL)
		return (NULL);
	split_words = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (split_words == NULL)
		return (NULL);
	split_words_current = split_words;
	while (*s != '\0')
	{
		if (*s != c)
		{
			s = fill_word(s, c, split_words_current++);
			if (s == NULL)
				return (NULL);
		}
		s++;
	}
	*split_words_current = NULL;
	return (split_words);
}
