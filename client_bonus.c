/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:32:01 by aderviso          #+#    #+#             */
/*   Updated: 2023/02/24 12:32:09 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_len;

void	send(int pid, int chr)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (chr >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit--;
	}
}

void	message_sent(int signal)
{
	static int	i = 1;

	(void)signal;
	if (i == g_len)
	{
		write(1, "Message Sent!\n", 14);
		exit(1);
	}
	i++;
}

int	main(int argc, char **argv)
{
	unsigned char	*str;
	int				pid;

	if (argc == 3)
	{
		signal(SIGUSR1, message_sent);
		pid = ft_atoi(argv[1]);
		str = (unsigned char *)argv[2];
		g_len = ft_strlen(argv[2]);
		while (*str)
			send(pid, *str++);
	}
	else
		exit(1);
	return (0);
}
