/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:13:56 by zelbassa          #+#    #+#             */
/*   Updated: 2023/11/12 00:33:32 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_length(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i ++;
	return (i);
}

int	word_count(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] != c)
		count ++;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			count ++;
		i ++;
	}
	return (count);
}

char	*copy_word(char const *str, char sep)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (word_length(str, sep) + 1));
	i = 0;
	while (str[i])
	{
		word[i] = str[i];
		if (str[i] == sep)
			break ;
		i ++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!ptr)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			if (!ptr[i])
				return (NULL);
			ptr[i] = copy_word(s, c);
			i ++;
		}
		while (*s != c && *s)
			s++;
	}
	ptr[i] = NULL;
	return (ptr);
}
