/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 00:14:58 by relamine          #+#    #+#             */
/*   Updated: 2024/06/24 15:05:02 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static void	signal_handler(int signal, siginfo_t *info, void *others)
{
	static char		byte;
	static int		count;
	static pid_t	si_pid;

	(void)others;
	if (si_pid != info->si_pid)
	{
		si_pid = info->si_pid;
		count = 0;
		byte = 0;
	}
	if (signal == SIGUSR1)
		byte = 128 >> count | byte;
	count++;
	if (count == 8)
	{
		write (1, &byte, 1);
		count = 0;
		byte = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;
	pid_t				pid;

	pid = getpid();
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = signal_handler;
	(void)argv;
	if (argc != 1)
		exit(1);
	write(1, "The process ID is ", 18);
	ft_putnbr(pid);
	write(1, "\n", 1);
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		exit(1);
	while (1)
		pause();
}
