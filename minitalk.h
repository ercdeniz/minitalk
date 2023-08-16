/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:56:58 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/08/16 13:54:28 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>

int		ft_atoi(const char *str);
char	*ft_itoa(int nb);
void	ft_putstr(char *str, int mod);
void	send_bit(int pid, char c);
void	handler(int signum);

#endif
