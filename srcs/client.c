/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:38:35 by anclarma          #+#    #+#             */
/*   Updated: 2021/06/20 21:50:06 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft.h"

#include <stdio.h>

static void	send_bit(int pid, int bit)
{
	if (bit)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	usleep(50);
}

static void	send_char(int pid, char c)
{
	send_bit(pid, c & 0x1);
	send_bit(pid, c & 0x2);
	send_bit(pid, c & 0x4);
	send_bit(pid, c & 0x8);
	send_bit(pid, c & 0x10);
	send_bit(pid, c & 0x20);
	send_bit(pid, c & 0x40);
	send_bit(pid, c & 0x80);
}

int	main(int ac, char **av)
{
	char	c;
	int		pid;
	int		i;

	if (ac > 1)
		pid = ft_atoi(av[1]);
	if (ac == 3)
	{
		i = 0;
		while (av[2][i])
		{
			c = av[2][i];
			send_char(pid, c);
			i++;
		}
		send_char(pid, 0);
	}
	else
		return (1);
	return (0);
}
