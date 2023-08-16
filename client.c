/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:56:39 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/08/16 12:56:39 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	res;

	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str >= '0' && *str <= '9' && *str)
		res = ((*str++ - 48) + (res * 10));
	return (res);
}

void	send_bit(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c << i) & 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
			send_bit(pid, av[2][i++]);
		send_bit(pid, '\0');
	}
	else
		ft_putstr("FORMAT Error!\nSend as:\n==> ./client PID MESSAGE <==", 1);
	return (0);
}
