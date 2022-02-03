/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:50:48 by ppeapod           #+#    #+#             */
/*   Updated: 2021/10/17 14:50:50 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_server	g_cn;

void	ft_handler1(int sig, siginfo_t *siginfo, void *context)
{
	int	i;

	context = 0;
	i = 0b10000000;
	if (SIGUSR1 == sig)
		g_cn.c = g_cn.c | i >> g_cn.n;
	g_cn.n++;
	if (g_cn.n == 8)
	{
		if (g_cn.c == '\0')
			write(1, "\n", 1);
		else
			write(1, &g_cn.c, 1);
		g_cn.n = 0;
		g_cn.c = 0b00000000;
	}
	kill(siginfo -> si_pid, SIGUSR1);
}

int	main(void)
{
	char				*pid;
	struct sigaction	act;

	g_cn.c = 0b00000000;
	g_cn.n = 0;
	pid = ft_itoa(getpid());
	write (1, pid, ft_strlen(pid));
	free(pid);
	write (1, "\n", 1);
	act.sa_sigaction = ft_handler1;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
}
