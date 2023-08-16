/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:57:19 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/08/16 13:57:17 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

char	*ft_itoa(int nb)
{
	char	*str;
	int		digit_len;
	int		n;

	n = nb;
	digit_len = 0;
	while (n != 0)
	{
		n /= 10;
		digit_len++;
	}
	str = (char *)malloc(sizeof(char) * (digit_len + 1));
	if (!str)
		return (NULL);
	str[digit_len] = '\0';
	while (nb > 0)
	{
		str[--digit_len] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}

void	handler(int signum)
{
	static int	i = 0;
	static char	c = 0;

	if (signum == SIGUSR1)
		c = (c << 1) | 1;
	else if (signum == SIGUSR2)
		c = (c << 1) | 0;
	i++;
	if (i == 8)
	{
		if (c != '\0')
			write(1, &c, 1);
		else
			write(1, "\n", 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	ft_putstr("Server Started!\nPID ->", 0);
	ft_putstr(pid, 1);
	free(pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
