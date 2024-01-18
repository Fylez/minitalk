/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:52:48 by lzaengel          #+#    #+#             */
/*   Updated: 2024/01/18 15:24:25 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_test(int signo, siginfo_t *info, void *context)
{
	static int	c = 0;
	static int	b = 1;

	(void)info;
	(void)context ;
	if (signo == SIGUSR1)
		c = c + b;
	b = b * 2;
	if (b == 256)
	{
		write(1, &c, 1);
		kill(info->si_pid, SIGUSR1);
		b = 1;
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	signal;

	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = ft_test;
	pid = getpid();
	ft_putnbr(pid);
	if (sigaction(SIGUSR1, &signal, NULL) == -1
		|| sigaction(SIGUSR2, &signal, NULL) == -1)
	{
		write(1, "Error SIG\n", 11);
		exit (1);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
