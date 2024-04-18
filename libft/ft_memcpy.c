/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:21:11 by zelbassa          #+#    #+#             */
/*   Updated: 2023/11/08 01:08:46 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	i = 0;
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		i ++;
	}
	return (ptr_dst);
}
/* 
int main()
{
	char src[] = "";
	char dst[] = "";
	char dst_1[] = "";

	printf("Before memcpy dest = %s\n", dst);
	ft_memcpy(dst, src, 3);
	// memcpy(dst_1, src, 3);
	printf("After memcpy dest = %s\n", dst);
	return 0;
} */