/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 00:14:58 by relamine          #+#    #+#             */
/*   Updated: 2024/05/26 11:27:58 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_bonus.h"
#include <stdio.h>

void signal_handler(int signal,siginfo_t *info, void *others) 
{
	static char byte;
	static int	count;
	static int	index;
	static int	si_pid;
	char 		*chars[5];

	(void)others;
	if (si_pid != info->si_pid)
	{
		si_pid = info->si_pid;
		count = 0;
		byte = 0;
	}
	if (signal == SIGUSR1)
	byte =  128 >> count | byte;
	count++;
	if (count == 8)
	{
		chars[index] = malloc(1);
		chars[index] = byte;
		count = 0;
		byte = 0;
	}
}


int main(int argc, char **argv)
{
	pid_t pid;
	struct sigaction action;

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
	{
		pause();
	}
}
