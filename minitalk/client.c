/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:51:00 by ppeapod           #+#    #+#             */
/*   Updated: 2021/10/17 14:51:01 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig)
{
	sig = 0;
	usleep(100);
}

int	ft_error(int n)
{
	n = 0;
	write (2, "error\n", 6);
	exit (1);
}

int	main(int argc, char **argv)
{
	int		g_j;
	int		pid;
	int		len;

	signal(SIGUSR1, ft_handler);
	if (argc != 3)
		ft_error(argc);
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) != 0)
		ft_error(pid);
	len = ft_strlen(argv[2]) + 1;
	while (len--)
	{
		g_j = 0b10000000;
		while (g_j > 0)
		{
			if (g_j & *argv[2])
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			g_j /= 2;
			usleep(2000);
		}
		argv[2]++;
	}
}
