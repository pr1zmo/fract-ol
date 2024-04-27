/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:35:52 by zelbassa          #+#    #+#             */
/*   Updated: 2024/04/26 18:16:51 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
int		ft_strlen(char const *str);
void	ft_putchar_fd(char c, int fd);

#endif
