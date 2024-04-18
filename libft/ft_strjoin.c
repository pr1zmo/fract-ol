/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:21:45 by zelbassa          #+#    #+#             */
/*   Updated: 2023/11/10 15:35:00 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr = malloc(strlen(s1) + strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i ++;
	}
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i ++;
		j ++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/* 
int main()
{
	char const *s1 = "Hello there";
	char const *s2 = "!";
	printf("this: %s", ft_strjoin(s1, s2));
} */