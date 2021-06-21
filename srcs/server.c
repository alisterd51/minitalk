/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:38:35 by anclarma          #+#    #+#             */
/*   Updated: 2021/06/20 21:46:49 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft.h"

static void	ft_buf(char c)
{
	static int	i = 0;
	static char	buf[1024] = {0};

	if (c)
		buf[i++] = c;
	else
	{
		write(1, buf, i);
		i = 0;
	}
	if (i == 1024)
	{
		write(1, buf, i);
		i = 0;
	}
}

static int	ft_exp(int nb, int exp)
{
	int	ret;

	ret = 1;
	while (exp--)
		ret *= nb;
	return (ret);
}

static void	receive_bit(int sig)
{
	static char	c = '\0';
	static int	i = 0;

	if (i < 7)
	{
		if (sig == SIGUSR2)
			c += ft_exp(2, i);
		i++;
	}
	else
	{
		if (sig == SIGUSR2)
			c += 0x80;
		ft_buf(c);
		c = '\0';
		i = 0;
	}
}

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	write(1, pid, ft_strlen(pid));
	free(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, receive_bit);
	signal(SIGUSR2, receive_bit);
	while (1)
		pause();
	return (0);
}
