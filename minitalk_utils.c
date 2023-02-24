/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:32:45 by aderviso          #+#    #+#             */
/*   Updated: 2023/02/24 12:32:46 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_itoa(int num)
{
	char	rt;

	if (num >= 10)
		ft_itoa(num / 10);
	rt = num % 10 + '0';
	write(1, &rt, 1);
}

int	ft_atoi(char *str)
{
	int	num;

	num = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			num = num * 10 + *str - '0';
		else
			exit(1);
		str++;
	}
	return (num);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		*(unsigned char *)(b + i++) = (unsigned char)c;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
