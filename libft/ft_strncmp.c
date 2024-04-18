/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:22:02 by zelbassa          #+#    #+#             */
/*   Updated: 2023/11/08 21:16:05 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i ++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/* 
int main()
{
	const char *s1 = "Hello there friendo";
	const char *s2 = "there";
	int i = 0;
	printf("%d", ft_strncmp((s1 + 6), s2, strlen(s2)));
	return (0);	
} */