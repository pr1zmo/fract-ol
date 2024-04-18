/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:22:10 by zelbassa          #+#    #+#             */
/*   Updated: 2024/04/03 02:30:57 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;
	char		*result;
	size_t		len;

	start = s1;
	end = s1 + ft_strlen(s1) - 1;
	while (*start && is_set(*start, set))
		start ++;
	while (end > start && is_set(*end, set))
		end --;
	if (end >= start)
		len = end - start + 1;
	else
		len = 0;
	result = malloc(len + 1);
	if (result)
		ft_strlcpy(result, start, len + 1);
	return (result);
}
