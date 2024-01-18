/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:52:42 by lzaengel          #+#    #+#             */
/*   Updated: 2024/01/18 15:20:08 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_strlen;

void	ft_exit(int r)
{
	if (r == 1)
		write(1, "Error SIG\n", 11);
	if (r == 3)
		write(1, "Error Kill\n", 12);
	if (r == 4)
		write(1, "Transmission finished successfully\n", 36);
	if (r == 5)
		write(1, "Wrong number of arguments\n", 27);
	exit(0);
}

void	ft_talk(int pid, char *string)
{
	int	i;
	int	bit;

	i = 0;
	bit = 0;
	while (string[i])
	{
		while (bit < 8)
		{
			if (string[i] & 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_exit(3);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_exit(3);
			}
			usleep(100);
			string[i] = string[i] >> 1;
			bit++;
		}
		bit = (i++, 0);
	}
}

void	ft_awnser(int signo)
{
	static int	i = 0;

	if (signo == SIGUSR1)
		i++;
	if (i == g_strlen)
		ft_exit(4);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	signal;

	if (argc != 3)
		ft_exit(5);
	signal.sa_handler = ft_awnser;
	if (sigaction(SIGUSR1, &signal, NULL) == -1
		|| sigaction(SIGUSR2, &signal, NULL) == -1)
		ft_exit(1);
	g_strlen = ft_strlen(argv[2]);
	pid = ft_atoi(argv[1]);
	ft_talk(pid, argv[2]);
	return (0);
}
