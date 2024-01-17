/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:15:48 by lzaengel          #+#    #+#             */
/*   Updated: 2024/01/18 00:15:42 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	nb;

	nb = n;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}

int	ft_isdigit(int character)
{
	if (character < '0' || character > '9')
	{
		return (0);
	}
	return (1);
}

int	ft_atoi( const char *theString )
{
	long int		i;
	long int		result;

	i = 0;
	result = 0;
	while (theString[i])
	{
		if (ft_isdigit(theString[i]))
		{
			result = result * 10 + theString[i] - '0';
			i++;
		}
		else
		{
			write(1, "Invalid PID\n", 13);
			exit(0);
		}
	}
	return (result);
}
