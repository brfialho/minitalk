/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:38:15 by brfialho          #+#    #+#             */
/*   Updated: 2025/08/12 11:49:11 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static void	ft_free_all(char**split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;

	if (!s || !*s)
		return (0);
	words = 0;
	if (*s != c)
		words++;
	while (*s)
	{
		if (*(s + 1) && *s == c && *(s + 1) != c)
			words++;
		s++;
	}
	return (words);
}

static char	fill_split(char**split, char *s, char end)
{
	size_t	word;
	size_t	letter;

	word = 0;
	while (*s && *s == end)
		s++;
	while (*s)
	{
		letter = 0;
		while (s[letter] && s[letter] != end)
			letter++;
		split[word] = ft_calloc(letter + 1, sizeof(char));
		if (!split[word])
			return (0);
		letter = 0;
		while (*s && *s != end)
			split[word][letter++] = *s++;
		word++;
		while (*s && *s == end)
			s++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!split)
		return (0);
	if (fill_split(split, (char *)s, c))
		return (split);
	ft_free_all(split);
	return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char** split = ft_split(" 2 m  1", '\0');
// 	int i = -1;
// 	while(split[++i])
// 		printf("WORD %d: %s\n", i, split[i]);
// 	printf("last pointer:%p\n", split[i]);
// 	ft_free_all(split);
// }