/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:51:20 by ppeapod           #+#    #+#             */
/*   Updated: 2021/10/17 14:51:22 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include "libft/libft.h"

typedef struct s_server
{
	char	c;
	int		n;
}				t_server;

void	ft_handler1(int sig, siginfo_t *siginfo, void *context);
void	ft_handler(int sig);
int		ft_error(int n);

#endif
