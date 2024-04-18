/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:21:14 by zelbassa          #+#    #+#             */
/*   Updated: 2023/11/07 21:48:13 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	i = 0;
	ptr_src = (unsigned char *)src;
	ptr_dst = (unsigned char *)dst;
	if (ptr_dst < ptr_src)
	{
		while (i < len)
		{
			ptr_dst[i] = ptr_src[i];
			i ++;
		}
	}
	else if (ptr_dst > ptr_src)
	{
		i = len;
		while (i > 0)
		{
			ptr_dst[i - 1] = ptr_src[i - 1];
			i --;
		}
	}
	return (ptr_dst);
}
/* 
int main() {
	char	src[] = "Hello there friendo";
	char	*dest;
    dest = src + 1;
	int j = 7;

    memmove(src, dest, j);
    printf("Original memmove result: %s\n", dest);

    ft_memmove(src, dest, j);
    printf("KKKKinal memmove ressss: %s\n", dest);

    return 0;
} */