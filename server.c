/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:52:48 by lzaengel          #+#    #+#             */
/*   Updated: 2024/01/19 17:55:29 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_exit(void)
{
	exit(0);
}
void	ft_test(int signo, siginfo_t *info, void *context)
{
	static int	c = 0;
	static int	b = 1;
	static int	sender;

	if (info->si_pid != 0)
		sender = info->si_pid;
	(void)context ;
	if (signo == SIGUSR1)
		c = c + b;
	b = b * 2;

	if (b == 256)
	{
		write(1, &c, 1);
		b = 1;
		c = 0;
	}
	usleep(100);
	if (kill(sender, SIGUSR1) == -1)
		ft_exit();

}

int	main(void)
{
	int					pid;
	struct sigaction	signal;

	signal.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	signal.sa_sigaction = ft_test;
	pid = getpid();
	ft_putnbr(pid);
	if (sigaction(SIGUSR1, &signal, NULL) == -1
		|| sigaction(SIGUSR2, &signal, NULL) == -1)
	{
		write(1, "Error SIG\n", 11);
		return (1);
	}
	while (1)
		pause();
	return (0);
}
