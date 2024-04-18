/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:21:02 by zelbassa          #+#    #+#             */
/*   Updated: 2023/11/09 18:31:18 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
/* 
int main()
{
	char *str;
	char *str2;

	str = ft_calloc(10, sizeof(char));
	str2 = calloc(10, sizeof(char));
	printf("ft_calloc: %s\n", str);
	printf("calloc: %s\n", str2);
	return (0);	
} */