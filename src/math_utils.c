/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:34 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/26 11:54:35 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static double	process_integer_part(char *str, int *i, int *sign)
{
	double	result;

	result = 0;
	if (ft_atoi(str) > 1 || ft_atoi(str) < -1)
		exit_handler();
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
	while (str[*i] == '0')
		(*i)++;
	if (str[*i] != '0' && ft_isdigit(str[*i]))
		result += (str[*i] - '0');
	while (str[*i] != '.')
		(*i)++;
	(*i)++;
	return (result);
}

static double	process_fractional_part(char *str, int *i)
{
	double	result;
	int		k;

	result = 0;
	k = 1;
	while (str[*i] && ft_isdigit(str[*i]))
	{
		result += (str[*i] - '0') * recursive_num(k);
		(*i)++;
		k++;
	}
	return (result);
}

double	atoi_double(char *str)
{
	int		i;
	int		sign;
	double	result;

	i = 0;
	sign = 1;
	result = process_integer_part(str, &i, &sign);
	result += process_fractional_part(str, &i);
	return (result * sign);
}
