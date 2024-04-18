/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:21:48 by zelbassa          #+#    #+#             */
/*   Updated: 2023/11/10 15:43:32 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst,
		const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dstsize == 0)
		return (strlen(src));
	while (dst[i] && i < dstsize)
		i ++;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i ++;
		j ++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[j])
	{
		i ++;
		j ++;
	}
	return (i);
}
/* 
void test_case(char *dst, const char *src, size_t dstsize)
{
    char ft_dst[20];
    char orig_dst[20];
    size_t ft_result, orig_result;

    strcpy(ft_dst, dst);
    strcpy(orig_dst, dst);

    ft_result = ft_strlcat(ft_dst, src, dstsize);
    orig_result = strlcat(orig_dst, src, dstsize);

    printf("ft_strlcat: result = %zu, dst = %s\n", ft_result, ft_dst);
    printf("strlcat: result = %zu, dst = %s\n", orig_result, orig_dst);
}

int main(void)
{
    printf("%s\n", "Test case 1: dstsize is larger than the length of dst");
    test_case("Hello", " World!", 20);
	printf("\n");
    printf("%s\n", "Test case 2: dstsize is smaller than the length of dst");
    test_case("Hello", " World!", 5);
	printf("\n");
    printf("%s\n", "Test case 3: dstsize is equal to the length of dst");
    test_case("Hello", " World!", 0);
	printf("\n");
    printf("%s\n", "Test case 4: src is an empty string");
    test_case("Hello", "", 20);
	printf("\n");
    printf("%s\n", "Test case 5: dst is an empty string");
    test_case("", " World!", 20);

    return (0);
} */