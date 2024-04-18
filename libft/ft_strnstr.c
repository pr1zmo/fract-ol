/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:22:05 by zelbassa          #+#    #+#             */
/*   Updated: 2023/11/11 23:07:17 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_ndl;

	len_ndl = 0;
	if (!*needle)
		return ((char *)haystack);
	len_ndl = strlen(needle);
	while (*haystack && len >= len_ndl)
	{
		if (!strncmp(haystack, needle, len_ndl))
			return ((char *)haystack);
		haystack ++;
		len --;
	}
	return (NULL);
}
/*
int main(int argc, char **argv)
{
	(void)argc;
	size_t nbr = 5;
	printf("mine  :%s\n", ft_strnstr(argv[1], argv[2], nbr));
	printf("theirs:%s", strnstr(argv[1], argv[2], nbr));
	return (0);
} */
