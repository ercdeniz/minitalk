/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:57:11 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/08/16 12:57:11 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str, int mod)
{
	if (*str)
	{
		while (*str)
			write(1, str++, 1);
	}
	else
		write(1, "(null)", 6);
	if (mod == 1)
		write(1, "\n", 1);
}
